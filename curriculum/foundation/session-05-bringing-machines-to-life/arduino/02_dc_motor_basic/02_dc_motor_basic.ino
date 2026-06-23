// InnoBees STEM Lab - DC Motor Basic Control
// L298N Motor Driver:
//   ENA -> D5 (PWM), IN1 -> D6, IN2 -> D7
//   Motor on OUT1/OUT2
//   Battery (6-9V) on VMS, GND shared with Arduino
// Demonstrates forward, reverse, and stop

const int ENA = 5;   // PWM speed control
const int IN1 = 6;   // direction pin 1
const int IN2 = 7;   // direction pin 2

void motorForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);
}

void motorReverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
}

void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void motorBrake() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== DC Motor Basic Control ===");
  Serial.println("Forward -> Stop -> Reverse -> Brake -> Repeat");
}

void loop() {
  Serial.println("FORWARD");
  motorForward();
  delay(3000);

  Serial.println("STOP (coast)");
  motorStop();
  delay(2000);

  Serial.println("REVERSE");
  motorReverse();
  delay(3000);

  Serial.println("BRAKE");
  motorBrake();
  delay(2000);
}
