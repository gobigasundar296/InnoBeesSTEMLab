// InnoBees STEM Lab - ESP32 Wi-Fi LED Web Server
// Creates a Wi-Fi Access Point. Connect phone to it.
// Open browser: http://192.168.4.1
// Click buttons to control LED on GPIO 2
//
// Wi-Fi Name: InnoBees_Lab
// Password: stem1234

#include <WiFi.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);
const int LED_PIN = 2;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  // Create Wi-Fi Access Point
  WiFi.softAP(ssid, password);

  Serial.println("=== InnoBees Wi-Fi LED Control ===");
  Serial.print("Wi-Fi Network: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  Serial.print("Open browser to: http://");
  Serial.println(WiFi.softAPIP());

  server.begin();
  Serial.println("Server started!");
}

String buildHTML() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<title>InnoBees LED Control</title>";
  html += "<style>";
  html += "body{font-family:Arial,sans-serif;text-align:center;padding:20px;";
  html += "background:#1a1a2e;color:white;margin:0;}";
  html += "h1{color:#00d4ff;margin-bottom:5px;}";
  html += "h3{color:#aaa;font-weight:normal;margin-top:0;}";
  html += ".status{font-size:24px;margin:20px;padding:15px;";
  html += "border-radius:10px;display:inline-block;}";
  html += ".on-status{background:#1b5e20;border:2px solid #4CAF50;}";
  html += ".off-status{background:#b71c1c;border:2px solid #f44336;}";
  html += ".btn{padding:20px 50px;font-size:22px;margin:15px;border:none;";
  html += "border-radius:12px;color:white;cursor:pointer;text-decoration:none;";
  html += "display:inline-block;transition:transform 0.1s;}";
  html += ".btn:active{transform:scale(0.95);}";
  html += ".on{background:#4CAF50;}.off{background:#f44336;}";
  html += "</style></head><body>";
  html += "<h1>InnoBees STEM Lab</h1>";
  html += "<h3>Wi-Fi LED Control</h3>";

  if (ledState) {
    html += "<div class='status on-status'>LED is ON</div>";
  } else {
    html += "<div class='status off-status'>LED is OFF</div>";
  }

  html += "<br><br>";
  html += "<a href='/on' class='btn on'>Turn ON</a>";
  html += "<a href='/off' class='btn off'>Turn OFF</a>";
  html += "</body></html>";
  return html;
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    // Process commands
    if (request.indexOf("/on") != -1) {
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Web: LED ON");
    } else if (request.indexOf("/off") != -1) {
      ledState = false;
      digitalWrite(LED_PIN, LOW);
      Serial.println("Web: LED OFF");
    }

    // Send response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println(buildHTML());
    client.stop();
  }
}
