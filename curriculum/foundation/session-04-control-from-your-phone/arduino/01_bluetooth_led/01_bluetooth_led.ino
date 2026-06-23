// InnoBees STEM Lab - ESP32 Bluetooth LED Control
// Built-in LED on GPIO 2 (most ESP32 boards)
// Phone app: "Serial Bluetooth Terminal" (Android)
// Commands: '1' = ON, '0' = OFF, 's' = status, 'b' = blink

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  SerialBT.begin("InnoBees_LED");  // Bluetooth device name
  Serial.println("=== InnoBees Bluetooth LED Control ===");
  Serial.println("Bluetooth started. Device name: InnoBees_LED");
  Serial.println("Pair your phone, then open Serial Bluetooth Terminal app.");

  SerialBT.println("=== InnoBees LED Control ===");
  SerialBT.println("Commands:");
  SerialBT.println("  1 = LED ON");
  SerialBT.println("  0 = LED OFF");
  SerialBT.println("  b = Blink 3 times");
  SerialBT.println("  s = Status");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {
      case '1':
        digitalWrite(LED_PIN, HIGH);
        SerialBT.println("LED: ON");
        Serial.println("BT Command: LED ON");
        break;

      case '0':
        digitalWrite(LED_PIN, LOW);
        SerialBT.println("LED: OFF");
        Serial.println("BT Command: LED OFF");
        break;

      case 'b':
      case 'B':
        SerialBT.println("Blinking 3 times...");
        for (int i = 0; i < 3; i++) {
          digitalWrite(LED_PIN, HIGH);
          delay(300);
          digitalWrite(LED_PIN, LOW);
          delay(300);
        }
        SerialBT.println("Blink complete.");
        break;

      case 's':
      case 'S':
        SerialBT.print("LED is currently: ");
        SerialBT.println(digitalRead(LED_PIN) ? "ON" : "OFF");
        break;
    }
  }
}
