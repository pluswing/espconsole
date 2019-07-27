#define FPS 60

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <string.h>
#include <SPIFFS.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#include "config.h"
#include "toluapp.h"
#include "game_api.h"

int tolua_game_api_open(lua_State *tolua_S);

lua_State *L = NULL;
GameApi *api;
AsyncWebServer webServer(API_PORT);

String files[255];
int fileCount = 0;
int cursor = 0;

typedef void (*Scene)(void);
Scene scene = NULL;

// lua print() function
void serialPrint(const char *message)
{
    Serial.println(message);
}

void setup()
{
    Serial.begin(115200);

    SPIFFS.begin();

    InitGameApi();
    api = GetApi();

    setupNetwork();

    scene = listFiles;
}

String uploadContent;
void handleUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final)
{
    if (!index)
    {
        uploadContent = "";
        Serial.printf("UploadStart: %s\n", filename.c_str());
    }
    char buff[len + 1] = {0};
    memcpy(buff, data, len);
    uploadContent += buff;

    if (final)
    {
        File f = SPIFFS.open(String("/" + filename).c_str(), "w");
        f.print(uploadContent);
        f.close();
        uploadContent = "";
        Serial.printf("UploadEnd: %s, %u B\n", filename.c_str(), index + len);
    }
}

void loop()
{
    scene();
}

void listFiles()
{
    File root = SPIFFS.open("/");
    fileCount = 0;
    while (true)
    {
        File file = root.openNextFile();
        if (!file)
        {
            break;
        }
        files[fileCount] = file.name();
        fileCount++;
    };

    cursor = 0;
    scene = selectFile;
}

void selectFile()
{
    api->Update();
    if (api->btnp(BTN_UP))
    {
        cursor -= 1;
        if (cursor < 0)
        {
            cursor = 0;
        }
    }
    else if (api->btnp(BTN_DOWN))
    {
        cursor += 1;
        if (cursor >= fileCount)
        {
            cursor = fileCount - 1;
        }
    }
    else if (api->btnp(BTN_A))
    {
        scene = loadScript;
        return;
    }

    api->cls(COLOR_BLACK);
    for (int i = 0; i < fileCount; i++)
    {
        api->text(10, i * 10, files[i].c_str(), COLOR_WHITE);
    }
    api->text(0, cursor * 10, ">", COLOR_GREEN);

    api->Draw();
}

void loadScript()
{
    if (L != NULL)
    {
        lua_close(L);
        L = NULL;
    }
    L = luaL_newstate();
    luaL_openlibs(L);
    tolua_game_api_open(L);
    Serial.print("LOAD: ");
    Serial.println(files[cursor].c_str());
    File f = SPIFFS.open(files[cursor].c_str(), "r");
    String script;
    char buf[256];
    while (true)
    {
        int n = f.readBytes(buf, 255);
        if (n == 0)
        {
            break;
        }
        buf[n] = '\0';
        script += buf;
    }
    Serial.println(script.c_str());

    // if (luaL_dostring(L, "local api = GetApi()\nfunction update()\nend\nfunction draw()\n-- api:cls(COLOR_BLACK)\napi:circb(api:analogX() + 80, api:analogY() + 64, 20, COLOR_GREEN)\nend\n") != 0)
    if (luaL_dostring(L, script.c_str()) != 0)
    {
        Serial.println("ERR");
        api->print(lua_tostring(L, -1));
    }
    scene = gameMain;
}

int actualFps = 0;
int frameCount = 0;
int frameCountStartTime = 0;

void gameMain()
{
    int frameMillis = 1000 / FPS;

    int start = millis();
    runOneFrame();
    frameCount++;
    int finish = millis();

    if (finish - frameCountStartTime > 1000)
    {
        actualFps = frameCount;
        frameCount = 0;
        frameCountStartTime = finish;
        Serial.println("FPS: " + String(actualFps));
    }

    if (frameMillis > finish - start)
    {
        // 許容時間ないに収まっていればdelayするだけ。
        delay(frameMillis - (finish - start));
    }
    else
    {
        // そうじゃなければ、ドロップフレーム分updateを呼び出す
        int drop = ceil((float)(finish - start) / frameMillis) - 1;
        for (int i = 0; i < drop; i++)
        {
            runUpdate();
        }
    }
}

void runOneFrame()
{
    runUpdate();
    runDraw();
}

void runUpdate()
{
    api->Update();

    lua_getglobal(L, "update");
    if (lua_pcall(L, 0, 0, 0) != 0)
    {
        api->print(lua_tostring(L, -1));
    }
}

void runDraw()
{
    lua_getglobal(L, "draw");
    if (lua_pcall(L, 0, 0, 0) != 0)
    {
        api->print(lua_tostring(L, -1));
    }

    api->Draw();
}

void setupNetwork()
{
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.print("Wi-Fi Connected! IP address: ");
    Serial.println(WiFi.localIP());
    if (!MDNS.begin(HOST_NAME))
    {
        Serial.println("Error setup MDNS.");
    }
    MDNS.addService("http", "tcp", API_PORT);

    webServer.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", "running");
    });

    webServer.on("/upload", HTTP_POST, [](AsyncWebServerRequest *request) {
        if (!request->hasParam("file", true, true))
        {
            request->send(500);
            return;
        }
        request->send(200);
        scene = listFiles;
    },
                 handleUpload);

    webServer.on("/delete", HTTP_POST, [](AsyncWebServerRequest *request) {
        if (!request->hasParam("file", true))
        {
            request->send(404);
            return;
        }
        AsyncWebParameter *p = request->getParam("file", true);
        Serial.println(String("delete:" + p->value()).c_str());
        if (!SPIFFS.remove(p->value()))
        {
            request->send(404);
            return;
        }
        request->send(200);
        scene = listFiles;
    });

    webServer.on("/list", HTTP_POST, [](AsyncWebServerRequest *request) {
        DynamicJsonDocument doc(1500);
        JsonArray data = doc.createNestedArray("files");
        for (int i = 0; i < fileCount; i++)
        {
            data.add(files[i]);
        }
        String jsonString;
        serializeJson(doc, jsonString);
        request->send(200, "application/json", jsonString);
    });

    webServer.onNotFound([](AsyncWebServerRequest *request) {
        request->send(404);
    });
    webServer.begin();
}
