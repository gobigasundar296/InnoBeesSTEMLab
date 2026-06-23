# Chapter 6: Functions and Debugging

## What is a function?

A **function** is a named block of code that performs a specific task. You can
call it by name whenever you need that task done.

### Why use functions?

1. **Reuse:** Write once, use many times.
2. **Organize:** Break complex code into manageable pieces.
3. **Readability:** `openGate()` is clearer than 10 lines of servo code.
4. **Debug:** Test each function independently.

## Arduino's built-in structure

Arduino already uses two functions:

```cpp
void setup() {
  // runs once at start
}

void loop() {
  // runs repeatedly forever
}
```

## Writing your own functions

### Function with no return value

```cpp
void blinkLED(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
}

// Usage:
blinkLED(8, 3);   // blink pin 8 three times
blinkLED(9, 5);   // blink pin 9 five times
```

### Function that returns a value

```cpp
float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH, 30000);
  return (duration * 0.034) / 2.0;
}

// Usage:
float dist = getDistance();
Serial.println(dist);
```

### Function structure

```cpp
returnType functionName(parameters) {
  // code
  return value;  // if returnType is not void
}
```

| Part | Examples |
|---|---|
| Return type | `void`, `int`, `float`, `bool` |
| Name | `blinkLED`, `getDistance`, `isButtonPressed` |
| Parameters | `int pin`, `int times`, or empty `()` |

## Functions from our projects

| Function | What it does | Returns |
|---|---|---|
| `getDistance()` | Measures ultrasonic distance | `float` (cm) |
| `openGate()` | Moves servo to open position | `void` |
| `closeGate()` | Moves servo to closed position | `void` |
| `setColor(r,g,b)` | Sets RGB LED color | `void` |
| `motorForward(speed)` | Drives motor forward | `void` |
| `measureDistance()` | Same as getDistance | `float` |
| `buildHTML()` | Creates web page | `String` |

## What is debugging?

**Debugging** is the process of finding and fixing errors (bugs) in code.
The name comes from early computing when a literal bug (moth) was found in
a computer causing a malfunction.

## Types of errors

### 1. Syntax errors (compile errors)

The code breaks language rules. Arduino IDE shows a red error message.

```cpp
// ERRORS:
int led = 8     // missing semicolon
digitalwrite(8, HIGH);  // wrong capitalization (should be digitalWrite)
if (x = 5) {   // should be == for comparison
```

### 2. Logic errors (code runs but does wrong thing)

The program compiles and runs, but doesn't behave correctly.

```cpp
// BUG: LED never turns on even when dark
if (lightLevel > THRESHOLD) {   // should be < not >
  digitalWrite(LED_PIN, HIGH);
}
```

### 3. Runtime errors (crashes or hangs during execution)

```cpp
// BUG: dividing by zero
int average = total / count;  // crashes if count is 0

// BUG: infinite loop
while (Serial.available() == 0) {
  // stuck here if nothing is sent
}
```

## Debugging strategies

### 1. Read the error message

Arduino IDE error messages tell you:
- The **line number** where the error is.
- The **type** of error.
- A **description** of what's wrong.

### 2. Use Serial.println() for tracing

Print variable values to see what the program is doing:

```cpp
void loop() {
  int light = analogRead(A0);
  Serial.print("DEBUG: light = ");   // ← add this
  Serial.println(light);              // ← add this

  if (light < THRESHOLD) {
    Serial.println("DEBUG: LED ON");  // ← add this
    digitalWrite(LED_PIN, HIGH);
  }
}
```

### 3. Check one thing at a time

Don't change multiple things. Change ONE thing, test, then change another.

### 4. Compare with working code

If a new program doesn't work, compare it line-by-line with a program you
know works.

### 5. Rubber duck debugging

Explain your code out loud, line by line, to a rubber duck (or teammate).
Often, you'll find the bug just by explaining.

## Common Arduino bugs

| Bug | Symptom | Fix |
|---|---|---|
| Wrong pin number | Nothing happens | Check pin matches wiring |
| Missing `pinMode()` | Output doesn't work | Add in `setup()` |
| `=` instead of `==` | Condition always true | Use `==` for comparison |
| Missing `Serial.begin()` | No serial output | Add in `setup()` |
| Wrong baud rate | Garbage in monitor | Match code and monitor setting |
| Variable overflow | Unexpected values | Use `long` for large numbers |
| Missing `delay()` | Runs too fast to see | Add appropriate delays |
| Floating input pin | Random readings | Add pull-up/pull-down |

## Debug challenge format

Given a program with intentional bugs, students must:

1. **Identify** each bug (describe what's wrong).
2. **Explain** why it causes a problem.
3. **Fix** the code.
4. **Verify** by predicting the correct behavior.

Example:

```cpp
// BUG HUNT: Find 3 errors in this button LED program
void setup() {
  pinMode(LED_PIN, OUTPUT)     // Bug 1: missing semicolon
  pinMode(BUTTON_PIN, OUTPUT); // Bug 2: should be INPUT or INPUT_PULLUP
}

void loop() {
  if (digitalRead(BUTTON_PIN) = HIGH) {  // Bug 3: = should be ==
    digitalWrite(LED_PIN, HIGH);
  }
}
```
