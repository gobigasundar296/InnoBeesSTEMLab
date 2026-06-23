// InnoBees STEM Lab - Ultrasonic Distance Meter
// HC-SR04: VCC -> 5V, GND -> GND, TRIG -> D9, ECHO -> D10
// Displays distance on Serial Monitor

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Distance Meter");
  Serial.println("Point the sensor at an object.");
}

float measureDistance() {
  // Send 10us trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration (timeout 30ms = ~500cm max)
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;  // no echo received
  }

  // Calculate distance: speed of sound = 0.034 cm/us, divide by 2 for round trip
  return (duration * 0.034) / 2.0;
}

void loop() {
  float distance = measureDistance();

  if (distance > 0) {
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
  } else {
    Serial.println("Out of range!");
  }
  delay(250);
}
