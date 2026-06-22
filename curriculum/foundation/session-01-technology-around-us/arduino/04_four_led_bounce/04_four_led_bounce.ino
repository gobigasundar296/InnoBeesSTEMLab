// InnoBees STEM Lab - Four LED Bounce
// D4, D5, D6 and D7 each drive one resistor-and-LED branch.

const int LED_PINS[] = {4, 5, 6, 7};
const int LED_COUNT = 4;
const int STEP_TIME_MS = 180;

void showOnly(int activeIndex) {
  for (int index = 0; index < LED_COUNT; index++) {
    digitalWrite(LED_PINS[index], index == activeIndex ? HIGH : LOW);
  }
}

void setup() {
  for (int index = 0; index < LED_COUNT; index++) {
    pinMode(LED_PINS[index], OUTPUT);
  }
}

void loop() {
  for (int index = 0; index < LED_COUNT; index++) {
    showOnly(index);
    delay(STEP_TIME_MS);
  }

  // Skip both end LEDs because they were already shown.
  for (int index = LED_COUNT - 2; index > 0; index--) {
    showOnly(index);
    delay(STEP_TIME_MS);
  }
}
