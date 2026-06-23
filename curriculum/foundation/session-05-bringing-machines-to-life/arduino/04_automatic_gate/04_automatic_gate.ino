// InnoBees STEM Lab - Automatic Gate
// HC-SR04: TRIG -> D9, ECHO -> D10
// Servo: Signal -> D6
// Green LED -> D4, Red LED -> D5
// Gate opens when person is within 30 cm

#include <Servo.h>

Servo gateServo;

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int SERVO_PIN = 6;
const int GREEN_LED = 4;
const int RED_LED = 5;

const int OPEN_DISTANCE = 30;  // cm threshold
const int OPEN_ANGLE = 90;
const int CLOSED_ANGLE = 0;
const int HOLD_TIME = 5000;    // keep open for 5 seconds

bool gateOpen = false;

void setup() {
  gateServo.attach(SERVO_PIN);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Start with gate closed
  gateServo.write(CLOSED_ANGLE);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  Serial.begin(9600);
  Serial.println("=== Automatic Gate System ===");
  Serial.print("Opens when object is within ");
  Serial.print(OPEN_DISTANCE);
  Serial.println(" cm");
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return 999.0;
  return (duration * 0.034) / 2.0;
}

void smoothOpen() {
  Serial.println(">> Gate OPENING");
  for (int a = CLOSED_ANGLE; a <= OPEN_ANGLE; a++) {
    gateServo.write(a);
    delay(15);
  }
  gateOpen = true;
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
}

void smoothClose() {
  Serial.println(">> Gate CLOSING");
  for (int a = OPEN_ANGLE; a >= CLOSED_ANGLE; a--) {
    gateServo.write(a);
    delay(15);
  }
  gateOpen = false;
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
}

void loop() {
  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.print(" cm | Gate: ");
  Serial.println(gateOpen ? "OPEN" : "CLOSED");

  if (distance < OPEN_DISTANCE && distance > 2) {
    if (!gateOpen) {
      smoothOpen();
    }
    delay(HOLD_TIME);  // keep gate open
  } else {
    if (gateOpen) {
      smoothClose();
    }
  }
  delay(200);
}
