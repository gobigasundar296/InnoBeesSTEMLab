// InnoBees STEM Lab - External LED Blink
// D8 -> 330 ohm resistor -> LED anode
// LED cathode -> GND

const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);

  digitalWrite(LED_PIN, LOW);
  delay(500);
}
