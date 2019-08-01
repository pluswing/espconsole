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

#include "toluapp.h"
#include "game_api.h"

#define HOST_NAME "espconsole"
#define API_PORT 80
#define SETTING_BUFFER_SIZE 1500
#define SSID_MAX 3

int tolua_game_api_open(lua_State *tolua_S);

lua_State *L = NULL;
GameApi *api;
AsyncWebServer webServer(API_PORT);

struct ESPConsoleSetting
{
    String ssids[SSID_MAX];
    String passwords[SSID_MAX];
};

ESPConsoleSetting setting;

String ssids[255];
int ssidCount = 0;
String selectedSsid = "";
String password = "";

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

    loadSetting();

    scene = collectSSID;
}

void loop()
{
    scene();
}

void collectSSID()
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; i++)
    {
        ssids[i] = WiFi.SSID(i);
    }
    ssidCount = n;
    scene = findConnectableWifi;
}

int findConnectableWifiIndex()
{
    for (int i = 0; i < SSID_MAX; i++)
    {
        for (int j = 0; j < ssidCount; j++)
        {
            Serial.println(setting.ssids[i] + "==" + ssids[j]);
            if (setting.ssids[i] != "" && setting.ssids[i] == ssids[j])
            {
                Serial.println("found!");
                return i;
            }
        }
    }
    return -1;
}

void findConnectableWifi()
{
    if (findConnectableWifiIndex() != -1)
    {
        scene = connectWiFi;
    }
    else
    {
        scene = selectSSID;
    }
}

void selectSSID()
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
        if (cursor >= ssidCount)
        {
            cursor = ssidCount - 1;
        }
    }
    else if (api->btnp(BTN_A))
    {
        selectedSsid = ssids[cursor];
        password = "";
        scene = inputPassword;
        return;
    }
    else if (api->btnp(BTN_B))
    {
        scene = listFiles;
        return;
    }

    api->cls(COLOR_BLACK);
    for (int i = 0; i < ssidCount; i++)
    {
        api->text(10, i * 10, ssids[i].c_str(), COLOR_WHITE);
    }
    api->text(0, cursor * 10, ">", COLOR_GREEN);

    api->Draw();
}

char input = 'A';
bool ok = false;
int scrollTimer = 0;
void inputPassword()
{
    api->Update();

    if (api->btn(BTN_UP))
    {
        if (scrollTimer == 0)
        {
            scrollTimer = 10;
            input -= 1;
        }
        scrollTimer -= 1;
    }
    else if (api->btn(BTN_DOWN))
    {
        if (scrollTimer == 0)
        {
            scrollTimer = 10;
            input += 1;
        }
        scrollTimer -= 1;
    }
    else if (api->btnr(BTN_UP | BTN_DOWN))
    {
        scrollTimer = 0;
    }
    else if (api->btnp(BTN_LEFT))
    {
        if (ok)
        {
            ok = false;
        }
        else
        {
            char diff = 'a' - 'A';
            if ('A' <= input && input <= 'Z')
            {
                input += diff;
            }
            else if ('a' <= input && input <= 'z')
            {
                input -= diff;
            }
            else
            {
                input = 'A';
            }
        }
    }
    else if (api->btnp(BTN_RIGHT))
    {
        ok = true;
    }
    else if (api->btnp(BTN_B))
    {
        if (!ok && password.length() != 0)
        {
            input = password.charAt(password.length() - 1);
            password = password.substring(0, password.length() - 1);
        }
    }
    else if (api->btnp(BTN_A))
    {
        if (ok)
        {
            // 確定
            for (int i = 0; i < SSID_MAX; i++)
            {
                if (setting.ssids[i] == "")
                {
                    setting.ssids[i] = selectedSsid;
                    setting.passwords[i] = password;
                }
                else
                {
                    continue;
                }
                saveSetting();
                scene = findConnectableWifi;
                return;
            }
        }
        else
        {
            password += input;
        }
    }

    api->cls(COLOR_BLACK);
    api->text(0, 0, ("SSID:" + selectedSsid).c_str(), COLOR_WHITE);
    api->text(0, 10, "INPUT PASSWORD", COLOR_WHITE);

    api->text(10, 30, password.c_str(), COLOR_WHITE);
    if (!ok)
    {
        api->text(10 + password.length() * 6, 30, String(input).c_str(), COLOR_RED);
    }

    api->text(100, 50, "[OK]", ok ? COLOR_RED : COLOR_WHITE);

    api->Draw();
}

void setupSoftAP()
{
    // WiFiに接続せず、ESP32自体がアクセスポイントになるパターン
    // WiFi.softAP(ssid, password);
    setupMDNS();
    setupWebServer();
    scene = listFiles;
}

void loadSetting()
{
    DynamicJsonDocument json(SETTING_BUFFER_SIZE);
    File f = SPIFFS.open("/.setting.json", "r");
    if (!f)
    {
        return;
    }
    char content[SETTING_BUFFER_SIZE];
    f.readBytes(content, SETTING_BUFFER_SIZE);
    f.close();
    deserializeJson(json, content);

    JsonArray ssids = json["ssids"];
    JsonArray passwords = json["passwords"];
    for (int i = 0; i < SSID_MAX; i++)
    {
        setting.ssids[i] = "";
        setting.passwords[i] = "";
        Serial.println("size" + String(ssids.size()));
        if (ssids.size() > i)
        {
            const char *ssid = ssids[i];
            const char *password = passwords[i];
            setting.ssids[i] = ssid;
            setting.passwords[i] = password;
        }
    }
}

