# ESP Console

Game Console with ESP32
Game software written by Lua 5.1
over the air upload.

# Dependeny Arduino libraries
- Adafruit_GFX
- Adafruit_ST7735
- Adafruit_MCP3008
- ESPAsyncWebServer
- AsyncTCP
- ArduinoJson

# API

## upload file
curl -X POST http://espconsole.local/upload -F "file=@input_test.lua"

## delete file
curl -X POST http://espconsole.local/delete -F "file=/test3.lua"

## list files
curl -X POST http://espconsole.local/list

