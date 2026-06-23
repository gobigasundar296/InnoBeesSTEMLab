# Student Workbook: Think Like a Programmer

**Name:** _________________________  
**Class:** _________________________  
**Team:** _________________________  
**Date:** _________________________

## Part A - Algorithms

### 1. What is an algorithm?

An algorithm is: ____________________________________________________

____________________________________________________________________

### 2. Write an algorithm: Making a phone call

Write step-by-step instructions for calling a friend:

```text
1. 
2. 
3. 
4. 
5. 
6. 
```

### 3. Write an algorithm: Automatic door

Write the algorithm for a door that opens when someone approaches:

```text
1. 
2. 
3. 
4. 
5. 
6. 
```

### 4. What makes a good algorithm? (tick all that apply)

- [ ] Steps are clear and unambiguous
- [ ] Steps are in the correct order
- [ ] It eventually finishes (or loops intentionally)
- [ ] Each step can actually be done
- [ ] It uses fancy words

## Part B - Flowcharts

### 1. Match the shape to its meaning

| Shape | Meaning |
|---|---|
| Oval | |
| Rectangle | |
| Diamond | |
| Parallelogram | |
| Arrow | |

Word bank: *Start/End, Process/Action, Decision (Yes/No), Input/Output, Flow direction*

### 2. Draw a flowchart: LED control

Draw a flowchart for: "Read a button. If pressed, turn LED on. Otherwise, turn LED off. Repeat forever."

```text




```

### 3. Draw a flowchart: Temperature zones

Draw a flowchart for: "Read temperature. If above 35, show RED. If 25-35, show GREEN. If below 25, show BLUE."

```text




```

## Part C - Variables

### 1. What is a variable?

____________________________________________________________________

### 2. Choose the correct data type

| Variable | Type (int, float, bool, char, String) |
|---|---|
| Number of button presses | |
| Temperature reading (23.5°C) | |
| Is the LED on? | |
| Command from Serial ('A') | |
| Student name | |
| Pin number | |

### 3. What's wrong with these variable names?

| Declaration | Error |
|---|---|
| `int 3rdPlace = 0;` | |
| `float my speed = 5.0;` | |
| `int for = 10;` | |
| `bool ledState = "true";` | |

### 4. Trace the values

What is the value of `x` after each line?

```cpp
int x = 5;        // x = ___
x = x + 3;        // x = ___
x = x * 2;        // x = ___
x++;               // x = ___
x -= 4;            // x = ___
```

## Part D - Conditions

### 1. Write the condition for each situation

| Situation | Code condition |
|---|---|
| Light level is below 300 | `if (____________)` |
| Button is pressed (INPUT_PULLUP) | `if (____________)` |
| Distance is less than 20 cm | `if (____________)` |
| Temperature between 20 and 30 | `if (____________)` |
| Motor speed equals zero | `if (____________)` |

### 2. What does this code do?

```cpp
int score = 75;

if (score >= 90) {
  Serial.println("A");
} else if (score >= 70) {
  Serial.println("B");
} else if (score >= 50) {
  Serial.println("C");
} else {
  Serial.println("F");
}
```

Output: _____________

### 3. Fill in the blanks

```cpp
int light = analogRead(A0);

if (light _____ 200) {
  // very dark - turn on bright LED
  analogWrite(LED_PIN, 255);
} else if (light _____ 600) {
  // medium - dim LED
  analogWrite(LED_PIN, 100);
} _______ {
  // bright - LED off
  analogWrite(LED_PIN, 0);
}
```

## Part E - Loops

### 1. What does this for loop do?

```cpp
for (int i = 0; i < 5; i++) {
  Serial.println(i);
}
```

Output (write each line):

```text
___
___
___
___
___
```

### 2. How many times does this loop run?

```cpp
for (int i = 1; i <= 10; i += 2) {
  Serial.println(i);
}
```

Number of times: _______

Values printed: ____________________

### 3. Write a for loop that:

Blinks an LED on pin 8 exactly 7 times (200ms on, 200ms off):

```cpp
for (________________________________) {
  
  
  
  
}
```

### 4. What's the difference between for and while?

`for` loop: _________________________________________________________

`while` loop: _______________________________________________________

## Part F - Functions

### 1. Why do we use functions? (list two reasons)

1. ________________________________________________________________
2. ________________________________________________________________

### 2. Identify the parts of this function

```cpp
float getDistance() {
  long duration = pulseIn(ECHO, HIGH);
  return (duration * 0.034) / 2.0;
}
```

Return type: _____________

Function name: _____________

Parameters: _____________

What it returns: _____________

### 3. Write a function

Write a function called `beep` that takes a parameter `times` and beeps a
buzzer on pin 7 that many times:

```cpp
void beep(___________) {
  for (________________________________) {
    
    
    
    
  }
}
```

## Part G - Debugging

### 1. Find the bugs! (3 errors)

```cpp
const int LED_PIN = 8;
const int BUTTON_PIN = 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) = LOW) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

Bug 1: Line ___ : ___________________________________________________

Bug 2: Line ___ : ___________________________________________________

Bug 3: Line ___ : ___________________________________________________

### 2. Find the logic error

This code should turn the LED ON when it's dark, but it doesn't work:

```cpp
int light = analogRead(A0);
if (light > 300) {
  digitalWrite(LED_PIN, HIGH);  // should turn on when dark
}
```

What's wrong? _____________________________________________________

Fix: ______________________________________________________________

### 3. What debugging tool shows variable values while running?

____________________________________________________________________

## Part H - Coding challenges

### Challenge 1: Predict the output

```cpp
int a = 10;
int b = 3;
Serial.println(a / b);
Serial.println(a % b);
```

Output line 1: _______

Output line 2: _______

### Challenge 2: Design challenge

**Problem:** Create a countdown timer from 10 to 0 that:
- Displays each number on Serial Monitor
- Blinks an LED with each count
- When it reaches 0, sounds a buzzer for 2 seconds

Write the algorithm:

```text
1. 
2. 
3. 
4. 
5. 
```

Write the code (or pseudocode):

```cpp



```

## Part I - Reflection

### 1. Which programming concept was hardest to understand?

____________________________________________________________________

### 2. What debugging strategy will you use first when code doesn't work?

____________________________________________________________________

### 3. How is writing an algorithm similar to giving directions?

____________________________________________________________________
