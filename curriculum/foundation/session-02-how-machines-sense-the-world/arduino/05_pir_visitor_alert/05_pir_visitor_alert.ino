// InnoBees STEM Lab - PIR Visitor Alert
// PIR sensor (HC-SR501) OUT -> D4
// Buzzer -> D7, LED -> D8
// Wait 30 seconds for PIR to warm up before testing

const int PIR_PIN = 4;
const int BUZZER_PIN = 7;
const int LED_PIN = 8;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("=== VISITOR ALERT SYSTEM ===");
  Serial.println("PIR sensor warming up...");
  Serial.println("Please wait 30 seconds.");

  // Blink LED during warm-up to show system is starting
  for (int i = 0; i < 30; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }

  Serial.println("System READY! Walk past the sensor.");
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("*** VISITOR DETECTED! ***");
    digitalWrite(LED_PIN, HIGH);

    // Three alert beeps
    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
    delay(1000);  // pause before next detection
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}
