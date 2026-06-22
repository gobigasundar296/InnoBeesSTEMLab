// InnoBees STEM Lab - Common-Cathode RGB LED Color Cycle
// D9  -> 330 ohm resistor -> red anode
// D10 -> 330 ohm resistor -> green anode
// D11 -> 330 ohm resistor -> blue anode
// Common cathode -> GND

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int COLOR_TIME_MS = 700;

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);       // Red
  delay(COLOR_TIME_MS);

  setColor(0, 255, 0);       // Green
  delay(COLOR_TIME_MS);

  setColor(0, 0, 255);       // Blue
  delay(COLOR_TIME_MS);

  setColor(255, 255, 0);     // Yellow
  delay(COLOR_TIME_MS);

  setColor(0, 255, 255);     // Cyan
  delay(COLOR_TIME_MS);

  setColor(255, 0, 255);     // Magenta
  delay(COLOR_TIME_MS);

  setColor(255, 255, 255);   // White-like mix
  delay(COLOR_TIME_MS);

  setColor(0, 0, 0);         // Off
  delay(COLOR_TIME_MS);
}
