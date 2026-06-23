// InnoBees STEM Lab - Multi-Sensor Smart Classroom
// LDR on A0 (voltage divider with 10k)
// PIR on D4
// Sound sensor digital on D5
// Buzzer on D7
// LED on D8
//
// Features:
// - Auto-light: LED on when dark AND someone is present
// - Noise alert: buzzer beeps when loud sound detected
// - Serial Monitor shows all sensor readings

const int LDR_PIN = A0;
const int PIR_PIN = 4;
const int SOUND_PIN = 5;
const int BUZZER_PIN = 7;
const int LED_PIN = 8;

const int DARK_THRESHOLD = 300;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("=== SMART CLASSROOM SYSTEM ===");
  Serial.println("Initializing sensors...");
  Serial.println("Waiting 30 seconds for PIR warm-up.");
  delay(30000);
  Serial.println("All systems active!");
  Serial.println("---");
}

void loop() {
  // Read all sensors
  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  int sound = digitalRead(SOUND_PIN);

  // Display sensor data
  Serial.print("Light: ");
  Serial.print(light);
  Serial.print(" | Motion: ");
  Serial.print(motion ? "YES" : "no");
  Serial.print(" | Sound: ");
  Serial.print(sound ? "LOUD" : "quiet");

  // Auto-light logic: turn on if dark AND someone is present
  if (light < DARK_THRESHOLD && motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.print(" | -> LIGHT ON");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Noise alert: beep if loud sound detected
  if (sound == HIGH) {
    Serial.print(" | -> NOISE ALERT!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  }

  Serial.println();
  delay(500);
}
