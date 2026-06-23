/*
 * Session 6: Think Like a Programmer
 * Program 2: Temperature Alarm with Thresholds
 *
 * Demonstrates: conditions (if/else if/else), comparison operators, variables
 *
 * Description:
 * Reads a simulated temperature value (potentiometer on A0, mapped to 0-50°C).
 * Uses multiple conditions to classify temperature into zones:
 * - Cold (below 20°C): Blue LED
 * - Normal (20-30°C): Green LED
 * - Warm (30-40°C): Yellow LED
 * - Hot (above 40°C): Red LED + Buzzer alarm
 *
 * Wiring:
 * - Potentiometer middle pin → A0 (simulates temperature sensor)
 * - Blue LED   → pin 2 (with 330 ohm resistor)
 * - Green LED  → pin 3 (with 330 ohm resistor)
 * - Yellow LED → pin 4 (with 330 ohm resistor)
 * - Red LED    → pin 5 (with 330 ohm resistor)
 * - Buzzer     → pin 6
 *
 * Concepts practiced:
 * - Variables (temperature, sensorValue)
 * - map() function for type conversion
 * - if / else if / else (multiple thresholds)
 * - Comparison operators (<, >=, <=)
 * - Logical AND operator (&&)
 * - Functions (allOff, showZone)
 */

const int SENSOR_PIN = A0;
const int BLUE_LED = 2;
const int GREEN_LED = 3;
const int YELLOW_LED = 4;
const int RED_LED = 5;
const int BUZZER_PIN = 6;

// Temperature thresholds (degrees Celsius)
const int COLD_MAX = 20;
const int NORMAL_MAX = 30;
const int WARM_MAX = 40;

void setup() {
  Serial.begin(9600);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("=== Temperature Alarm System ===");
  Serial.println("Zones: Cold(<20) Normal(20-30) Warm(30-40) Hot(>40)");
  Serial.println();
}

void loop() {
  // Read sensor and convert to temperature
  int sensorValue = analogRead(SENSOR_PIN);
  int temperature = map(sensorValue, 0, 1023, 0, 50);

  // Display current reading
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C  -> ");

  // Turn off all indicators
  allOff();

  // Decide which zone using conditions
  if (temperature < COLD_MAX) {
    // COLD zone
    Serial.println("COLD (Blue)");
    digitalWrite(BLUE_LED, HIGH);
  } else if (temperature >= COLD_MAX && temperature < NORMAL_MAX) {
    // NORMAL zone
    Serial.println("NORMAL (Green)");
    digitalWrite(GREEN_LED, HIGH);
  } else if (temperature >= NORMAL_MAX && temperature < WARM_MAX) {
    // WARM zone
    Serial.println("WARM (Yellow)");
    digitalWrite(YELLOW_LED, HIGH);
  } else {
    // HOT zone - alarm!
    Serial.println("HOT! ALARM! (Red + Buzzer)");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500);
}

// Function: turn off all LEDs and buzzer
void allOff() {
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}
