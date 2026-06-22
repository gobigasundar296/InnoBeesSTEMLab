// InnoBees STEM Lab - Control an LED from Serial Monitor
// D8 -> 330 ohm resistor -> LED anode; LED cathode -> GND
// Serial Monitor baud rate: 9600
// Send: 1 = on, 0 = off, b = blink once

const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Send 1 for ON, 0 for OFF, or b to blink.");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } else if (command == '0') {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    } else if (command == 'b' || command == 'B') {
      digitalWrite(LED_PIN, HIGH);
      delay(250);
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED BLINK");
    }
  }
}
