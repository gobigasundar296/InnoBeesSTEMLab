# Chapter 5: Loops — Repeating Actions

## Why loops matter

Without loops, repeating an action 10 times means writing the same code
10 times. Loops let us say "do this N times" or "keep doing this while
a condition is true."

### Without a loop (bad)

```cpp
digitalWrite(LED_PIN, HIGH);
delay(200);
digitalWrite(LED_PIN, LOW);
delay(200);
digitalWrite(LED_PIN, HIGH);
delay(200);
digitalWrite(LED_PIN, LOW);
delay(200);
digitalWrite(LED_PIN, HIGH);
delay(200);
digitalWrite(LED_PIN, LOW);
delay(200);
// ... 10 more times ...
```

### With a loop (good)

```cpp
for (int i = 0; i < 10; i++) {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}
```

Same result. Shorter code. Easy to change to 20 or 100 times.

## The for loop

Use when you **know how many times** to repeat.

### Syntax

```cpp
for (initialization; condition; update) {
  // code to repeat
}
```

### Parts explained

```cpp
for (int i = 0; i < 5; i++) {
//    ↑          ↑       ↑
//    Start at 0  While <5  Add 1 each time
//
//    Runs with i = 0, 1, 2, 3, 4  (5 times)
}
```

### Examples

```cpp
// Blink LED 3 times
for (int i = 0; i < 3; i++) {
  digitalWrite(LED_PIN, HIGH);
  delay(300);
  digitalWrite(LED_PIN, LOW);
  delay(300);
}

// Count from 1 to 10
for (int num = 1; num <= 10; num++) {
  Serial.println(num);
}

// Fade LED brightness up
for (int brightness = 0; brightness <= 255; brightness += 5) {
  analogWrite(LED_PIN, brightness);
  delay(30);
}

// Light LEDs one by one (chaser)
int ledPins[] = {2, 3, 4, 5, 6};
for (int i = 0; i < 5; i++) {
  digitalWrite(ledPins[i], HIGH);
  delay(200);
  digitalWrite(ledPins[i], LOW);
}
```

## The while loop

Use when you **don't know how many times** — repeat while a condition is true.

### Syntax

```cpp
while (condition) {
  // code repeats as long as condition is true
}
```

### Examples

```cpp
// Wait until button is pressed
while (digitalRead(BUTTON_PIN) == HIGH) {
  // do nothing, just wait
}
Serial.println("Button pressed!");

// Read serial commands until 'q' is received
char cmd = ' ';
while (cmd != 'q') {
  if (Serial.available()) {
    cmd = Serial.read();
    Serial.println(cmd);
  }
}
Serial.println("Quit received.");
```

## The do...while loop

Runs at least once, then checks the condition:

```cpp
do {
  // code runs at least once
  int reading = analogRead(A0);
  Serial.println(reading);
  delay(500);
} while (reading < 500);
```

## The loop() function in Arduino

Arduino's `loop()` function is itself an infinite loop:

```cpp
void loop() {
  // This entire block repeats forever
  // It's equivalent to: while(true) { ... }
}
```

## Nested loops

Loops inside loops:

```cpp
// 3 rounds of 5 blinks each
for (int round = 1; round <= 3; round++) {
  Serial.print("Round ");
  Serial.println(round);

  for (int blink = 0; blink < 5; blink++) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
  delay(1000);  // pause between rounds
}
```

## Loop control: break and continue

### break — exit the loop early

```cpp
for (int i = 0; i < 100; i++) {
  int distance = getDistance();
  if (distance < 5) {
    Serial.println("TOO CLOSE! Stopping.");
    break;  // exit the loop immediately
  }
  moveForward();
}
```

### continue — skip to next iteration

```cpp
for (int i = 0; i < 10; i++) {
  int value = analogRead(A0);
  if (value < 100) {
    continue;  // skip this reading, it's noise
  }
  Serial.println(value);  // only print valid readings
}
```

## Common loop patterns in Arduino

| Pattern | Loop type | Example use |
|---|---|---|
| Blink N times | `for` | Alert beeps |
| Fade up/down | `for` with PWM | LED breathing effect |
| LED chaser | `for` over array | Running lights |
| Wait for input | `while` | Wait for button |
| Count events | `for` or `while` | Score counter |
| Sweep servo | `for` | Radar scan |
| Read until valid | `while` | Sensor stabilization |

## Infinite loop dangers

A `while(true)` or `while(1)` loop with no exit condition will run forever.
In Arduino's `loop()`, this is expected. But inside `setup()` or a function,
an accidental infinite loop will freeze your program.

```cpp
// DANGER: this never exits if button is never pressed
while (digitalRead(BUTTON_PIN) == HIGH) {
  // stuck here forever if button is broken
}
```

**Safety:** Add a timeout or escape condition:

```cpp
unsigned long startTime = millis();
while (digitalRead(BUTTON_PIN) == HIGH) {
  if (millis() - startTime > 10000) {
    Serial.println("Timeout! Moving on.");
    break;
  }
}
```

## Practice: trace the loop

What does this print?

```cpp
for (int i = 1; i <= 5; i++) {
  Serial.print(i * 2);
  Serial.print(" ");
}
```

Answer: `2 4 6 8 10`
