# Session 5: Bringing Machines to Life

This module teaches students how machines create physical motion. Students
learn the working principles of different motor types, how motor drivers
amplify Arduino's limited output, and build projects that move, spin, and
respond to sensor inputs.

**Audience:** Classes 6-9  
**Duration:** 2 hours (extendable to 4 hours with all activities)  
**Learning cycle:** Explore → Understand → Build → Code → Challenge → Present

## What students learn

1. Why Arduino cannot drive motors directly from I/O pins.
2. How servo motors rotate to precise angles (review from Session 3).
3. How DC motors provide continuous rotation.
4. How gear motors trade speed for torque.
5. How an H-bridge motor driver controls direction and speed.
6. How the L298N and L293D motor driver modules work.
7. How PWM controls motor speed smoothly.
8. How to combine sensors with motors for automatic systems.
9. How to build an automatic gate using servo + ultrasonic sensor.
10. How to build a smart fan controller using DC motor + temperature/LDR.

## Learning documents

- [Teacher guide and delivery plan](teacher-guide.md)
- [Chapter 1: Why motors need drivers](01-why-motors-need-drivers.md)
- [Chapter 2: Servo motors — precision positioning](02-servo-motors.md)
- [Chapter 3: DC motors and gear motors](03-dc-and-gear-motors.md)
- [Chapter 4: H-bridge and motor driver modules](04-motor-drivers.md)
- [Chapter 5: Speed control with PWM](05-pwm-speed-control.md)
- [Chapter 6: Motor projects with sensors](06-motor-projects.md)
- [Student workbook](student-workbook.md)
- [Teacher answer key](teacher-answer-key.md)

## Image illustrations

- [Editable SVG diagram index](circuits/README.md)

## Arduino programs

- [Servo sweep and positions](arduino/01_servo_sweep/01_servo_sweep.ino)
- [DC motor basic control](arduino/02_dc_motor_basic/02_dc_motor_basic.ino)
- [DC motor speed control (PWM)](arduino/03_dc_motor_speed/03_dc_motor_speed.ino)
- [Automatic gate (ultrasonic + servo)](arduino/04_automatic_gate/04_automatic_gate.ino)
- [Smart fan controller](arduino/05_smart_fan/05_smart_fan.ino)
- [Motor direction and speed from Serial](arduino/06_motor_serial_control/06_motor_serial_control.ino)

## Core Path for a two-hour class

If only two hours are available, teach:

1. Why motors need drivers — current and voltage limitations.
2. Servo motor review and multi-position control.
3. DC motor with L298N driver — direction and speed.
4. Hands-on: Automatic Gate (ultrasonic + servo).
5. Hands-on: Smart Fan Controller (LDR or pot + DC motor).
6. Challenge discussion: Design a Motion-Based Solution.

The gear motor details, advanced PWM, and full challenge build continue
in extended time.

## Equipment per team

- Arduino Uno R3 and USB data cable
- Breadboard and jumper wires
- SG90 micro servo motor
- Small DC motor (3-6V)
- DC gear motor (optional, for demonstration)
- L298N motor driver module (or L293D IC)
- 9V battery with clip (or 4xAA battery holder)
- HC-SR04 ultrasonic sensor
- LDR and 10 kilohm resistor
- Potentiometer (10 kilohm)
- LEDs (for status indication) and 330 ohm resistors
- Diodes (1N4007) for back-EMF protection (if using L293D)
- Small fan blade (attaches to DC motor shaft)
- Multimeter
