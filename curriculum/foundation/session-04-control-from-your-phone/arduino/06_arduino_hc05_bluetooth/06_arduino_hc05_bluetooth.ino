// InnoBees STEM Lab - Arduino Uno with HC-05 Bluetooth Module
// For teams using Arduino Uno instead of ESP32
// HC-05 TX -> Arduino D10 (SoftwareSerial RX)
// HC-05 RX -> Voltage divider (1k+2k) -> Arduino D11 (SoftwareSerial TX)
// HC-05 VCC -> 5V, GND -> GND
// LED on D8 -> 330 ohm -> LED -> GND
//
// Commands via Bluetooth: '1'=ON, '0'=OFF, 'b'=blink, 's'=status

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);  // RX, TX

const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.println("=== InnoBees Arduino Bluetooth (HC-05) ===");
  Serial.println("Pair your phone with 'HC-05' (PIN: 1234)");
  Serial.println("Then open Serial Bluetooth Terminal app.");

  BTSerial.println("InnoBees LED Control");
  BTSerial.println("Commands: 1=ON, 0=OFF, b=blink, s=status");
}

void loop() {
  // Check for Bluetooth commands
  if (BTSerial.available()) {
    char command = BTSerial.read();

    switch (command) {
      case '1':
        digitalWrite(LED_PIN, HIGH);
        BTSerial.println("LED: ON");
        Serial.println("BT: LED ON");
        break;

      case '0':
        digitalWrite(LED_PIN, LOW);
        BTSerial.println("LED: OFF");
        Serial.println("BT: LED OFF");
        break;

      case 'b':
      case 'B':
        BTSerial.println("Blinking...");
        for (int i = 0; i < 3; i++) {
          digitalWrite(LED_PIN, HIGH);
          delay(300);
          digitalWrite(LED_PIN, LOW);
          delay(300);
        }
        BTSerial.println("Done.");
        break;

      case 's':
      case 'S':
        BTSerial.print("LED is: ");
        BTSerial.println(digitalRead(LED_PIN) ? "ON" : "OFF");
        break;
    }
  }

  // Forward Serial Monitor to Bluetooth (for debugging)
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
