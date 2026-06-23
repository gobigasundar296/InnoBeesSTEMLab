/*
 * Session 6: Think Like a Programmer
 * Program 5: Password Lock System
 *
 * Demonstrates: arrays, loops, conditions, serial input, string comparison
 *
 * Description:
 * A 4-digit password lock system via Serial Monitor:
 * - User enters a 4-character password.
 * - System compares input with stored password character by character.
 * - Green LED and servo open on correct password.
 * - Red LED and buzzer on wrong password.
 * - Locks out after 3 failed attempts for 10 seconds.
 *
 * Wiring:
 * - Green LED  → pin 3 (with 330 ohm resistor)
 * - Red LED    → pin 4 (with 330 ohm resistor)
 * - Buzzer     → pin 5
 * - Servo      → pin 9 (optional, for physical lock demo)
 *
 * Concepts practiced:
 * - Arrays (storing password, storing input)
 * - For loops (comparing characters one by one)
 * - Conditions (correct/incorrect, lockout check)
 * - Variables (attempt counter, lock state)
 * - Functions (checkPassword, lockOut, openLock)
 * - While loops (reading serial input)
 */

#include <Servo.h>

const int GREEN_LED = 3;
const int RED_LED = 4;
const int BUZZER_PIN = 5;
const int SERVO_PIN = 9;

// The secret password (4 characters)
const char PASSWORD[] = "1234";
const int PASSWORD_LENGTH = 4;
const int MAX_ATTEMPTS = 3;

Servo lockServo;
int failedAttempts = 0;
bool isLocked = true;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  lockServo.attach(SERVO_PIN);
  lockServo.write(0);  // locked position

  Serial.println("===========================");
  Serial.println("   PASSWORD LOCK SYSTEM");
  Serial.println("===========================");
  Serial.println();
  Serial.println("Enter 4-digit password:");
}

void loop() {
  // Check if locked out
  if (failedAttempts >= MAX_ATTEMPTS) {
    lockOut();
    return;
  }

  // Read password from serial
  if (Serial.available() >= PASSWORD_LENGTH) {
    char input[PASSWORD_LENGTH + 1];  // +1 for null terminator

    // Read characters into array using a for loop
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
      input[i] = Serial.read();
    }
    input[PASSWORD_LENGTH] = '\0';  // null terminate

    // Clear any extra characters
    while (Serial.available()) {
      Serial.read();
    }

    Serial.print("Entered: ");
    Serial.println(input);

    // Check password
    if (checkPassword(input)) {
      accessGranted();
    } else {
      accessDenied();
    }
  }
}

// Function: compare input with password character by character
bool checkPassword(char input[]) {
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    if (input[i] != PASSWORD[i]) {
      return false;  // mismatch found
    }
  }
  return true;  // all characters matched
}

// Function: handle correct password
void accessGranted() {
  Serial.println(">>> ACCESS GRANTED <<<");
  Serial.println("Lock is OPEN");

  failedAttempts = 0;  // reset counter
  isLocked = false;

  // Green LED on
  digitalWrite(GREEN_LED, HIGH);

  // Open servo (unlock)
  lockServo.write(90);

  // Success beep
  tone(BUZZER_PIN, 1000, 100);
  delay(150);
  tone(BUZZER_PIN, 1500, 100);
  delay(150);
  tone(BUZZER_PIN, 2000, 200);

  delay(5000);  // keep open for 5 seconds

  // Re-lock
  lockServo.write(0);
  digitalWrite(GREEN_LED, LOW);
  isLocked = true;
  Serial.println("\nLock closed. Enter password:");
}

// Function: handle incorrect password
void accessDenied() {
  failedAttempts++;
  int remaining = MAX_ATTEMPTS - failedAttempts;

  Serial.println("!!! ACCESS DENIED !!!");
  Serial.print("Attempts remaining: ");
  Serial.println(remaining);

  // Red LED flash
  for (int i = 0; i < 3; i++) {
    digitalWrite(RED_LED, HIGH);
    delay(100);
    digitalWrite(RED_LED, LOW);
    delay(100);
  }

  // Error buzzer
  tone(BUZZER_PIN, 300, 500);
  delay(600);

  if (remaining > 0) {
    Serial.println("Try again:");
  }
}

// Function: lockout after too many failed attempts
void lockOut() {
  Serial.println("!!! LOCKED OUT - TOO MANY ATTEMPTS !!!");
  Serial.println("Wait 10 seconds...");

  // Flash red LED rapidly during lockout
  for (int i = 0; i < 20; i++) {
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER_PIN, 200, 50);
    delay(250);
    digitalWrite(RED_LED, LOW);
    delay(250);
  }

  // Reset attempts
  failedAttempts = 0;
  Serial.println("\nLockout over. Enter password:");
}
