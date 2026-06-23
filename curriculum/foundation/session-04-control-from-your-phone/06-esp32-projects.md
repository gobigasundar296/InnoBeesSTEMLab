# Chapter 6: ESP32 Wireless Projects

## Setting up ESP32 in Arduino IDE

### Step 1: Add ESP32 board URL

1. Open Arduino IDE → File → Preferences.
2. In "Additional Board Manager URLs", add:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Click OK.

### Step 2: Install ESP32 board package

1. Tools → Board → Boards Manager.
2. Search "ESP32".
3. Install "esp32 by Espressif Systems".
4. Wait for download to complete.

### Step 3: Select board and port

1. Tools → Board → ESP32 Arduino → "ESP32 Dev Module".
2. Tools → Port → Select the correct COM port.
3. Upload speed: 921600 (default is fine).

### Step 4: Test with blink

```cpp
const int LED_PIN = 2;  // Built-in LED on most ESP32 boards

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

If the built-in LED blinks, ESP32 is working!

## Project 1: Bluetooth LED control

Complete code for controlling an LED from a phone via Bluetooth.

```cpp
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("InnoBees_LED");
  Serial.println("Bluetooth started. Pair with 'InnoBees_LED'");
  SerialBT.println("Commands: 1=ON, 0=OFF, s=status");
}

void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    switch (cmd) {
      case '1':
        digitalWrite(LED_PIN, HIGH);
        SerialBT.println("LED: ON");
        break;
      case '0':
        digitalWrite(LED_PIN, LOW);
        SerialBT.println("LED: OFF");
        break;
      case 's':
        SerialBT.print("LED is: ");
        SerialBT.println(digitalRead(LED_PIN) ? "ON" : "OFF");
        break;
    }
  }
}
```

## Project 2: Wi-Fi LED web server

Control an LED from any phone browser.

```cpp
#include <WiFi.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);
const int LED_PIN = 2;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

String buildPage() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<style>body{font-family:Arial;text-align:center;padding:20px;background:#1a1a2e;color:white;}";
  page += ".btn{padding:20px 40px;font-size:20px;margin:10px;border:none;border-radius:10px;color:white;}";
  page += ".on{background:#4CAF50;}.off{background:#f44336;}</style></head><body>";
  page += "<h1>InnoBees LED Control</h1>";
  page += "<p>LED Status: <b>" + String(ledState ? "ON" : "OFF") + "</b></p>";
  page += "<a href='/on'><button class='btn on'>Turn ON</button></a> ";
  page += "<a href='/off'><button class='btn off'>Turn OFF</button></a>";
  page += "</body></html>";
  return page;
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/on") != -1) {
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
    } else if (request.indexOf("/off") != -1) {
      ledState = false;
      digitalWrite(LED_PIN, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println(buildPage());
    client.stop();
  }
}
```

## Project 3: Wi-Fi servo control

Control a servo motor angle from the phone browser.

```cpp
#include <WiFi.h>
#include <ESP32Servo.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);
Servo myServo;
const int SERVO_PIN = 13;
int currentAngle = 90;

void setup() {
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);
  myServo.write(currentAngle);

  WiFi.softAP(ssid, password);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

String buildPage() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<style>body{font-family:Arial;text-align:center;padding:20px;background:#1a1a2e;color:white;}";
  page += ".btn{padding:15px 30px;font-size:18px;margin:5px;border:none;border-radius:8px;color:white;background:#2196F3;}</style></head><body>";
  page += "<h1>Servo Control</h1>";
  page += "<p>Current Angle: <b>" + String(currentAngle) + "&deg;</b></p>";
  page += "<a href='/angle?v=0'><button class='btn'>0&deg;</button></a>";
  page += "<a href='/angle?v=45'><button class='btn'>45&deg;</button></a>";
  page += "<a href='/angle?v=90'><button class='btn'>90&deg;</button></a>";
  page += "<a href='/angle?v=135'><button class='btn'>135&deg;</button></a>";
  page += "<a href='/angle?v=180'><button class='btn'>180&deg;</button></a>";
  page += "</body></html>";
  return page;
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/angle?v=") != -1) {
      int startIdx = request.indexOf("v=") + 2;
      int endIdx = request.indexOf(" ", startIdx);
      String angleStr = request.substring(startIdx, endIdx);
      int angle = angleStr.toInt();
      if (angle >= 0 && angle <= 180) {
        currentAngle = angle;
        myServo.write(currentAngle);
      }
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println(buildPage());
    client.stop();
  }
}
```

## Project 4: Sensor dashboard

Display sensor readings on the phone in real-time.

```cpp
#include <WiFi.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);
const int LDR_PIN = 34;  // Use GPIO34 for analog on ESP32

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

String buildPage() {
  int lightLevel = analogRead(LDR_PIN);
  String lightStatus = (lightLevel < 1000) ? "DARK" : "BRIGHT";

  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<meta http-equiv='refresh' content='2'>";  // auto-refresh every 2s
  page += "<style>body{font-family:Arial;text-align:center;padding:20px;background:#1a1a2e;color:white;}";
  page += ".card{background:#16213e;padding:20px;margin:10px;border-radius:10px;}";
  page += "h2{color:#00d4ff;}</style></head><body>";
  page += "<h1>Sensor Dashboard</h1>";
  page += "<div class='card'><h2>Light Sensor</h2>";
  page += "<p>Raw Value: " + String(lightLevel) + "</p>";
  page += "<p>Status: " + lightStatus + "</p></div>";
  page += "<p><small>Auto-refreshes every 2 seconds</small></p>";
  page += "</body></html>";
  return page;
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println(buildPage());
    client.stop();
  }
}
```

## Project 5: Smart home demo

Combines LED, servo (door), and sensor monitoring in one web interface.

This combines all the concepts from Sessions 1-4 into a single smart home
demonstration system.

## ESP32 pin notes

| Function | Recommended pins |
|---|---|
| Digital output (LED, buzzer) | GPIO 2, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23 |
| PWM output | Any output-capable pin |
| Analog input | GPIO 32, 33, 34, 35, 36, 39 (ADC1 only when Wi-Fi active) |
| Servo signal | GPIO 13, 14, 15, 16, 17, 18, 19 |
| Avoid | GPIO 6-11 (flash SPI), GPIO 0, 2 (boot) |

**Note:** When Wi-Fi is active, only ADC1 pins (GPIO 32-39) work for
`analogRead()`. ADC2 pins conflict with Wi-Fi.
