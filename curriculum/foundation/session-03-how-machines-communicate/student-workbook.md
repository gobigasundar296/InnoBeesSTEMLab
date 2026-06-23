# Student Workbook: How Machines Communicate

**Name:** _________________________  
**Class:** _________________________  
**Team:** _________________________  
**Date:** _________________________

## Safety promise

Tick each rule before starting.

- [ ] I will check pin numbers before uploading code.
- [ ] I will not force the servo motor shaft by hand.
- [ ] I will use resistors with all LEDs including RGB channels.
- [ ] I will disconnect power before changing wires.
- [ ] I will not point buzzers directly at anyone's ear.
- [ ] I will ask the teacher before connecting unfamiliar modules.

## Part A - Input vs. Output

### 1. Classify each device

Write `INPUT` or `OUTPUT` next to each device:

| Device | Input or Output? |
|---|---|
| Push button | |
| LED | |
| LDR | |
| Buzzer | |
| PIR sensor | |
| LCD display | |
| Servo motor | |
| Ultrasonic sensor | |

### 2. Complete the Input-Process-Output model

**System: Automatic gate**

| Input | Process | Output |
|---|---|---|
| _________ detects _________ | Arduino decides _________ | _________ moves to _________ |

### 3. Digital output vs. PWM

Digital output gives _______ states: _______ and _______.

PWM gives _______ levels by switching rapidly. Range: _______ to _______.

PWM pins on Arduino Uno are: _________________________________

## Part B - RGB LED and colors

### 1. What color do these combinations make?

| Red | Green | Blue | Predicted color | Observed color |
|---|---|---|---|---|
| 255 | 0 | 0 | | |
| 0 | 255 | 0 | | |
| 0 | 0 | 255 | | |
| 255 | 255 | 0 | | |
| 255 | 0 | 255 | | |
| 0 | 255 | 255 | | |
| 255 | 255 | 255 | | |

### 2. Create your own color

Choose a target color: _________________

What RGB values did you use? R=_____ G=_____ B=_____

### 3. Why does each RGB channel need its own resistor?

____________________________________________________________________

### 4. Complete the code

```cpp
analogWrite(RED_PIN, _____);    // full red
analogWrite(GREEN_PIN, _____);  // half green
analogWrite(BLUE_PIN, _____);   // no blue
```

What color would this produce? _________________________________

## Part C - LCD Display

### 1. What does LCD stand for?

____________________________________________________________________

### 2. How many characters can a 16x2 LCD show?

Total characters: _______  Rows: _______  Columns per row: _______

### 3. What is the advantage of I2C?

Without I2C: _______ data wires needed.

With I2C: _______ data wires needed (_______ and _______).

### 4. Write the code to display your name on row 0 and class on row 1

```cpp
lcd.setCursor(_____, _____);
lcd.print("_______________");

lcd.setCursor(_____, _____);
lcd.print("_______________");
```

### 5. What should you do if the LCD is blank after uploading?

____________________________________________________________________

## Part D - 7-Segment Display

### 1. How many LED segments make up the display?

_______

### 2. Fill in which segments are ON for each digit

| Digit | Draw which segments light up |
|---|---|
| 0 | |
| 3 | |
| 7 | |

### 3. When would you choose a 7-segment over an LCD?

____________________________________________________________________

## Part E - Buzzer

### 1. Active vs. passive buzzer

| Feature | Active buzzer | Passive buzzer |
|---|---|---|
| Needs frequency signal? | | |
| Can play different notes? | | |
| Arduino function | | |

### 2. What is the frequency of note A4?

_______ Hz

### 3. Design an alert pattern

Describe what your alert means: _________________________________

Pattern: _____ ms on, _____ ms off, repeated _____ times.

## Part F - Servo Motor

### 1. What makes a servo different from a regular motor?

____________________________________________________________________

### 2. What is the rotation range of a standard servo?

_______ degrees to _______ degrees

### 3. What are the three servo wires?

Brown/Black = _____________

Red = _____________

Orange/Yellow = _____________

### 4. Complete the code to move servo to 90 degrees

```cpp
#include <____________>

Servo myServo;

void setup() {
  myServo.attach(_____);
  myServo.write(_____);
}
```

### 5. Name two applications where a servo motor is useful

1. ________________________________________________________________

2. ________________________________________________________________

## Part G - Build challenges

### Challenge 1: Traffic Signal

**Objective:** Build a traffic light with Red, Yellow, Green LEDs.

Timing sequence:

- Green on for _____ seconds
- Yellow on for _____ seconds
- Red on for _____ seconds

Did it work correctly? ____________

What would you add to make it better? _________________________________

### Challenge 2: Welcome Display

**Objective:** Show a welcome message on the LCD.

Line 1 displays: _________________________________________________

Line 2 displays: _________________________________________________

### Challenge 3: Smart Classroom Display (team challenge)

**Objective:** Design an output system using at least 3 different outputs.

What problem does your system solve?

____________________________________________________________________

Outputs used:

1. ________________________________________________________________
2. ________________________________________________________________
3. ________________________________________________________________

Sensor input connected: ____________________________________________

Describe the system behavior:

____________________________________________________________________

____________________________________________________________________

____________________________________________________________________

## Part H - Reflection

### 1. Which output device was most interesting? Why?

____________________________________________________________________

### 2. What system would you build combining sensors from Session 2 with outputs from today?

____________________________________________________________________

____________________________________________________________________

### 3. What was the hardest part of today's session?

____________________________________________________________________