void saveSetting()
{
    DynamicJsonDocument json(SETTING_BUFFER_SIZE);
    JsonArray ssids = json.createNestedArray("ssids");
    JsonArray passwords = json.createNestedArray("passwords");
    for (int i = 0; i < SSID_MAX; i++)
    {
        if (setting.ssids[i] == "")
        {
            continue;
        }
        ssids.add(setting.ssids[i]);
        passwords.add(setting.passwords[i]);
    }
    File f = SPIFFS.open("/.setting.json", "w");
    String content;
    serializeJson(json, content);
    f.print(content);
    f.close();
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
        if (file.name()[0] == '/' && file.name()[1] == '.')
        {
            // /.から始まるファイルは無視。
            continue;
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
    else if (api->btnp(BTN_RIGHT))
    {
        scene = wifiSetting;
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

int wifiCursor = 0;
void wifiSetting()
{
    api->Update();

    if (api->btnp(BTN_LEFT))
    {
        scene = selectFile;
        return;
    }

    if (api->btnp(BTN_UP))
    {
        wifiCursor -= 1;
        if (wifiCursor < 0)
        {
            wifiCursor = 0;
        }
    }
    if (api->btnp(BTN_DOWN))
    {
        wifiCursor += 1;
        if (wifiCursor >= SSID_MAX)
        {
            wifiCursor = SSID_MAX - 1;
        }
    }
    if (api->btnp(BTN_A))
    {
        if (setting.ssids[wifiCursor] != "")
        {
            selectedSsid = setting.ssids[wifiCursor];
            scene = inputPassword;
            return;
        }
    }
    if (api->btnp(BTN_B))
    {
        if (setting.ssids[wifiCursor] != "")
        {
            selectedSsid = setting.ssids[wifiCursor];
            scene = deleteSsid;
            return;
        }
    }

    api->cls(COLOR_BLACK);
    api->text(0, 0, "WIFI SETTING", COLOR_WHITE);
    for (int i = 0; i < SSID_MAX; i++)
    {
        api->text(10, 10 + 10 * i, (String(i + 1) + ": " + (setting.ssids[i] == "" ? String("NO DATA") : setting.ssids[i])).c_str(), COLOR_WHITE);
    }

    api->text(0, 10 + 10 * wifiCursor, ">", COLOR_GREEN);
    api->Draw();
}

void deleteSsid()
{
    api->Update();

    if (api->btnp(BTN_A))
    {
        for (int i = 0; i < SSID_MAX; i++)
        {
            if (setting.ssids[i] == selectedSsid)
            {
                setting.ssids[i] = "";
                setting.passwords[i] = "";
                saveSetting();
                loadSetting();
                scene = wifiSetting;
            }
        }
    }
    if (api->btnp(BTN_B))
    {
        scene = wifiSetting;
        return;
    }

    api->cls(COLOR_BLACK);
    api->text(0, 0, "DELETE OK?", COLOR_WHITE);
    api->text(10, 10, ("SSID: " + selectedSsid).c_str(), COLOR_WHITE);

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

    if (luaL_dostring(L, script.c_str()) != 0)
    {
        api->Error(lua_tostring(L, -1));
        scene = nop;
    }
    else
    {
        scene = gameMain;
    }
}

int frameCount = 0;
int frameCountStartTime = 0;
int extendTime = 0;

void gameMain()
{
    int frameMillis = 1000 / api->getFPS();

    int start = millis();
    try
    {
        runOneFrame();
    }
    catch (char *s)
    {
        return;
    }
    frameCount++;
    int finish = millis();

    if (finish - frameCountStartTime > 1000)
    {
        api->actualFps = frameCount;
        frameCount = 0;
        frameCountStartTime = finish;
    }

    if (frameMillis + extendTime > finish - start)
    {
        // 許容時間ないに収まっていればdelayするだけ。 調整のため+1msしとく。
        delay((frameMillis + extendTime) - (finish - start) + 1);
        extendTime = 0;
    }
    else
    {
        // そうじゃなければ、ドロップフレーム分updateを呼び出す
        int drop = ceil((float)(finish - start) / frameMillis) - 1;
        for (int i = 0; i < drop; i++)
        {
            try
            {
                runUpdate();
            }
            catch (char *e)
            {
                return;
            }
        }
        // ドロップフレームして巻いた分の時間を持っておく
        extendTime = (drop + 1) * frameMillis - (finish - start);
    }
}

void nop()
{
    api->Draw();
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
        api->Error(lua_tostring(L, -1));
        scene = nop;
        throw "";
    }
}

void runDraw()
{
    lua_getglobal(L, "draw");
    if (lua_pcall(L, 0, 0, 0) != 0)
    {
        api->Error(lua_tostring(L, -1));
        scene = nop;
        throw "";
    }
    api->Draw();
}

void connectWiFi()
{
    int i = findConnectableWifiIndex();
    if (i == -1)
    {
        scene = listFiles;
        return;
    }

    String ssid = setting.ssids[i];
    String password = setting.passwords[i];

    WiFi.begin(ssid.c_str(), password.c_str());
    int n = 0;
    api->cls(COLOR_BLACK);
    api->text(0, 0, "CONNECTING...", COLOR_WHITE);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        api->text(n * 6, 10, ".", COLOR_WHITE);
        api->Draw();
        n += 1;
        if (n > 10)
        {
            scene = failedConnectWiFi;
        }
    }
    setupMDNS();
    setupWebServer();

    scene = listFiles;
}

void failedConnectWiFi()
{
    api->cls(COLOR_BLACK);
    api->text(0, 0, "CONNECT FAILED.", COLOR_WHITE);
    api->Draw();
    if (api->btnp(BTN_A | BTN_B))
    {
        scene = selectSSID;
    }
}

void setupMDNS()
{
    if (!MDNS.begin(HOST_NAME))
    {
        Serial.println("Error setup MDNS.");
    }
    MDNS.addService("http", "tcp", API_PORT);
}

void setupWebServer()
{
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
