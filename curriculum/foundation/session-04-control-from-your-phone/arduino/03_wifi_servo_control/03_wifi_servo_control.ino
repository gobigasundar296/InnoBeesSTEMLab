// InnoBees STEM Lab - ESP32 Wi-Fi Servo Control
// Servo signal on GPIO 13
// Creates Wi-Fi AP: InnoBees_Lab / stem1234
// Open browser: http://192.168.4.1
// Click angle buttons to move servo

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

  Serial.println("=== InnoBees Wi-Fi Servo Control ===");
  Serial.print("Connect to Wi-Fi: ");
  Serial.println(ssid);
  Serial.print("Open browser: http://");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

String buildHTML() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<title>Servo Control</title>";
  html += "<style>";
  html += "body{font-family:Arial,sans-serif;text-align:center;padding:20px;";
  html += "background:#1a1a2e;color:white;}";
  html += "h1{color:#00d4ff;}";
  html += ".angle{font-size:48px;color:#ffc107;margin:20px;}";
  html += ".btn{padding:15px 30px;font-size:18px;margin:8px;border:none;";
  html += "border-radius:8px;color:white;background:#2196F3;cursor:pointer;";
  html += "text-decoration:none;display:inline-block;}";
  html += ".btn:active{background:#1565C0;}";
  html += ".current{background:#FF9800;}";
  html += "</style></head><body>";
  html += "<h1>Servo Motor Control</h1>";
  html += "<div class='angle'>" + String(currentAngle) + "&deg;</div>";
  html += "<p>Select an angle:</p>";

  int angles[] = {0, 30, 45, 60, 90, 120, 135, 150, 180};
  for (int i = 0; i < 9; i++) {
    String cls = (angles[i] == currentAngle) ? "btn current" : "btn";
    html += "<a href='/angle?v=" + String(angles[i]) + "' class='" + cls + "'>";
    html += String(angles[i]) + "&deg;</a> ";
  }

  html += "<br><br><p>Applications:</p>";
  html += "<a href='/angle?v=0' class='btn'>Close Gate</a> ";
  html += "<a href='/angle?v=90' class='btn'>Open Gate</a>";
  html += "</body></html>";
  return html;
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/angle?v=") != -1) {
      int startIdx = request.indexOf("v=") + 2;
      int endIdx = request.indexOf(" ", startIdx);
      if (endIdx == -1) endIdx = request.length();
      String angleStr = request.substring(startIdx, endIdx);
      int angle = angleStr.toInt();

      if (angle >= 0 && angle <= 180) {
        currentAngle = angle;
        myServo.write(currentAngle);
        Serial.print("Servo moved to: ");
        Serial.println(currentAngle);
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
