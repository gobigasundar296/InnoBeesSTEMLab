// InnoBees STEM Lab - LDR Smart Street Light
// LDR voltage divider: 5V -> LDR -> A0 -> 10k resistor -> GND
// D8 -> 330 ohm resistor -> LED anode; LED cathode -> GND
// When dark (low reading), LED turns ON automatically

const int LDR_PIN = A0;
const int LED_PIN = 8;
const int DARK_THRESHOLD = 300;  // Adjust based on your LDR and environment

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Smart Street Light Active");
  Serial.println("Cover the LDR to simulate darkness.");
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);

  Serial.print("Light level: ");
  Serial.print(lightLevel);

  if (lightLevel < DARK_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println(" -> DARK: Street light ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println(" -> BRIGHT: Street light OFF");
  }
  delay(500);
}
