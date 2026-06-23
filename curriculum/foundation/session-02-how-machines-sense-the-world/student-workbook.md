# Student Workbook: How Machines Sense the World

**Name:** _________________________  
**Class:** _________________________  
**Team:** _________________________  
**Date:** _________________________

## Safety promise

Tick each rule before starting.

- [ ] I will check the sensor voltage rating before connecting.
- [ ] I will not touch powered circuits with wet hands.
- [ ] I will use Serial Monitor to observe sensor data before adding outputs.
- [ ] I will not point ultrasonic sensors at anyone's ears.
- [ ] I will not create open flames to test the flame sensor.
- [ ] I will ask the teacher before connecting an unfamiliar module.

## Part A - Understanding sensors

### 1. What is a sensor?

A sensor is:

____________________________________________________________________

### 2. Input-Process-Output model

Complete the diagram for a Smart Street Light:

| Input | Process | Output |
|---|---|---|
| Sensor: _________ detects _________ | Arduino checks if _________ | _________ turns _________ |

### 3. Digital vs. analog

Explain the difference:

Digital sensor output: _________________________________________________

Analog sensor output: _________________________________________________

### 4. Human senses to electronic sensors

| Human sense | What it detects | Electronic sensor equivalent |
|---|---|---|
| Eyes | | |
| Ears | | |
| Skin (touch) | | |
| Skin (temperature) | | |

## Part B - Push button

### 1. Why do we need a pull-up or pull-down resistor?

____________________________________________________________________

____________________________________________________________________

### 2. Complete the table

| Pull-down resistor | Button pressed | Button released |
|---|---|---|
| Pin reads: | ________ | ________ |

| INPUT_PULLUP | Button pressed | Button released |
|---|---|---|
| Pin reads: | ________ | ________ |

### 3. Write the Arduino code to read a button on pin D2

```cpp
pinMode(_____, _____________);

int state = ___________(______);
```

## Part C - LDR (Light-Dependent Resistor)

### 1. How does an LDR work?

When light increases, LDR resistance _______________________.

When light decreases, LDR resistance _______________________.

### 2. Draw the voltage divider circuit

```text
5V --- [     ] --- A0 --- [      ] --- GND
       (label)            (label)
```

### 3. Serial Monitor observations

Cover the LDR and record the reading: _________________

Shine light on the LDR and record the reading: _________________

What threshold value would you choose? _________________

Why did you choose this value?

____________________________________________________________________

### 4. Complete the Smart Street Light code

```cpp
int lightLevel = analogRead(______);

if (lightLevel _____ THRESHOLD) {
  digitalWrite(LED_PIN, ______);  // turn on: it's dark
} else {
  digitalWrite(LED_PIN, ______);  // turn off: it's bright
}
```

## Part D - Ultrasonic sensor (HC-SR04)

### 1. How does it measure distance?

Step 1: Arduino sends a ____________ to the TRIG pin.

Step 2: Sensor sends out ____________ pulses.

Step 3: Pulses hit an ____________ and bounce back.

Step 4: The ECHO pin stays ____________ for the travel time.

Step 5: Arduino calculates ____________ from the time.

### 2. Distance formula

```text
Distance (cm) = (____________ × 0.034) / ______
```

Why do we divide by 2? _________________________________________________

### 3. Measurement activity

| Actual distance (ruler) | Sensor reading | Difference |
|---|---|---|
| 5 cm | | |
| 15 cm | | |
| 30 cm | | |
| 50 cm | | |
| 100 cm | | |

Is the sensor accurate? At what range does it become unreliable?

____________________________________________________________________

## Part E - PIR motion sensor

### 1. What does PIR stand for?

____________________________________________________________________

### 2. What does it actually detect?

____________________________________________________________________

### 3. Why does the PIR need warm-up time?

____________________________________________________________________

### 4. True or False

| Statement | T/F |
|---|---|
| PIR detects a person standing still | |
| PIR can detect animals | |
| PIR uses infrared radiation | |
| PIR measures exact distance | |
| PIR output is digital (HIGH/LOW) | |

## Part F - Sensor identification

Look at the sensors on your table. For each one, fill in:

| Sensor | What it detects | Digital or analog? | Arduino function to read it |
|---|---|---|---|
| Push button | | | |
| Touch sensor | | | |
| LDR | | | |
| HC-SR04 | | | |
| PIR | | | |
| Soil moisture | | | |
| Sound sensor | | | |
| Flame sensor | | | |

## Part G - Build challenges

### Challenge 1: Visitor Alert System

**Objective:** Build a system that detects a person and alerts with buzzer and LED.

Sensors used: _________________________________________________________

Outputs used: _________________________________________________________

Describe how it works:

____________________________________________________________________

____________________________________________________________________

Did it work on the first try? If not, what did you fix?

____________________________________________________________________

### Challenge 2: Smart Street Light

**Objective:** Build a light that automatically turns on in darkness.

Threshold value used: ____________

How did you determine this value?

____________________________________________________________________

### Challenge 3: Smart Classroom (team challenge)

**Objective:** Design a sensor system for your classroom.

Problem your system solves: __________________________________________

Sensors used (at least 2): ____________________________________________

Outputs used (at least 2): ____________________________________________

Describe the system behavior:

____________________________________________________________________

____________________________________________________________________

____________________________________________________________________

Draw your circuit layout:

```text



```

## Part H - Reflection

### 1. Which sensor was most interesting to you? Why?

____________________________________________________________________

____________________________________________________________________

### 2. Name one real-world application you'd like to build with sensors.

____________________________________________________________________

### 3. What was the most challenging part of today's session?

____________________________________________________________________
