/*
 * Session 6: Think Like a Programmer
 * Program 4: Reaction Time Game
 *
 * Demonstrates: variables, timing, conditions, random, serial input
 *
 * Description:
 * A reaction time game:
 * 1. LED turns on after a random delay (2-5 seconds).
 * 2. Player must press button as fast as possible.
 * 3. Reaction time is measured and displayed.
 * 4. Tracks best score across multiple rounds.
 * 5. Reports if pressed too early (cheat detection).
 *
 * Wiring:
 * - LED        → pin 8 (with 330 ohm resistor)
 * - Button     → pin 2 (with INPUT_PULLUP, other side to GND)
 * - Buzzer     → pin 6 (for start/end signals)
 *
 * Concepts practiced:
 * - Variables (timing, score tracking)
 * - millis() for non-blocking timing
 * - random() for unpredictable delays
 * - Conditions (too early, valid press, new record)
 * - while loop (waiting for input)
 * - Comparison (tracking best time)
 */

const int LED_PIN = 8;
const int BUTTON_PIN = 2;
const int BUZZER_PIN = 6;

unsigned long bestTime = 99999;  // best reaction time in ms
int roundNumber = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  // Seed random number generator from unused analog pin
  randomSeed(analogRead(A5));

  Serial.println("=================================");
  Serial.println("   REACTION TIME GAME");
  Serial.println("=================================");
  Serial.println();
  Serial.println("Rules:");
  Serial.println("- Wait for the LED to turn ON");
  Serial.println("- Press the button as FAST as possible");
  Serial.println("- Don't press early or it's a foul!");
  Serial.println();
  Serial.println("Press button to start...");

  // Wait for initial button press
  waitForPress();
  delay(500);
}

void loop() {
  roundNumber++;
  Serial.print("\n--- Round ");
  Serial.print(roundNumber);
  Serial.println(" ---");
  Serial.println("Get ready...");

  // Random wait (2000-5000 ms)
  unsigned long waitTime = random(2000, 5001);

  // Check for early press during wait (cheating!)
  unsigned long waitStart = millis();
  bool cheated = false;

  while (millis() - waitStart < waitTime) {
    if (digitalRead(BUTTON_PIN) == LOW) {
      cheated = true;
      break;
    }
  }

  if (cheated) {
    Serial.println("TOO EARLY! That's a foul!");
    // Buzzer error sound
    tone(BUZZER_PIN, 200, 500);
    delay(2000);
    Serial.println("Try again...");
    delay(1000);
    return;  // skip to next round
  }

  // Turn LED on — NOW!
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 1000, 50);  // short beep
  unsigned long startTime = millis();

  // Wait for button press (with 5 second timeout)
  while (digitalRead(BUTTON_PIN) == HIGH) {
    if (millis() - startTime > 5000) {
      Serial.println("Too slow! (5 second timeout)");
      digitalWrite(LED_PIN, LOW);
      delay(1000);
      return;
    }
  }

  // Calculate reaction time
  unsigned long reactionTime = millis() - startTime;
  digitalWrite(LED_PIN, LOW);

  // Display result
  Serial.print("Reaction time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  // Check for new record
  if (reactionTime < bestTime) {
    bestTime = reactionTime;
    Serial.println("*** NEW BEST TIME! ***");
    // Victory beep
    tone(BUZZER_PIN, 1500, 100);
    delay(150);
    tone(BUZZER_PIN, 2000, 100);
  }

  // Classify speed
  if (reactionTime < 200) {
    Serial.println("Rating: INCREDIBLE!");
  } else if (reactionTime < 300) {
    Serial.println("Rating: Excellent!");
  } else if (reactionTime < 500) {
    Serial.println("Rating: Good");
  } else {
    Serial.println("Rating: Keep practicing!");
  }

  Serial.print("Best time so far: ");
  Serial.print(bestTime);
  Serial.println(" ms");

  // Wait before next round
  delay(2000);
  Serial.println("\nPress button for next round...");
  waitForPress();
  delay(300);
}

// Function: wait for button press (blocking)
void waitForPress() {
  while (digitalRead(BUTTON_PIN) == HIGH) {
    // wait
  }
  // Debounce
  delay(50);
}
