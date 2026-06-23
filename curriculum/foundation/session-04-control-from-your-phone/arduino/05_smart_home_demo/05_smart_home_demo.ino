// InnoBees STEM Lab - ESP32 Smart Home Demo
// Combines LED control, servo (door), and sensor monitoring
// LED on GPIO 2, Servo on GPIO 13, LDR on GPIO 34
// Wi-Fi AP: InnoBees_Lab / stem1234
// Access: http://192.168.4.1

#include <WiFi.h>
#include <ESP32Servo.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);

// Pin definitions
const int LED_PIN = 2;
const int SERVO_PIN = 13;
const int LDR_PIN = 34;

// State
bool ledState = false;
bool doorOpen = false;
Servo doorServo;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  doorServo.attach(SERVO_PIN);
  doorServo.write(0);  // door closed

  WiFi.softAP(ssid, password);

  Serial.println("=== InnoBees Smart Home Demo ===");
  Serial.print("Connect to: ");
  Serial.println(ssid);
  Serial.print("Open: http://");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

String buildHTML() {
  int lightRaw = analogRead(LDR_PIN);
  String lightStatus = (lightRaw < 1500) ? "Dark" : "Bright";

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<title>Smart Home</title>";
  html += "<style>";
  html += "body{font-family:Arial,sans-serif;text-align:center;padding:15px;";
  html += "background:#1a1a2e;color:white;margin:0;}";
  html += "h1{color:#00d4ff;margin-bottom:5px;}";
  html += ".card{background:#16213e;padding:15px;margin:10px auto;";
  html += "border-radius:10px;max-width:400px;border:1px solid #0f3460;}";
  html += ".btn{padding:12px 25px;font-size:16px;margin:5px;border:none;";
  html += "border-radius:8px;color:white;cursor:pointer;text-decoration:none;";
  html += "display:inline-block;}";
  html += ".green{background:#4CAF50;}.red{background:#f44336;}";
  html += ".blue{background:#2196F3;}.orange{background:#FF9800;}";
  html += ".indicator{display:inline-block;width:15px;height:15px;";
  html += "border-radius:50%;margin-right:8px;}";
  html += "</style></head><body>";

  html += "<h1>Smart Home Control</h1>";
  html += "<p style='color:#888;'>InnoBees STEM Lab</p>";

  // Room Light Control
  html += "<div class='card'>";
  html += "<h3>Room Light</h3>";
  html += "<p><span class='indicator' style='background:";
  html += ledState ? "#4CAF50" : "#555";
  html += ";'></span>" + String(ledState ? "ON" : "OFF") + "</p>";
  html += "<a href='/led/on' class='btn green'>ON</a> ";
  html += "<a href='/led/off' class='btn red'>OFF</a>";
  html += "</div>";

  // Door Control
  html += "<div class='card'>";
  html += "<h3>Front Door</h3>";
  html += "<p><span class='indicator' style='background:";
  html += doorOpen ? "#FF9800" : "#2196F3";
  html += ";'></span>" + String(doorOpen ? "OPEN" : "CLOSED") + "</p>";
  html += "<a href='/door/open' class='btn orange'>Open</a> ";
  html += "<a href='/door/close' class='btn blue'>Close</a>";
  html += "</div>";

  // Light Sensor
  html += "<div class='card'>";
  html += "<h3>Light Sensor</h3>";
  html += "<p>Level: " + String(lightRaw) + " (" + lightStatus + ")</p>";
  html += "<a href='/auto' class='btn blue'>Auto Light Mode</a>";
  html += "</div>";

  html += "<p style='color:#555;font-size:12px;'>Refreshes every 5s</p>";
  html += "</body></html>";
  return html;
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    // LED commands
    if (request.indexOf("/led/on") != -1) {
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Light: ON");
    } else if (request.indexOf("/led/off") != -1) {
      ledState = false;
      digitalWrite(LED_PIN, LOW);
      Serial.println("Light: OFF");
    }
    // Door commands
    else if (request.indexOf("/door/open") != -1) {
      doorOpen = true;
      doorServo.write(90);
      Serial.println("Door: OPEN");
    } else if (request.indexOf("/door/close") != -1) {
      doorOpen = false;
      doorServo.write(0);
      Serial.println("Door: CLOSED");
    }
    // Auto mode: turn on light if dark
    else if (request.indexOf("/auto") != -1) {
      int light = analogRead(LDR_PIN);
      if (light < 1500) {
        ledState = true;
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Auto: Dark detected, light ON");
      } else {
        ledState = false;
        digitalWrite(LED_PIN, LOW);
        Serial.println("Auto: Bright detected, light OFF");
      }
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println(buildHTML());
    client.stop();
  }
}
