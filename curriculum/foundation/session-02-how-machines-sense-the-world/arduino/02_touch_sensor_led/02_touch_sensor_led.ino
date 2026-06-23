// InnoBees STEM Lab - Touch Sensor LED Toggle
// Touch sensor (TTP223) signal on D3
// D8 -> 330 ohm resistor -> LED anode; LED cathode -> GND

const int TOUCH_PIN = 3;
const int LED_PIN = 8;
bool ledState = false;
bool lastTouch = false;

void setup() {
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Touch the sensor to toggle the LED.");
}

void loop() {
  bool currentTouch = digitalRead(TOUCH_PIN);

  // Detect rising edge (touch just happened)
  if (currentTouch && !lastTouch) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "LED ON" : "LED OFF");
    delay(50);  // brief debounce
  }
  lastTouch = currentTouch;
}
