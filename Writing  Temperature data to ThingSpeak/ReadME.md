# Writing Temperature data to ThingSpeak


## Introduction

Interfacing TMP102 Temperature Sensor to ESP8266 and uploading data to ThingSpeak

## Hardware Components:
- ESP8266
- TMP102

## Development Tools Used:
- Circuit Connections - PROTEUS 8 Professional
- Programming - Arduino IDE 1.8.19

## Hardware Connection:
- Connect VCC of TMP102 to 3V of ESP8266
- Connect GND of TMP102 to G of ESP8266
- Connect SCL of TMP102 to D1 of ESP8266
- Connect SDA of TMP102 to D2 of ESP8266

## Dependencies
- SparkFun TMP102 library:  http://librarymanager/All#SparkFun_TMP102
- ThingSpeak library

## Usage:
- Connect D0 and D1 as shown in the following diagram
<img src=https://github.com/IEEEProjectsBengaluru/ESP8266-Programming/blob/main/Writing%20%20Temperature%20data%20to%20ThingSpeak/results/connections.png>

- Open the code using Arduino IDE
- Go to Tools -> Boards -> ESP8266 Boards -> NodeMCU 1.0
- Go to Tools -> Port -> Select the port
- Click on Upload

## Output
<img src=https://github.com/IEEEProjectsBengaluru/ESP8266-Programming/blob/main/Writing%20%20Temperature%20data%20to%20ThingSpeak/results/ezgif.com-video-to-gif.gif>
