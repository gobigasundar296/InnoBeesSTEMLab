// InnoBees STEM Lab - ESP32 Sensor Dashboard
// LDR on GPIO 34 (ADC1 - works with Wi-Fi)
// Voltage divider: 3.3V -> LDR -> GPIO34 -> 10k -> GND
// Creates Wi-Fi AP and serves a live dashboard
// Auto-refreshes every 3 seconds

#include <WiFi.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);
const int LDR_PIN = 34;

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);

  Serial.println("=== InnoBees Sensor Dashboard ===");
  Serial.print("Connect to Wi-Fi: ");
  Serial.println(ssid);
  Serial.print("Open browser: http://");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

String getBarWidth(int value, int maxVal) {
  int percent = map(value, 0, maxVal, 0, 100);
  return String(percent);
}

String buildHTML() {
  int lightRaw = analogRead(LDR_PIN);
  // ESP32 ADC is 12-bit (0-4095)
  int lightPercent = map(lightRaw, 0, 4095, 0, 100);
  String lightStatus;
  String barColor;

  if (lightRaw < 1000) {
    lightStatus = "DARK";
    barColor = "#3f51b5";
  } else if (lightRaw < 2500) {
    lightStatus = "MODERATE";
    barColor = "#ff9800";
  } else {
    lightStatus = "BRIGHT";
    barColor = "#ffc107";
  }

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<meta http-equiv='refresh' content='3'>";
  html += "<title>Sensor Dashboard</title>";
  html += "<style>";
  html += "body{font-family:Arial,sans-serif;text-align:center;padding:20px;";
  html += "background:#1a1a2e;color:white;margin:0;}";
  html += "h1{color:#00d4ff;}";
  html += ".card{background:#16213e;padding:20px;margin:15px auto;";
  html += "border-radius:12px;max-width:400px;border:1px solid #0f3460;}";
  html += ".value{font-size:36px;color:#ffc107;margin:10px 0;}";
  html += ".bar-bg{background:#0f3460;border-radius:8px;height:30px;margin:10px 0;}";
  html += ".bar{height:30px;border-radius:8px;transition:width 0.5s;}";
  html += ".status{font-size:18px;padding:5px 15px;border-radius:5px;";
  html += "display:inline-block;margin:10px;}";
  html += "small{color:#888;}";
  html += "</style></head><body>";
  html += "<h1>InnoBees Sensor Dashboard</h1>";

  // Light sensor card
  html += "<div class='card'>";
  html += "<h2>Light Sensor (LDR)</h2>";
  html += "<div class='value'>" + String(lightRaw) + "</div>";
  html += "<div class='bar-bg'><div class='bar' style='width:" + String(lightPercent);
  html += "%;background:" + barColor + ";'></div></div>";
  html += "<div class='status' style='background:" + barColor + ";'>" + lightStatus + "</div>";
  html += "</div>";

  // System info card
  html += "<div class='card'>";
  html += "<h2>System Info</h2>";
  html += "<p>Uptime: " + String(millis() / 1000) + " seconds</p>";
  html += "<p>Connected clients: " + String(WiFi.softAPgetStationNum()) + "</p>";
  html += "</div>";

  html += "<p><small>Auto-refreshes every 3 seconds</small></p>";
  html += "</body></html>";
  return html;
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println(buildHTML());
    client.stop();
  }

  // Also print to Serial for debugging
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 2000) {
    Serial.print("Light: ");
    Serial.println(analogRead(LDR_PIN));
    lastPrint = millis();
  }
}
