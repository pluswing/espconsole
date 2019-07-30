# ESP Console
DIY Game Console with ESP32  
紹介動画: https://youtu.be/rkK88xarytI

## これはなに？
Lua言語で簡単にゲームプログラミングができ、
WEB APIで作ったゲームを実機に転送、実行が可能なゲーム機のファームウェアです。

ゲーム機自体も、電子部品をブレッドボード上で接続するだけなので、簡単に作ることができます。

## 必要な電子部品
- ESP32-DevKitC
  - http://akizukidenshi.com/catalog/g/gM-11819/
- ブレッドボード(2つ必要です。)
  - http://akizukidenshi.com/catalog/g/gP-05294/
- ジャンパーワイヤー
  - http://akizukidenshi.com/catalog/g/gC-05159/
- タクトスイッチ
  - http://akizukidenshi.com/catalog/g/gP-02561/
- カラー液晶 ST7735
  - https://amzn.to/2McLzbK
- アナログジョイスティック
  - http://akizukidenshi.com/catalog/g/gK-10263/

### 部品と回路図の解説動画はこちら
https://youtu.be/0KpF7hCuopo

## 回路図
![回路図](./docs/imgs/circuit.png)

## ファームウェア書き込み

1. Arduino IDEのインストール  
こちらよりダウンロードし、インストールします。  
https://www.arduino.cc/en/main/software

2. arduino-esp32 の設定  
こちらの手順にしたがってArduino IDEにarduino-esp32をインストールします。  
https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md

3. このリポジトリをダウンロード  
「Clone or Download」ボタンをクリックし、「Download ZIP」をクリックすると、ダウンロードできます。

4. Dependency Arduino librariesのインストール  
次章に記載のある「Dependency Arduino libraries」のライブラリをインストールします。  
ESPAsyncWebServer, AsyncTCP はリンクから3の手順と同じく、ZIPファイルをダウンロード。  
解凍したファイルをlibrariesフォルダにコピーしてください。  
そのほかは、Arduino IDEのメニューから、[スケッチ]->[ライブラリをインクルード]->[ライブラリを管理...]からライブラリ名で探してインストールしてください。

5. ファームウェア書き込み  
ESP32-DevKitCとPCをUSBケーブルで接続し、  
3でダウンロードしたファイルを解凍し、espconsole.inoをArduino IDEで開きます。  
Arduino IDEのメニューから、[ツール]->[ボード]から「ESP32 Dev Module」を洗濯します。  
[ツール]->[ボード]の下にUpload Speedなどが表示されるので、  
以下に従い設定を変更します。

- Upload Speed: 921600
- CPU Frequency: 240MHz (WiFi/BT)
- Flash Frequency: 80MHz
- Flash Mode: QUI
- Flash Size: 4MB (32Mb)
- Partition Scheme: Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)
- Core Debug Level: なし
- PSRAM: Disabled

  [ツール]->[ボード]->[シリアルポート]から「...USBtoUART」という名前のものを探し選択します。  
これは、ESP32-DevKitCをUSBケーブルで接続してないと表示されないので注意してください。  

  「マイコンボードに書き込む」（アイコンが右矢印）ボタンを押して、ファームウェアを書き込みます。  
  書き込みに成功すれば、液晶にWIFI接続設定画面が表示されます。

## Dependency Arduino libraries
- Adafruit_GFX (1.5.6)
  - https://github.com/adafruit/Adafruit-GFX-Library
- Adafruit_ST7735 (1.3.7)
  - https://github.com/adafruit/Adafruit-ST7735-Library
- ESPAsyncWebServer (commit: b0c6144886f4e1f88684f708d7b2974143d8601c)
  - https://github.com/me-no-dev/ESPAsyncWebServer
- AsyncTCP (commit: 90715ae6b3ee72e9e40cd3dd2f9609217bf3ee02)
  - https://github.com/me-no-dev/AsyncTCP
- ArduinoJson (6.11.1)
  - https://github.com/bblanchon/ArduinoJson

## ゲームAPI
### INPUT
- btn(button)
- btnp(button)
- btnr(button)
- analogX()
- analogY()

### buttons
- BTN_A
- BTN_B
- BNT_UP
- BTN_DOWN
- BTN_LEFT
- BTN_RIGHT

### Graphics
- cls(color)
- pix(x, y, color)
- line(x1, y1, x2, y2, color)
- rect(x, y, w, h, color) -- 矩形（塗りつぶし）
- rectb(x, y, w, h, color) -- 輪郭線
- circ(x, y, r, color)
- circb(x, y, r, color)
- text(x, y, s, color)

### colors
- COLOR_WHITE
- COLOR_BLACK
- COLOR_RED
- COLOR_GREEN
- COLOR_BLUE
- COLOR_MAGENTA
- COLOR_CYAN
- COLOR_YELLOW

色指定は、BGR565です。

## Web API

## upload file
curl -X POST http://espconsole.local/upload -F "file=@input_test.lua"

## delete file
curl -X POST http://espconsole.local/delete -F "file=/test3.lua"

## list files
curl -X POST http://espconsole.local/list
