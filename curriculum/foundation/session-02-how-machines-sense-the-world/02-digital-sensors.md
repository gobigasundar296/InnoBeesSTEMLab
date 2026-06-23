# Chapter 2: Digital Sensors — Buttons and Touch

## Push button (tactile switch)

A push button is the simplest digital input. It has two states:

- **Pressed:** circuit is closed, current flows.
- **Released:** circuit is open, no current flows.

### Internal construction

A standard four-leg tactile switch has two pairs of permanently connected
pins. Pressing the button connects the two pairs, completing the circuit.

```text
  A ----+---- B         A and B are always connected
        |               C and D are always connected
     [button]           Press connects A-B pair to C-D pair
        |
  C ----+---- D
```

When placed across the breadboard center gap, the permanently connected pairs
sit on opposite sides, and pressing creates the bridge.

### Pull-up and pull-down resistors

Without a resistor, an unpressed button leaves the Arduino input pin
*floating* — neither HIGH nor LOW. This causes unpredictable readings.

**Pull-down resistor (10 kilohm to GND):**

```text
D2 ---+--- Button --- 5V
      |
     10k
      |
     GND
```

- Button pressed: pin reads HIGH (5 V through button).
- Button released: pin reads LOW (pulled to GND through resistor).

**Internal pull-up (built into Arduino):**

```text
D2 --- Button --- GND
```

Use `pinMode(pin, INPUT_PULLUP)` to enable the internal pull-up resistor.

- Button pressed: pin reads LOW (connected to GND).
- Button released: pin reads HIGH (pulled up internally).

Note: With `INPUT_PULLUP`, the logic is *inverted* — LOW means pressed.

### Reading a button in Arduino

```cpp
const int BUTTON_PIN = 2;
const int LED_PIN = 8;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);
  if (state == LOW) {        // LOW = pressed with INPUT_PULLUP
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

## Touch sensor (TTP223)

A touch sensor module detects the presence of a finger through capacitance
change. No physical pressing force is required.

### How it works

The sensor has a copper pad covered by a protective layer. When a finger
approaches, the body's natural capacitance changes the electrical field. The
TTP223 chip detects this change and outputs a digital HIGH or LOW signal.

### Connections

| TTP223 pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| SIG (OUT) | Arduino digital pin (e.g., D3) |

### Behavior

- Default mode: output is HIGH when touched, LOW when not touched.
- Some modules have a mode jumper to toggle between momentary and toggle
  behavior.

### Advantages over push buttons

- No moving parts — longer physical life.
- Can be placed behind a panel or surface.
- Looks cleaner in a finished product.
- Hygienic — sealed surface can be cleaned.

### Reading a touch sensor

```cpp
const int TOUCH_PIN = 3;
const int LED_PIN = 8;

void setup() {
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(TOUCH_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

## Comparison: button vs. touch sensor

| Feature | Push button | Touch sensor (TTP223) |
|---|---|---|
| Detection method | Mechanical contact | Capacitance change |
| Moving parts | Yes | No |
| Requires pull resistor | Yes (or INPUT_PULLUP) | No (built into module) |
| Can work through surface | No | Yes |
| Cost | Very low | Low |
| Bounce issues | Yes | Minimal |

## Button debouncing concept

When a mechanical button is pressed or released, the metal contacts may
bounce rapidly for a few milliseconds, creating multiple false signals.

Simple software debounce: add a short delay after detecting a state change.

```cpp
if (digitalRead(BUTTON_PIN) == LOW) {
  delay(50);  // wait for bounce to settle
  if (digitalRead(BUTTON_PIN) == LOW) {
    // confirmed press
  }
}
```

Touch sensors handle debouncing internally, which is one advantage of
capacitive sensing.
