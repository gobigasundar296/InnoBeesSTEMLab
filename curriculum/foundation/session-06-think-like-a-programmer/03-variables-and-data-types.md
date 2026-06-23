# Chapter 3: Variables and Data Types

## What is a variable?

A **variable** is a named container that stores a value in the computer's
memory. The value can change as the program runs.

Think of a variable as a **labeled box:**

```text
┌──────────┐     ┌──────────┐     ┌──────────┐
│ score    │     │ name     │     │ ledPin   │
│   42     │     │ "Aarav"  │     │    8     │
└──────────┘     └──────────┘     └──────────┘
```

## Why we need variables

Without variables, programs cannot:
- Remember sensor readings.
- Count events.
- Compare values.
- Change behavior over time.
- Track state (is the LED on or off?).

## Declaring variables in Arduino (C++)

```cpp
int score = 0;           // whole number
float temperature = 25.5; // decimal number
bool ledState = false;    // true or false
char command = 'A';       // single character
```

### Declaration syntax

```cpp
dataType variableName = initialValue;
```

## Common data types

| Type | Stores | Example | Size |
|---|---|---|---|
| `int` | Whole numbers | `int count = 0;` | 2 bytes |
| `long` | Large whole numbers | `long duration = 50000;` | 4 bytes |
| `float` | Decimal numbers | `float distance = 12.5;` | 4 bytes |
| `bool` | True or false | `bool isOpen = false;` | 1 byte |
| `char` | Single character | `char grade = 'A';` | 1 byte |
| `String` | Text | `String name = "InnoBees";` | varies |

## Naming rules

1. Start with a letter or underscore (not a number).
2. Can contain letters, numbers, and underscores.
3. Case-sensitive (`score` ≠ `Score` ≠ `SCORE`).
4. Cannot use reserved words (`int`, `for`, `if`, etc.).
5. Choose meaningful names!

| Bad name | Good name | Why better |
|---|---|---|
| `x` | `lightLevel` | Describes what it stores |
| `n` | `buttonCount` | Clear purpose |
| `a` | `motorSpeed` | Self-documenting |
| `temp` | `temperatureC` | Unambiguous |

## Constants

A **constant** is a variable whose value never changes. Use `const`:

```cpp
const int LED_PIN = 8;        // pin numbers don't change
const int THRESHOLD = 300;    // named threshold is clearer than magic number
const float PI_VALUE = 3.14;  // mathematical constant
```

Convention: constants use `ALL_CAPS_WITH_UNDERSCORES`.

## Variable scope

### Global variables (declared outside functions)

Available everywhere in the program:

```cpp
int score = 0;  // global — accessible in setup() and loop()

void setup() {
  score = 10;   // works
}

void loop() {
  score++;      // works
}
```

### Local variables (declared inside functions)

Only available inside that function:

```cpp
void loop() {
  int reading = analogRead(A0);  // local — only exists in loop()
  Serial.println(reading);
}

void setup() {
  // reading does NOT exist here
}
```

## Changing variable values

### Assignment

```cpp
int speed = 100;     // initial value
speed = 200;         // change to 200
speed = speed + 50;  // now 250
```

### Shorthand operators

```cpp
count++;       // same as count = count + 1
count--;       // same as count = count - 1
speed += 10;   // same as speed = speed + 10
speed -= 5;    // same as speed = speed - 5
speed *= 2;    // same as speed = speed * 2
```

## Variables in our projects

| Project | Variable | Purpose |
|---|---|---|
| Smart street light | `lightLevel` | Stores sensor reading |
| Visitor alert | `motionDetected` | Stores PIR state |
| Traffic signal | `greenTime` | Stores timing value |
| Motor control | `currentSpeed` | Stores PWM value |
| Bluetooth LED | `ledState` | Tracks ON/OFF state |
| Reaction game | `startTime` | Records when LED turned on |

## Type conversion

Sometimes you need to convert between types:

```cpp
int sensorValue = 512;
float voltage = sensorValue * (5.0 / 1023.0);  // int → float
int rounded = (int)voltage;                      // float → int (truncates)
```

The `map()` function does conversion with scaling:

```cpp
int pwm = map(sensorValue, 0, 1023, 0, 255);
```

## Practice

### What's wrong with these declarations?

```cpp
int 2ndValue = 10;      // ???
float for = 3.14;       // ???
int my score = 100;     // ???
bool ledState = "yes";  // ???
```

Answers: starts with number, reserved word, space in name, wrong type for bool.
