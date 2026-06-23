// InnoBees STEM Lab - DC Motor Speed Control (PWM)
// L298N: ENA -> D5 (PWM), IN1 -> D6, IN2 -> D7
// Potentiometer on A0 controls speed
// Motor on OUT1/OUT2, Battery on VMS

const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;
const int POT_PIN = A0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Set direction to forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  Serial.begin(9600);
  Serial.println("=== DC Motor Speed Control ===");
  Serial.println("Turn the potentiometer to change speed.");
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  analogWrite(ENA, motorSpeed);

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print(" -> PWM: ");
  Serial.print(motorSpeed);
  Serial.print(" -> Speed: ");
  Serial.print(map(motorSpeed, 0, 255, 0, 100));
  Serial.println("%");

  delay(100);
}
