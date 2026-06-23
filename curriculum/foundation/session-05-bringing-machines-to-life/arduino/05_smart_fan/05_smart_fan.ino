// InnoBees STEM Lab - Smart Fan Controller
// L298N: ENA -> D5 (PWM), IN1 -> D6, IN2 -> D7
// LDR voltage divider on A0 (5V -> LDR -> A0 -> 10k -> GND)
// Fan (DC motor with blade) on OUT1/OUT2
// LED indicator on D3
//
// Brighter light = faster fan (simulating hotter = more cooling)

const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;
const int LDR_PIN = A0;
const int LED_PIN = 3;

// Thresholds - adjust based on your LDR
const int FAN_OFF_THRESHOLD = 200;   // below this: fan off
const int FAN_MAX_THRESHOLD = 800;   // above this: full speed
const int MIN_MOTOR_PWM = 60;        // minimum to start spinning

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Set direction (always forward for fan)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  Serial.begin(9600);
  Serial.println("=== Smart Fan Controller ===");
  Serial.println("Cover/uncover the LDR to change fan speed.");
  Serial.print("Fan OFF below: ");
  Serial.println(FAN_OFF_THRESHOLD);
  Serial.print("Fan MAX above: ");
  Serial.println(FAN_MAX_THRESHOLD);
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  int fanSpeed;
  String status;

  if (lightLevel < FAN_OFF_THRESHOLD) {
    fanSpeed = 0;
    status = "OFF (cool)";
    digitalWrite(LED_PIN, LOW);
  } else if (lightLevel > FAN_MAX_THRESHOLD) {
    fanSpeed = 255;
    status = "MAX (hot!)";
    digitalWrite(LED_PIN, HIGH);
  } else {
    fanSpeed = map(lightLevel, FAN_OFF_THRESHOLD, FAN_MAX_THRESHOLD,
                   MIN_MOTOR_PWM, 255);
    status = "AUTO";
    // Blink LED for medium
    digitalWrite(LED_PIN, (millis() / 500) % 2);
  }

  analogWrite(ENA, fanSpeed);

  Serial.print("Light: ");
  Serial.print(lightLevel);
  Serial.print(" | Fan PWM: ");
  Serial.print(fanSpeed);
  Serial.print(" | Status: ");
  Serial.println(status);

  delay(300);
}
