// InnoBees STEM Lab - Buzzer Melody Player
// Passive buzzer on D7
// Plays a scale and then "Twinkle Twinkle Little Star"

const int BUZZER_PIN = 7;

// Note frequencies (Hz)
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

// Twinkle Twinkle Little Star melody
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

int durations[] = {
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800
};

int numNotes = 42;

void playScale() {
  Serial.println("Playing scale: C D E F G A B C");
  int scale[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
                 NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
  for (int i = 0; i < 8; i++) {
    tone(BUZZER_PIN, scale[i], 300);
    delay(400);
  }
  noTone(BUZZER_PIN);
  delay(500);
}

void playMelody() {
  Serial.println("Playing: Twinkle Twinkle Little Star");
  for (int i = 0; i < numNotes; i++) {
    tone(BUZZER_PIN, melody[i], durations[i]);
    delay(durations[i] + 50);
  }
  noTone(BUZZER_PIN);
}

void setup() {
  Serial.begin(9600);
  Serial.println("=== Buzzer Melody Player ===");

  playScale();
  delay(1000);
  playMelody();

  Serial.println("Done! Reset to play again.");
}

void loop() {
  // nothing - plays once in setup
}
