/*
 * Session 6: Think Like a Programmer
 * Program 3: Pattern Generator (Loops)
 *
 * Demonstrates: for loops, nested loops, arrays, loop patterns
 *
 * Description:
 * Generates multiple LED patterns using different loop techniques:
 * - Pattern 1: Sequential chase (left to right)
 * - Pattern 2: Bounce (left to right, then right to left)
 * - Pattern 3: Build-up (accumulate one by one)
 * - Pattern 4: Binary counter (LEDs show binary numbers)
 * Patterns change automatically every 10 seconds.
 *
 * Wiring:
 * - LED 1 → pin 2 (with 330 ohm resistor)
 * - LED 2 → pin 3 (with 330 ohm resistor)
 * - LED 3 → pin 4 (with 330 ohm resistor)
 * - LED 4 → pin 5 (with 330 ohm resistor)
 *
 * Concepts practiced:
 * - Arrays (storing pin numbers)
 * - For loops (counting, iterating arrays)
 * - Nested loops (patterns within patterns)
 * - Variables (speed, pattern number)
 * - Modulo operator (%) for cycling
 */

const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {2, 3, 4, 5};
const int SPEED = 200;  // milliseconds between steps

int currentPattern = 0;

void setup() {
  Serial.begin(9600);

  // Use a loop to set all pins as output
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.println("=== Pattern Generator ===");
  Serial.println("4 patterns using loops");
  Serial.println();
}

void loop() {
  // Cycle through patterns
  switch (currentPattern) {
    case 0:
      Serial.println("Pattern 1: Chase ->");
      patternChase();
      break;
    case 1:
      Serial.println("Pattern 2: Bounce <->");
      patternBounce();
      break;
    case 2:
      Serial.println("Pattern 3: Build-up");
      patternBuildUp();
      break;
    case 3:
      Serial.println("Pattern 4: Binary counter");
      patternBinary();
      break;
  }

  // Move to next pattern (using modulo to cycle)
  currentPattern = (currentPattern + 1) % 4;
  delay(500);  // pause between patterns
}

// Function: turn off all LEDs
void allOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

// Pattern 1: Simple chase left to right (3 rounds)
void patternChase() {
  for (int round = 0; round < 3; round++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      allOff();
      digitalWrite(ledPins[i], HIGH);
      delay(SPEED);
    }
  }
  allOff();
}

// Pattern 2: Bounce left-right-left (2 rounds)
void patternBounce() {
  for (int round = 0; round < 2; round++) {
    // Left to right
    for (int i = 0; i < NUM_LEDS; i++) {
      allOff();
      digitalWrite(ledPins[i], HIGH);
      delay(SPEED);
    }
    // Right to left
    for (int i = NUM_LEDS - 2; i > 0; i--) {
      allOff();
      digitalWrite(ledPins[i], HIGH);
      delay(SPEED);
    }
  }
  allOff();
}

// Pattern 3: Build-up — LEDs turn on one by one, then all off
void patternBuildUp() {
  for (int round = 0; round < 3; round++) {
    // Turn on one at a time (accumulate)
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(SPEED);
    }
    delay(300);
    // Turn off one at a time
    for (int i = NUM_LEDS - 1; i >= 0; i--) {
      digitalWrite(ledPins[i], LOW);
      delay(SPEED);
    }
    delay(200);
  }
}

// Pattern 4: Binary counter 0-15 displayed on 4 LEDs
void patternBinary() {
  // Count from 0 to 15 (4 bits)
  for (int number = 0; number <= 15; number++) {
    // Set each LED based on the bit value
    for (int bit = 0; bit < NUM_LEDS; bit++) {
      if (number & (1 << bit)) {
        digitalWrite(ledPins[bit], HIGH);
      } else {
        digitalWrite(ledPins[bit], LOW);
      }
    }
    Serial.print("  Binary: ");
    Serial.println(number);
    delay(SPEED * 2);
  }
  allOff();
}
