// InnoBees STEM Lab - Servo Angle Control
// SG90 Servo: Signal -> D9, Red -> 5V, Brown -> GND
// Control servo angle from Serial Monitor
// Type an angle (0-180) and press Enter

#include <Servo.h>

Servo myServo;
const int SERVO_PIN = 9;

void setup() {
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);

  Serial.println("=== Servo Angle Control ===");
  Serial.println("Enter an angle (0-180) to move the servo.");
  Serial.println("Special commands: s = sweep, c = center");

  // Start at center position
  myServo.write(90);
  Serial.println("Servo at 90 degrees (center).");
}

void sweep() {
  Serial.println("Sweeping 0 -> 180 -> 0...");
  for (int angle = 0; angle <= 180; angle += 2) {
    myServo.write(angle);
    delay(15);
  }
  for (int angle = 180; angle >= 0; angle -= 2) {
    myServo.write(angle);
    delay(15);
  }
  Serial.println("Sweep complete.");
}

void loop() {
  if (Serial.available() > 0) {
    char first = Serial.peek();

    if (first == 's' || first == 'S') {
      Serial.read();  // consume the character
      sweep();
    } else if (first == 'c' || first == 'C') {
      Serial.read();
      myServo.write(90);
      Serial.println("Centered at 90 degrees.");
    } else {
      int angle = Serial.parseInt();
      if (angle >= 0 && angle <= 180) {
        myServo.write(angle);
        Serial.print("Servo moved to: ");
        Serial.print(angle);
        Serial.println(" degrees");
      } else {
        Serial.println("Invalid! Enter 0-180, 's' for sweep, 'c' for center.");
      }
    }
  }
}
