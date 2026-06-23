/*
 * Session 6: Think Like a Programmer
 * Program 1: Traffic Light with Timer
 *
 * Demonstrates: conditions, timing, loops, sequential logic
 *
 * Description:
 * Simulates a traffic light cycle (RED → GREEN → YELLOW → RED).
 * Uses a for loop for countdown timing and conditions for state changes.
 * Displays countdown on Serial Monitor.
 *
 * Wiring:
 * - Red LED    → pin 4 (with 330 ohm resistor)
 * - Yellow LED → pin 3 (with 330 ohm resistor)
 * - Green LED  → pin 2 (with 330 ohm resistor)
 *
 * Concepts practiced:
 * - Variables (pin numbers, timing values)
 * - Constants (timing durations)
 * - For loops (countdown)
 * - Functions (allOff, setLight)
 * - Sequential logic (state machine)
 */

const int RED_PIN = 4;
const int YELLOW_PIN = 3;
const int GREEN_PIN = 2;

const int RED_TIME = 5;      // seconds
const int GREEN_TIME = 5;    // seconds
const int YELLOW_TIME = 2;   // seconds

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  Serial.println("=== Traffic Light System ===");
  Serial.println("Cycle: RED -> GREEN -> YELLOW -> RED");
  Serial.println();
}

void loop() {
  // RED phase
  setLight("RED", RED_PIN, RED_TIME);

  // GREEN phase
  setLight("GREEN", GREEN_PIN, GREEN_TIME);

  // YELLOW phase
  setLight("YELLOW", YELLOW_PIN, YELLOW_TIME);
}

// Function: turn off all LEDs
void allOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

// Function: set a traffic light phase with countdown
void setLight(const char* name, int pin, int duration) {
  allOff();
  digitalWrite(pin, HIGH);

  Serial.print(name);
  Serial.print(" - countdown: ");

  // For loop countdown
  for (int i = duration; i > 0; i--) {
    Serial.print(i);
    Serial.print(" ");
    delay(1000);
  }

  Serial.println("-> SWITCH!");
}
