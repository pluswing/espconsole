#include "game_api.h"

void serialPrint(const char *message);

GameApi::GameApi()
{

    display = new Adafruit_ST7735(DISPLAY_CS, DISPLAY_DC, DISPLAY_RST);
    adc = new Adafruit_MCP3008();

    display->initR(INITR_GREENTAB);
    display->setRotation(135);
    display->setFont();
    display->setTextColor(COLOR_WHITE);
    display->setTextSize(1);

    backScreen = new GFXcanvas16(display->width(), display->height());
    cls(COLOR_BLACK);
    Draw();

    pinMode(BTN_A_PIN, INPUT_PULLUP);
    pinMode(BTN_B_PIN, INPUT_PULLUP);

    adc->begin();
    Calibrate();
}

GameApi::~GameApi()
{
}

void GameApi::cls(int color)
{
    backScreen->fillScreen(color);
}

void GameApi::pix(int x, int y, int color)
{
    backScreen->drawPixel(x, y, color);
}

void GameApi::line(int x1, int y1, int x2, int y2, int color)
{
    backScreen->drawLine(x1, y1, x2, y2, color);
}

void GameApi::rect(int x, int y, int w, int h, int color)
{
    backScreen->fillRect(x, y, w, h, color);
}

void GameApi::rectb(int x, int y, int w, int h, int color)
{
    backScreen->drawRect(x, y, w, h, color);
}

void GameApi::circ(int x, int y, int r, int color)
{
    backScreen->drawCircle(x, y, r, color);
}
void GameApi::circb(int x, int y, int r, int color)
{
    backScreen->fillCircle(x, y, r, color);
}
void GameApi::text(int x, int y, const char *s, int color)
{
    backScreen->setCursor(x, y);
    backScreen->setTextColor(color);
    backScreen->print(s);
}

void GameApi::Draw()
{
    display->drawRGBBitmap(0, 0, backScreen->getBuffer(), display->width(), display->height());
}

// Input
unsigned int GameApi::btn(int button)
{
    return buttonState & button;
}
unsigned int GameApi::btnp(int button)
{
    return (buttonState & button) & ((~lastButtonState) & button);
}

unsigned int GameApi::btnr(int button)
{
    return (lastButtonState & button) & ((~buttonState) & button);
}

int GameApi::analogY()
{
    return stick.y;
}
int GameApi::analogX()
{
    return stick.x;
}

void GameApi::print(const char *message)
{
    serialPrint(message);
}

void GameApi::Calibrate()
{
    center = ReadRawAnalogInput();
}

void GameApi::Update()
{
    lastButtonState = buttonState;

    buttonState = 0;
    buttonState += digitalRead(BTN_A_PIN) ? 0 : BTN_A;
    buttonState += digitalRead(BTN_B_PIN) ? 0 : BTN_B;
    stick = ReadAnalog();
    if (stick.y < 0)
    {
        buttonState += BTN_UP;
    }
    else if (stick.y > 0)
    {
        buttonState += BTN_DOWN;
    }
    if (stick.x > 0)
    {
        buttonState += BTN_RIGHT;
    }
    else if (stick.x < 0)
    {
        buttonState += BTN_LEFT;
    }
}

AnalogInput GameApi::ReadRawAnalogInput()
{
    AnalogInput r;
    r.down = adc->readADC(0);
    r.up = adc->readADC(1);
    r.left = adc->readADC(2);
    r.right = adc->readADC(3);
    return r;
}

AnalogInput GameApi::ReadAnalogInputCalibrated()
{
    AnalogInput r = ReadRawAnalogInput();
    r.up -= center.up;
    r.down -= center.down;
    r.left -= center.left;
    r.right -= center.right;
    return r;
}

Analog GameApi::ReadAnalog()
{
    AnalogInput r = ReadAnalogInputCalibrated();
    Analog a;

    if (r.down > ANALOG_THRETHOLD)
    {
        a.y = r.down * ANALOG_RANGE / ANALOG_MAX;
    }
    else if (r.up > ANALOG_THRETHOLD)
    {
        a.y = -r.up * ANALOG_RANGE / ANALOG_MAX;
    }
    else
    {
        a.y = 0;
    }

    if (r.left > ANALOG_THRETHOLD)
    {
        a.x = -r.left * ANALOG_RANGE / ANALOG_MAX;
    }
    else if (r.right > ANALOG_THRETHOLD)
    {
        a.x = r.right * ANALOG_RANGE / ANALOG_MAX;
    }
    else
    {
        a.x = 0;
    }

    return a;
}

GameApi *g_gameApi;

void InitGameApi()
{
    if (g_gameApi == NULL)
    {
        g_gameApi = new GameApi();
    }
}

GameApi *GetApi()
{
    return g_gameApi;
}