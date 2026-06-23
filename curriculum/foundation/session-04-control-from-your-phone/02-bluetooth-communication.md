# Chapter 2: Bluetooth Communication

## What is Bluetooth?

Bluetooth is a wireless technology for exchanging data over **short distances**
using radio waves in the 2.4 GHz band.

### Key characteristics

| Property | Value |
|---|---|
| Range | ~10 meters (typical) |
| Frequency | 2.4 GHz |
| Speed | 1-3 Mbps (Classic) |
| Power | Low |
| Pairing | Device-to-device |

## How Bluetooth works (simplified)

1. **Advertising:** The ESP32 broadcasts its name ("InnoBees LED").
2. **Discovery:** Your phone scans and finds the device.
3. **Pairing:** Phone and ESP32 agree to connect.
4. **Communication:** Data flows both ways — phone sends commands, ESP32
   sends responses.

## Bluetooth Classic vs. BLE

| Feature | Bluetooth Classic | BLE (Low Energy) |
|---|---|---|
| Best for | Continuous data stream | Short bursts of data |
| Power usage | Higher | Very low |
| Range | ~10 m | ~10-30 m |
| Example use | Audio, serial data | Fitness bands, beacons |
| ESP32 support | Yes | Yes |

For our projects, we use **Bluetooth Classic** with Serial communication
because it's simpler and works well with free phone apps.

## ESP32 Bluetooth Serial

ESP32 can act as a Bluetooth Serial device. From the phone, it appears as
a wireless serial port — just like the USB Serial Monitor, but without wires.

### Required library

The `BluetoothSerial` library is included with the ESP32 board package.
No additional installation needed.

### Basic setup

```cpp
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("InnoBees_LED");  // Bluetooth device name
  Serial.println("Bluetooth started! Pair with 'InnoBees_LED'");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(command);
  }
}
```

## Phone app setup

### For Android (recommended for classroom)

1. Install **"Serial Bluetooth Terminal"** from Play Store (free).
2. Enable Bluetooth on the phone.
3. Pair with "InnoBees_LED" in phone Bluetooth settings.
4. Open the app and connect to the paired device.
5. Type commands and send.

### For iOS

iOS does not support Bluetooth Classic Serial easily. Use:
- **BLE-based approach** with apps like "LightBlue" or
- **Wi-Fi web server** approach (covered in Chapter 3).

## Controlling an LED via Bluetooth

```cpp
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int LED_PIN = 2;  // Built-in LED on most ESP32 boards

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("InnoBees_LED");
  Serial.println("Ready! Send '1' for ON, '0' for OFF");
  SerialBT.println("Send '1' for ON, '0' for OFF");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    if (command == '1') {
      digitalWrite(LED_PIN, HIGH);
      SerialBT.println("LED ON");
      Serial.println("LED ON");
    } else if (command == '0') {
      digitalWrite(LED_PIN, LOW);
      SerialBT.println("LED OFF");
      Serial.println("LED OFF");
    }
  }
}
```

## HC-05 Bluetooth Module (for Arduino Uno)

If using Arduino Uno instead of ESP32, the HC-05 external module adds
Bluetooth capability.

### HC-05 connections

| HC-05 pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| TXD | Arduino D10 (SoftwareSerial RX) |
| RXD | Arduino D11 through voltage divider (SoftwareSerial TX) |

**Important:** HC-05 RXD is 3.3V logic. Use a voltage divider (1k + 2k)
to step down the Arduino's 5V TX signal.

### Arduino with HC-05

```cpp
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);  // RX, TX
const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("Bluetooth ready");
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    if (command == '1') {
      digitalWrite(LED_PIN, HIGH);
      BTSerial.println("LED ON");
    } else if (command == '0') {
      digitalWrite(LED_PIN, LOW);
      BTSerial.println("LED OFF");
    }
  }
}
```

## Security considerations

- Bluetooth has limited range (~10 m), providing some physical security.
- For classroom use, simple character commands are fine.
- For real products, authentication and encryption are important.
- Never transmit passwords or sensitive data over unencrypted Bluetooth.

## Troubleshooting Bluetooth

| Problem | Solution |
|---|---|
| Device not found | Ensure ESP32 code is running and BT is started |
| Cannot pair | Restart Bluetooth on phone, restart ESP32 |
| Connected but no response | Check baud rate, verify command characters |
| Disconnects frequently | Move closer, check for interference |
| App shows garbage text | Ensure both sides use same encoding |
