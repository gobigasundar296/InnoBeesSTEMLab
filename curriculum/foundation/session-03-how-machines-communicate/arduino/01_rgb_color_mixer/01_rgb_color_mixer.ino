// InnoBees STEM Lab - RGB LED Color Mixer
// RGB LED (Common Cathode):
//   Red pin -> 330 ohm -> D9 (PWM)
//   Green pin -> 330 ohm -> D10 (PWM)
//   Blue pin -> 330 ohm -> D11 (PWM)
//   Common cathode -> GND
// Cycles through colors, then accepts Serial commands

const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== RGB Color Mixer ===");
  Serial.println("Enter R,G,B values (e.g., 255,128,0)");
  Serial.println("Showing demo colors first...");

  // Demo: cycle through basic colors
  setColor(255, 0, 0);    // Red
  delay(800);
  setColor(0, 255, 0);    // Green
  delay(800);
  setColor(0, 0, 255);    // Blue
  delay(800);
  setColor(255, 255, 0);  // Yellow
  delay(800);
  setColor(255, 0, 255);  // Magenta
  delay(800);
  setColor(0, 255, 255);  // Cyan
  delay(800);
  setColor(255, 255, 255);// White
  delay(800);
  setColor(0, 0, 0);      // Off

  Serial.println("Demo complete. Enter your RGB values:");
}

void loop() {
  if (Serial.available() > 0) {
    int r = Serial.parseInt();
    int g = Serial.parseInt();
    int b = Serial.parseInt();

    r = constrain(r, 0, 255);
    g = constrain(g, 0, 255);
    b = constrain(b, 0, 255);

    setColor(r, g, b);
    Serial.print("Color set to: R=");
    Serial.print(r);
    Serial.print(" G=");
    Serial.print(g);
    Serial.print(" B=");
    Serial.println(b);
  }
}
