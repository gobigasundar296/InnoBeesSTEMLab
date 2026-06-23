// InnoBees STEM Lab - Traffic Signal System
// Red LED on D4 -> 330 ohm -> LED -> GND
// Yellow LED on D3 -> 330 ohm -> LED -> GND
// Green LED on D2 -> 330 ohm -> LED -> GND
// Simulates a standard traffic light sequence

const int RED_PIN = 4;
const int YELLOW_PIN = 3;
const int GREEN_PIN = 2;

void allOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Traffic Signal System ===");
}

void loop() {
  // GREEN phase - Go
  allOff();
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("GREEN - GO");
  delay(5000);

  // YELLOW phase - Prepare to stop
  allOff();
  digitalWrite(YELLOW_PIN, HIGH);
  Serial.println("YELLOW - PREPARE TO STOP");
  delay(2000);

  // RED phase - Stop
  allOff();
  digitalWrite(RED_PIN, HIGH);
  Serial.println("RED - STOP");
  delay(5000);

  // RED + YELLOW phase - Get ready (used in some countries)
  digitalWrite(YELLOW_PIN, HIGH);
  Serial.println("RED + YELLOW - GET READY");
  delay(1500);
}
