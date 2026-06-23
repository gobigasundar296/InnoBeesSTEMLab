// InnoBees STEM Lab - 7-Segment Display Counter
// Common cathode 7-segment display
// Segments: a=D2, b=D3, c=D4, d=D5, e=D6, f=D7, g=D8
// Each segment through a 330 ohm resistor
// Common cathode -> GND
// Counts from 0 to 9 repeatedly

// Pin assignments for segments a through g
const int SEG_A = 2;
const int SEG_B = 3;
const int SEG_C = 4;
const int SEG_D = 5;
const int SEG_E = 6;
const int SEG_F = 7;
const int SEG_G = 8;

const int segPins[] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G};

// Segment patterns: {a, b, c, d, e, f, g}
const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void displayDigit(int num) {
  if (num < 0 || num > 9) return;
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[num][i]);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], LOW);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("7-Segment Counter");
}

void loop() {
  for (int d = 0; d <= 9; d++) {
    displayDigit(d);
    Serial.print("Displaying: ");
    Serial.println(d);
    delay(1000);
  }
}
