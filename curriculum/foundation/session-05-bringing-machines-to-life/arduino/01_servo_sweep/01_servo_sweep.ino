// InnoBees STEM Lab - Servo Sweep and Positions
// SG90 Servo signal -> D9, Red -> 5V, Brown -> GND
// Demonstrates smooth sweep and specific positions

#include <Servo.h>

Servo myServo;
const int SERVO_PIN = 9;

void smoothMove(int targetAngle, int stepDelay) {
  int current = myServo.read();

  if (current < targetAngle) {
    for (int a = current; a <= targetAngle; a++) {
      myServo.write(a);
      delay(stepDelay);
    }
  } else {
    for (int a = current; a >= targetAngle; a--) {
      myServo.write(a);
      delay(stepDelay);
    }
  }
}

void setup() {
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);
  Serial.println("=== Servo Sweep and Positions ===");
  myServo.write(0);
  delay(500);
}

void loop() {
  // Demonstrate specific positions
  Serial.println("Moving to 0 degrees (closed)");
  smoothMove(0, 15);
  delay(1000);

  Serial.println("Moving to 45 degrees (half open)");
  smoothMove(45, 15);
  delay(1000);

  Serial.println("Moving to 90 degrees (open)");
  smoothMove(90, 15);
  delay(1000);

  Serial.println("Moving to 180 degrees (full range)");
  smoothMove(180, 15);
  delay(1000);

  // Full sweep
  Serial.println("Sweeping 180 -> 0...");
  smoothMove(0, 10);
  delay(2000);
}
