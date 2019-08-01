#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// TOLUA_BEGIN

// private defines
#define BTN_A_PIN 4
#define BTN_B_PIN 0

#define ANALOG_Y_PIN 34
#define ANALOG_X_PIN 35

#define ANALOG_MAX 4096
#define ANALOG_THRETHOLD 1000
#define ANALOG_RANGE 100
#define REVERSE_ANALOG_X true
#define REVERSE_ANALOG_Y false

#define DISPLAY_CS 5
#define DISPLAY_RST 22
#define DISPLAY_DC 21

// Colors
#define COLOR_WHITE 0xFFFF
#define COLOR_BLACK 0x0000
#define COLOR_RED 0x001F
#define COLOR_BLUE 0xF800
#define COLOR_GREEN 0x07E0
#define COLOR_YELLOW 0x07FF
#define COLOR_MAGENTA 0xF81F
#define COLOR_CYAN 0xFFE0

// Buttons
#define BTN_A 1
#define BTN_B 2
#define BTN_UP 4
#define BTN_DOWN 8
#define BTN_LEFT 16
#define BTN_RIGHT 32

// TOLUA_END

struct Analog
{
    int x;
    int y;
};

// TOLUA_BEGIN
class GameApi
{
    // TOLUA_END
public:
    GameApi();
    virtual ~GameApi();

    // TOLUA_BEGIN

    // Enviroments
    int width();
    int height();
    void setFPS(int fps);
    int getFPS();
    void showFPS(int x, int y, int color);

    // Graphics
    void cls(int color);
    void pix(int x, int y, int color);
    void line(int x1, int y1, int x2, int y2, int color);
    void rect(int x, int y, int w, int h, int color);
    void rectb(int x, int y, int w, int h, int color);
    void circ(int x, int y, int r, int color);
    void circb(int x, int y, int r, int color);
    void text(int x, int y, const char *s, int color);
    int color(int r, int g, int b);

    // TOLUA_END
    void bmp(int x, int y, const unsigned char *bmp, int w, int h, int color);
    // TOLUA_BEGIN

    // Input/Output
    bool btn(int button);
    bool btnp(int button);
    bool btnr(int button);
    int analogY();
    int analogX();

    void print(const char *message);
    // TOLUA_END

    void Calibrate();
    void Update();
    void Draw();
    void Error(const char *message);

    int actualFps;

private:
    int fps;
    Adafruit_ST7735 *display;
    GFXcanvas16 *backScreen;

    unsigned int buttonState;
    unsigned int lastButtonState;
    Analog center;
    Analog stick;

    Analog ReadRawAnalogInput();
    Analog ReadAnalogInputCalibrated();
    Analog ReadAnalog();

    // TOLUA_BEGIN
};

// TOLUA_END

void InitGameApi();
// TOLUA_BEGIN
GameApi *GetApi();
// TOLUA_END
