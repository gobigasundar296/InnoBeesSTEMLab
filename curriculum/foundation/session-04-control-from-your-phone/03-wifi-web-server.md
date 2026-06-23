# Chapter 3: Wi-Fi and Web Server Basics

## What is Wi-Fi?

Wi-Fi is a wireless networking technology that connects devices to a local
network and the internet using radio waves.

### Key characteristics

| Property | Value |
|---|---|
| Range | ~30-100 meters (indoor) |
| Frequency | 2.4 GHz / 5 GHz |
| Speed | Up to hundreds of Mbps |
| Devices | Many can connect simultaneously |
| Internet | Can access the internet |

## Wi-Fi vs. Bluetooth

| Feature | Bluetooth | Wi-Fi |
|---|---|---|
| Range | ~10 m | ~30-100 m |
| Devices | Usually 1-to-1 | Many devices |
| Internet access | No | Yes |
| Power consumption | Low | Higher |
| Setup complexity | Simple pairing | Network name + password |
| Best for | Direct phone control | Web-based control, IoT |

## How ESP32 Wi-Fi works

ESP32 can operate in three Wi-Fi modes:

1. **Station (STA):** Connects to an existing Wi-Fi network (like your home
   router or phone hotspot).
2. **Access Point (AP):** Creates its own Wi-Fi network that phones can
   connect to directly.
3. **Both (STA+AP):** Connects to a network AND creates its own.

For classroom use, **Access Point mode** is simplest — no external router
needed!

## ESP32 as a Web Server

A web server is a program that responds to requests from a web browser.
ESP32 can run a tiny web server that:

- Serves an HTML page with buttons.
- Responds when you click a button.
- Controls hardware (LEDs, servos, etc.) based on web requests.

**The magic:** Students control hardware from their phone's web browser!

## Basic Wi-Fi Access Point setup

```cpp
#include <WiFi.h>

const char* ssid = "InnoBees_Lab";
const char* password = "stem1234";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // Create Access Point
  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
  Serial.println("Web server started!");
}
```

## Web page with control buttons

The ESP32 serves an HTML page that looks like a simple app:

```cpp
String getHTML(bool ledState) {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>";
  html += "body{font-family:Arial;text-align:center;padding:20px;}";
  html += ".btn{padding:20px 40px;font-size:20px;margin:10px;border:none;";
  html += "border-radius:10px;color:white;cursor:pointer;}";
  html += ".on{background:#4CAF50;} .off{background:#f44336;}";
  html += "</style></head><body>";
  html += "<h1>InnoBees Smart Control</h1>";
  html += "<p>LED is: " + String(ledState ? "ON" : "OFF") + "</p>";
  html += "<a href='/on'><button class='btn on'>Turn ON</button></a>";
  html += "<a href='/off'><button class='btn off'>Turn OFF</button></a>";
  html += "</body></html>";
  return html;
}
```

## How web control works

```text
1. ESP32 creates Wi-Fi network "InnoBees_Lab"
2. Phone connects to this Wi-Fi
3. Phone opens browser → goes to 192.168.4.1
4. ESP32 sends HTML page with ON/OFF buttons
5. Student clicks "Turn ON"
6. Phone sends request: http://192.168.4.1/on
7. ESP32 receives request, turns on LED
8. ESP32 sends updated page back to phone
```

## Connecting to existing Wi-Fi (Station mode)

```cpp
#include <WiFi.h>

const char* ssid = "YourNetworkName";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
```

In Station mode, both the phone and ESP32 must be on the same Wi-Fi network.
The phone accesses ESP32 using the IP address shown in Serial Monitor.

## HTTP basics for students

HTTP (HyperText Transfer Protocol) is how web browsers talk to web servers.

| Concept | Meaning |
|---|---|
| URL | Address of a page (e.g., `192.168.4.1/on`) |
| GET request | Browser asking for a page |
| Response | Server sending back HTML content |
| Status 200 | "OK, here's your page" |
| Status 404 | "Page not found" |

When you type a URL and press Enter, you're sending a GET request. The server
responds with the page content.

## Security note for classroom

- The password "stem1234" is for classroom use only.
- In real IoT products, use strong passwords and encryption (HTTPS).
- The Access Point is only for the local classroom — it does not connect to
  the internet.
- Students should not store personal passwords in code.
