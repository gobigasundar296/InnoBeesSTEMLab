// InnoBees STEM Lab - Four LED Chaser
// D4, D5, D6 and D7 each connect to:
// digital pin -> 330 ohm resistor -> LED anode; LED cathode -> GND

const int LED_PINS[] = {4, 5, 6, 7};
const int LED_COUNT = 4;
const int STEP_TIME_MS = 180;

void setup() {
  for (int index = 0; index < LED_COUNT; index++) {
    pinMode(LED_PINS[index], OUTPUT);
  }
}

void loop() {
  for (int index = 0; index < LED_COUNT; index++) {
    digitalWrite(LED_PINS[index], HIGH);
    delay(STEP_TIME_MS);
    digitalWrite(LED_PINS[index], LOW);
  }
}
