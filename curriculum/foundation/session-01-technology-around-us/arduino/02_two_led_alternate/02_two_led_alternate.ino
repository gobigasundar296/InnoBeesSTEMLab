// InnoBees STEM Lab - Two Alternating LEDs
// D7 -> 330 ohm resistor -> LED 1 anode; cathode -> GND
// D8 -> 330 ohm resistor -> LED 2 anode; cathode -> GND

const int LED_1_PIN = 7;
const int LED_2_PIN = 8;
const int STEP_TIME_MS = 500;

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, LOW);
  delay(STEP_TIME_MS);

  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, HIGH);
  delay(STEP_TIME_MS);
}
