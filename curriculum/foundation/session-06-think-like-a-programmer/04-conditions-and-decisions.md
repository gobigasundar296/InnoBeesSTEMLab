# Chapter 4: Conditions and Decisions

## Why programs need decisions

Without conditions, programs can only do the same thing every time. With
conditions, programs can **react differently** to different situations.

```text
Without conditions:          With conditions:
  LED always on              IF dark THEN LED on
                             ELSE LED off
```

## The if statement

```cpp
if (condition) {
  // code runs only when condition is true
}
```

### Example: button check

```cpp
if (digitalRead(BUTTON_PIN) == LOW) {
  digitalWrite(LED_PIN, HIGH);
}
```

## if...else

```cpp
if (condition) {
  // runs when condition is TRUE
} else {
  // runs when condition is FALSE
}
```

### Example: light control

```cpp
int light = analogRead(LDR_PIN);

if (light < 300) {
  digitalWrite(LED_PIN, HIGH);  // dark: turn on
} else {
  digitalWrite(LED_PIN, LOW);   // bright: turn off
}
```

## if...else if...else (multiple conditions)

```cpp
if (condition1) {
  // runs when condition1 is true
} else if (condition2) {
  // runs when condition2 is true
} else {
  // runs when none of the above are true
}
```

### Example: distance zones

```cpp
float distance = getDistance();

if (distance < 10) {
  Serial.println("TOO CLOSE!");
  digitalWrite(RED_LED, HIGH);
} else if (distance < 30) {
  Serial.println("WARNING");
  digitalWrite(YELLOW_LED, HIGH);
} else {
  Serial.println("SAFE");
  digitalWrite(GREEN_LED, HIGH);
}
```

## Comparison operators

| Operator | Meaning | Example |
|---|---|---|
| `==` | Equal to | `if (x == 5)` |
| `!=` | Not equal to | `if (x != 0)` |
| `<` | Less than | `if (temp < 30)` |
| `>` | Greater than | `if (speed > 100)` |
| `<=` | Less than or equal | `if (count <= 10)` |
| `>=` | Greater than or equal | `if (score >= 50)` |

**Warning:** `==` (comparison) is NOT `=` (assignment)!

```cpp
if (x == 5)   // CORRECT: checks if x equals 5
if (x = 5)    // WRONG: assigns 5 to x (always true!)
```

## Logical operators (combining conditions)

| Operator | Meaning | Example |
|---|---|---|
| `&&` | AND (both must be true) | `if (temp > 30 && humidity > 80)` |
| `||` | OR (at least one true) | `if (button1 == LOW || button2 == LOW)` |
| `!` | NOT (inverts) | `if (!motionDetected)` |

### AND example: smart light

Turn on light only when it's dark AND someone is present:

```cpp
if (lightLevel < 300 && motionDetected == HIGH) {
  digitalWrite(LED_PIN, HIGH);
}
```

### OR example: alarm

Sound alarm if fire detected OR intrusion detected:

```cpp
if (flameDetected == LOW || pirTriggered == HIGH) {
  digitalWrite(BUZZER_PIN, HIGH);
}
```

## Nested conditions

Conditions inside conditions:

```cpp
if (systemArmed) {
  if (motionDetected) {
    soundAlarm();
  }
}
```

This is equivalent to:

```cpp
if (systemArmed && motionDetected) {
  soundAlarm();
}
```

## The switch statement

When checking one variable against many values:

```cpp
char command = Serial.read();

switch (command) {
  case '1':
    digitalWrite(LED_PIN, HIGH);
    break;
  case '0':
    digitalWrite(LED_PIN, LOW);
    break;
  case 'b':
    blinkLED();
    break;
  default:
    Serial.println("Unknown command");
    break;
}
```

## Common mistakes

| Mistake | Problem | Fix |
|---|---|---|
| `if (x = 5)` | Assigns instead of compares | `if (x == 5)` |
| Missing `{}` | Only first line is conditional | Always use braces |
| Using `&&` when meaning `||` | Logic error | Think: "BOTH" vs "EITHER" |
| Overlapping ranges | Multiple conditions true | Use `else if` |
| Forgetting `break` in switch | Falls through to next case | Add `break;` |

## Real-world decision examples

| Scenario | Condition | True action | False action |
|---|---|---|---|
| Street light | Dark? | LED on | LED off |
| Alarm | Motion? | Buzzer on | Buzzer off |
| Gate | Person close? | Open servo | Close servo |
| Fan | Hot? | Motor fast | Motor slow/off |
| Display | Button pressed? | Show next screen | Keep current |
