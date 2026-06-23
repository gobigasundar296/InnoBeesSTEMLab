# Chapter 4: 7-Segment Display

## What is a 7-segment display?

A 7-segment display uses seven individual LEDs (labeled a-g) arranged in a
figure-8 pattern to show digits 0 through 9 and some letters.

```text
   ___
  | a |
  f   b
  |_g_|
  e   c
  |_d_|  .dp
```

## Segment map

| Digit | a | b | c | d | e | f | g |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
| 1 | 0 | 1 | 1 | 0 | 0 | 0 | 0 |
| 2 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |
| 3 | 1 | 1 | 1 | 1 | 0 | 0 | 1 |
| 4 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |
| 5 | 1 | 0 | 1 | 1 | 0 | 1 | 1 |
| 6 | 1 | 0 | 1 | 1 | 1 | 1 | 1 |
| 7 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| 8 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 9 | 1 | 1 | 1 | 1 | 0 | 1 | 1 |

## Common cathode vs. common anode

- **Common cathode:** All cathodes share one GND pin. Segments turn on with
  HIGH.
- **Common anode:** All anodes share one 5V pin. Segments turn on with LOW.

This module uses common cathode (HIGH = segment on).

## Connections to Arduino

Each segment needs its own Arduino pin and current-limiting resistor (330 ohm).

| Segment | Arduino pin | Through |
|---|---|---|
| a | D2 | 330 ohm resistor |
| b | D3 | 330 ohm resistor |
| c | D4 | 330 ohm resistor |
| d | D5 | 330 ohm resistor |
| e | D6 | 330 ohm resistor |
| f | D7 | 330 ohm resistor |
| g | D8 | 330 ohm resistor |
| Common cathode | GND | direct |

## Arduino program: digit display

```cpp
// Segment pins: a=D2, b=D3, c=D4, d=D5, e=D6, f=D7, g=D8
const int segPins[] = {2, 3, 4, 5, 6, 7, 8};

// Segment patterns for digits 0-9 (a,b,c,d,e,f,g)
const byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[num][i]);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop() {
  for (int d = 0; d <= 9; d++) {
    displayDigit(d);
    delay(1000);
  }
}
```

## Using arrays for patterns

The program above uses a 2D array to store segment patterns. This is more
efficient than writing separate `if` statements for each digit.

- `digits[0]` contains the pattern for displaying "0".
- `digits[5]` contains the pattern for displaying "5".
- Each pattern has 7 values (one per segment).

## Displaying letters

Some letters can be shown on a 7-segment display:

| Letter | Segments on |
|---|---|
| A | a, b, c, e, f, g |
| b | c, d, e, f, g |
| C | a, d, e, f |
| d | b, c, d, e, g |
| E | a, d, e, f, g |
| F | a, e, f, g |
| H | b, c, e, f, g |
| L | d, e, f |

Not all letters are possible — this is a limitation of 7-segment displays.

## Practical applications

- Digital clocks (four 7-segment displays).
- Counters (score boards, visitor counters).
- Temperature displays.
- Simple numeric indicators.

## When to use 7-segment vs. LCD

| Feature | 7-segment | LCD (16x2) |
|---|---|---|
| Shows | Digits and some letters | Full text and numbers |
| Visibility | Very bright, visible from far | Moderate |
| Wiring | Many pins (7 per digit) | 2 pins with I2C |
| Cost | Very low | Moderate |
| Best for | Counters, clocks | Messages, sensor data |
