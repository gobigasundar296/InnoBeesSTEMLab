# Chapter 6: Servo Motor Control

## What is a servo motor?

A servo motor is a motor that can rotate to a **specific angle** and hold
that position. Unlike a regular DC motor that spins continuously, a servo
moves to a commanded angle (typically 0° to 180°) and stays there.

## How it works

Inside a servo motor:

1. **DC motor:** Provides the rotational force.
2. **Gear train:** Reduces speed but increases torque (strength).
3. **Position sensor (potentiometer):** Tells the control circuit the current
   angle.
4. **Control circuit:** Compares the commanded angle with the actual angle
   and adjusts the motor.

This creates a feedback loop — the servo always knows where it is and
corrects itself.

## Servo signal

The servo is controlled by a PWM signal:

- Signal frequency: 50 Hz (one pulse every 20 ms).
- Pulse width determines angle:
  - ~1 ms pulse = 0°
  - ~1.5 ms pulse = 90° (center)
  - ~2 ms pulse = 180°

Arduino's Servo library handles this automatically.

## SG90 micro servo specifications

| Parameter | Value |
|---|---|
| Operating voltage | 4.8-6 V |
| Rotation range | 0° to 180° |
| Speed | ~0.1 s per 60° |
| Torque | ~1.8 kg·cm |
| Weight | ~9 g |

## Connections

The SG90 servo has three wires:

| Wire color | Connects to |
|---|---|
| Brown/Black | GND |
| Red | 5V |
| Orange/Yellow | Signal → Arduino PWM pin (e.g., D9) |

**Power note:** For a single SG90, powering from the Arduino 5V pin is
usually acceptable for testing. For multiple servos or heavy loads, use an
external 5V power supply with common GND.

## Arduino Servo library

```cpp
#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);  // signal wire on D9
}

void loop() {
  myServo.write(0);    // go to 0 degrees
  delay(1000);
  myServo.write(90);   // go to 90 degrees
  delay(1000);
  myServo.write(180);  // go to 180 degrees
  delay(1000);
}
```

## Key Servo functions

| Function | What it does |
|---|---|
| `myServo.attach(pin)` | Connect servo signal to a pin |
| `myServo.write(angle)` | Move to angle (0-180) |
| `myServo.read()` | Get the last written angle |
| `myServo.detach()` | Disconnect (stops holding position) |

## Controlling servo from Serial Monitor

```cpp
#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Enter angle (0-180):");
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Moving to: ");
      Serial.print(angle);
      Serial.println(" degrees");
    }
  }
}
```

## Smooth servo movement

Instead of jumping to an angle, move gradually:

```cpp
void smoothMove(int targetAngle) {
  int currentAngle = myServo.read();
  if (currentAngle < targetAngle) {
    for (int a = currentAngle; a <= targetAngle; a++) {
      myServo.write(a);
      delay(15);
    }
  } else {
    for (int a = currentAngle; a >= targetAngle; a--) {
      myServo.write(a);
      delay(15);
    }
  }
}
```

## Practical applications

| Application | Servo action |
|---|---|
| Automatic gate | 0° = closed, 90° = open |
| Robot arm joint | Variable angles for positioning |
| Radar/scanner | Sweep 0°-180° continuously |
| Bin lid opener | 0° = closed, 45° = open |
| Traffic barrier | 0° = down, 90° = up |

## Combining servo with sensors

```cpp
// Ultrasonic-controlled gate: opens when someone is near
#include <Servo.h>

Servo gate;
const int TRIG = 9;
const int ECHO = 10;

void setup() {
  gate.attach(6);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  gate.write(0);  // start closed
}

void loop() {
  float dist = getDistance();
  if (dist > 0 && dist < 30) {
    gate.write(90);  // open
  } else {
    gate.write(0);   // closed
  }
  delay(200);
}
```

## Safety notes

- Do not force the servo shaft beyond its range.
- Do not block the servo from moving — this draws excessive current and can
  damage the motor or Arduino.
- If the servo jitters at rest, try a different power source or add a
  capacitor across the power lines.
