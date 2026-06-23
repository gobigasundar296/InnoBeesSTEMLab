# Chapter 2: RGB LED Color Mixing and PWM

## RGB color model

The RGB color model creates colors by mixing three primary light colors:

- **R**ed
- **G**reen
- **B**lue

By varying the intensity of each color from 0 (off) to 255 (full brightness),
we can create millions of color combinations.

## Color mixing basics

| Red | Green | Blue | Result |
|---|---|---|---|
| 255 | 0 | 0 | Red |
| 0 | 255 | 0 | Green |
| 0 | 0 | 255 | Blue |
| 255 | 255 | 0 | Yellow |
| 255 | 0 | 255 | Magenta (pink) |
| 0 | 255 | 255 | Cyan (light blue) |
| 255 | 255 | 255 | White |
| 0 | 0 | 0 | Off |
| 255 | 128 | 0 | Orange |
| 128 | 0 | 128 | Purple |

## PWM for brightness control

`analogWrite(pin, value)` creates a PWM signal:

- **value = 0:** LED is off (0% brightness).
- **value = 127:** LED is at ~50% brightness.
- **value = 255:** LED is at 100% brightness.

PWM works by switching the pin on and off very rapidly. The human eye sees
the average brightness, not the flicker.

```text
255: ████████████████  (always on)
192: ████████████░░░░  (75% on)
127: ████████░░░░░░░░  (50% on)
 64: ████░░░░░░░░░░░░  (25% on)
  0: ░░░░░░░░░░░░░░░░  (always off)
```

## RGB LED connections (common cathode)

```text
Arduino D9  (PWM) -> 330 ohm -> Red pin
Arduino D10 (PWM) -> 330 ohm -> Green pin
Arduino D11 (PWM) -> 330 ohm -> Blue pin
Common cathode pin -> GND
```

Each color channel needs its own resistor because:

- Red, green, and blue LEDs have different forward voltages.
- Each channel must be independently current-limited.

## Arduino program: color cycle

```cpp
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);    // Red
  delay(1000);
  setColor(0, 255, 0);    // Green
  delay(1000);
  setColor(0, 0, 255);    // Blue
  delay(1000);
  setColor(255, 255, 0);  // Yellow
  delay(1000);
  setColor(255, 0, 255);  // Magenta
  delay(1000);
  setColor(0, 255, 255);  // Cyan
  delay(1000);
  setColor(255, 255, 255);// White
  delay(1000);
}
```

## Smooth color fading

By gradually changing PWM values, we can create smooth transitions:

```cpp
// Fade red from off to full brightness
for (int i = 0; i <= 255; i++) {
  analogWrite(RED_PIN, i);
  delay(10);
}

// Fade red from full to off
for (int i = 255; i >= 0; i--) {
  analogWrite(RED_PIN, i);
  delay(10);
}
```

## RGB LED as a status indicator

RGB LEDs are excellent for showing system status with color:

| Color | Meaning |
|---|---|
| Green | Everything OK |
| Yellow | Warning, attention needed |
| Red | Error or danger |
| Blue | Processing or standby |
| White | System active |
| Purple | Special mode |

## Common anode vs. common cathode

| Type | Common pin | Turn on color | Turn off color |
|---|---|---|---|
| Common cathode | GND | `analogWrite(pin, 255)` | `analogWrite(pin, 0)` |
| Common anode | 5V | `analogWrite(pin, 0)` | `analogWrite(pin, 255)` |

With common anode, the logic is inverted: writing 0 turns the color ON
(full current flows), writing 255 turns it OFF.

Always check your RGB LED type before coding!
