/*
 * Session 6: Think Like a Programmer
 * Program 6: Debug Challenge (Intentional Bugs)
 *
 * *** THIS PROGRAM HAS INTENTIONAL BUGS ***
 * *** STUDENTS MUST FIND AND FIX THEM ***
 *
 * Description:
 * This program SHOULD make a smart nightlight:
 * - Read light level from LDR
 * - If dark: LED fades in smoothly (breathing effect)
 * - If bright: LED off
 * - Display light level and status on Serial Monitor
 * - Button press toggles override mode (LED always on)
 *
 * Wiring:
 * - LDR + 10k resistor → A0 (voltage divider)
 * - LED (PWM)          → pin 9 (with 330 ohm resistor)
 * - Button             → pin 2 (INPUT_PULLUP, other side to GND)
 *
 * === BUGS TO FIND (8 total) ===
 * Students should find all 8 bugs.
 * The fixed version is in the comments at the bottom of this file.
 *
 * Concepts tested:
 * - Syntax errors (missing characters)
 * - Logic errors (wrong comparisons)
 * - Pin configuration errors
 * - Variable type errors
 * - Function errors
 */

// --- BUGGY CODE STARTS HERE ---

const int LDR_PIN = A0;
const int LED_PIN = 9;
const int BUTTON_PIN = 2;
const int THRESHOLD = 400;  // dark below this value

bool overrideMode = false;
int brightness = 0
bool fadingUp = true;

void setup() {
  Serial.begin(9600)
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, OUTPUT);  // Bug: should be INPUT_PULLUP

  Serial.println("=== Smart Nightlight ===");
  Serial.println("Press button to toggle override mode");
}

void loop() {
  // Check button (simple debounce)
  if (digitalRead(BUTTON_PIN) = LOW) {  // Bug: = should be ==
    overrideMode = !overrideMode;
    Serial.print("Override mode: ");
    Serial.println(overrideMode ? "ON" : "OFF");
    delay(300);  // debounce
  }

  // Read light level
  int lightLevel = analogRead(LDR_PIN);

  Serial.print("Light: ");
  Serial.print(lightLevel);
  Serial.print(" | Mode: ");

  if (overrideMode) {
    // Override: LED always on at full brightness
    analogWrite(LED_PIN, 255);
    Serial.println("OVERRIDE - Full ON");
  } else if (lightLevel > THRESHOLD) {  // Bug: should be < for "dark"
    // Dark: do breathing effect
    breatheLED();
    Serial.println("DARK - Breathing");
  } else {
    // Bright: LED off
    analogWrite(LED_PIN, 0);
    Serial.println("BRIGHT - LED OFF");
  }

  delay(100);
}

// Function: breathing/fading LED effect
void breatheLED() {
  if (fadingUp) {
    brightness += 5;
    if (brightness >= 255) {
      brightness = 255;
      fadingUp = false;
    }
  } else {
    brightness += 5;  // Bug: should be -= 5
    if (brightness <= 0) {
      brightness = 0;
      fadingUp = true;
    }
  }

  analogWrite(LED_PIN, brightness)  // Bug: missing semicolon
}


// === ANSWER KEY (for teachers) ===
/*
 * BUG LIST:
 *
 * Bug 1: Line 42 - Missing semicolon after "int brightness = 0"
 *   Fix: int brightness = 0;
 *
 * Bug 2: Line 45 - Missing semicolon after "Serial.begin(9600)"
 *   Fix: Serial.begin(9600);
 *
 * Bug 3: Line 46 - BUTTON_PIN set as OUTPUT instead of INPUT_PULLUP
 *   Fix: pinMode(BUTTON_PIN, INPUT_PULLUP);
 *
 * Bug 4: Line 53 - Assignment (=) used instead of comparison (==)
 *   Fix: if (digitalRead(BUTTON_PIN) == LOW) {
 *
 * Bug 5: Line 69 - Condition is wrong (> should be <)
 *   Explanation: When it's dark, LDR gives LOW values (below threshold)
 *   Fix: } else if (lightLevel < THRESHOLD) {
 *
 * Bug 6: Line 85 - brightness should decrease (+=  should be -=)
 *   Fix: brightness -= 5;
 *
 * Bug 7: Line 92 - Missing semicolon after analogWrite call
 *   Fix: analogWrite(LED_PIN, brightness);
 *
 * Bug 8: (Bonus/subtle) The breathing function is called once per loop
 *   iteration but `delay(100)` in main loop means it fades very slowly.
 *   Not a crash bug, but a design issue. Reducing delay or increasing
 *   step size (brightness += 15) makes it visible.
 *
 * CORRECTED VERSION:
 *
 * const int LDR_PIN = A0;
 * const int LED_PIN = 9;
 * const int BUTTON_PIN = 2;
 * const int THRESHOLD = 400;
 *
 * bool overrideMode = false;
 * int brightness = 0;              // FIXED: added semicolon
 * bool fadingUp = true;
 *
 * void setup() {
 *   Serial.begin(9600);            // FIXED: added semicolon
 *   pinMode(LED_PIN, OUTPUT);
 *   pinMode(BUTTON_PIN, INPUT_PULLUP);  // FIXED: INPUT_PULLUP
 *   Serial.println("=== Smart Nightlight ===");
 * }
 *
 * void loop() {
 *   if (digitalRead(BUTTON_PIN) == LOW) {  // FIXED: == not =
 *     overrideMode = !overrideMode;
 *     Serial.print("Override: ");
 *     Serial.println(overrideMode ? "ON" : "OFF");
 *     delay(300);
 *   }
 *
 *   int lightLevel = analogRead(LDR_PIN);
 *   Serial.print("Light: ");
 *   Serial.print(lightLevel);
 *   Serial.print(" | ");
 *
 *   if (overrideMode) {
 *     analogWrite(LED_PIN, 255);
 *     Serial.println("OVERRIDE");
 *   } else if (lightLevel < THRESHOLD) {   // FIXED: < not >
 *     breatheLED();
 *     Serial.println("DARK - Breathing");
 *   } else {
 *     analogWrite(LED_PIN, 0);
 *     Serial.println("BRIGHT - OFF");
 *   }
 *   delay(100);
 * }
 *
 * void breatheLED() {
 *   if (fadingUp) {
 *     brightness += 5;
 *     if (brightness >= 255) {
 *       brightness = 255;
 *       fadingUp = false;
 *     }
 *   } else {
 *     brightness -= 5;             // FIXED: -= not +=
 *     if (brightness <= 0) {
 *       brightness = 0;
 *       fadingUp = true;
 *     }
 *   }
 *   analogWrite(LED_PIN, brightness);  // FIXED: added semicolon
 * }
 */
