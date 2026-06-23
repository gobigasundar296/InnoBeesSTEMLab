// InnoBees STEM Lab - Button LED Control
// D2 -> Push button -> GND (using INPUT_PULLUP)
// D8 -> 330 ohm resistor -> LED anode; LED cathode -> GND

const int BUTTON_PIN = 2;
const int LED_PIN = 8;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {  // LOW = pressed with INPUT_PULLUP
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button PRESSED - LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(50);
}
