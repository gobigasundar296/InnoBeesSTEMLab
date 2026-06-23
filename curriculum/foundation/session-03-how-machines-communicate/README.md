# Session 3: How Machines Communicate

This module teaches students how electronic systems communicate information
to humans through visual displays, sound, and motion. Students learn to
control LEDs, RGB LEDs, LCD displays, 7-segment displays, buzzers, and
servo motors using Arduino.

**Audience:** Classes 6-9  
**Duration:** 2 hours (extendable to 4 hours with all activities)  
**Learning cycle:** Explore → Understand → Build → Code → Challenge → Present

## What students learn

1. The difference between input devices (sensors) and output devices (actuators).
2. How RGB LEDs create colors through mixing.
3. How an LCD display shows text using the I2C interface.
4. How a 7-segment display represents numbers.
5. How buzzers create alert sounds and melodies.
6. How a servo motor rotates to a specific angle.
7. How to use `analogWrite()` (PWM) to control brightness and speed.
8. How to use the LiquidCrystal_I2C library for LCD control.
9. How to combine outputs to create meaningful systems.
10. How to design a complete output system for a given scenario.

## Learning documents

- [Teacher guide and delivery plan](teacher-guide.md)
- [Chapter 1: Output devices — how machines talk back](01-output-devices-overview.md)
- [Chapter 2: RGB LED color mixing and PWM](02-rgb-led-and-pwm.md)
- [Chapter 3: LCD display with I2C](03-lcd-display.md)
- [Chapter 4: 7-segment display](04-seven-segment-display.md)
- [Chapter 5: Buzzer sounds and melodies](05-buzzer-sounds.md)
- [Chapter 6: Servo motor control](06-servo-motor.md)
- [Student workbook](student-workbook.md)
- [Teacher answer key](teacher-answer-key.md)

## Arduino programs

- [RGB LED color mixer](arduino/01_rgb_color_mixer/01_rgb_color_mixer.ino)
- [LCD welcome display](arduino/02_lcd_welcome_display/02_lcd_welcome_display.ino)
- [7-segment counter](arduino/03_seven_segment_counter/03_seven_segment_counter.ino)
- [Traffic signal system](arduino/04_traffic_signal/04_traffic_signal.ino)
- [Buzzer melody player](arduino/05_buzzer_melody/05_buzzer_melody.ino)
- [Servo angle control](arduino/06_servo_control/06_servo_control.ino)

## Core Path for a two-hour class

If only two hours are available, teach:

1. Output devices overview and Input vs. Output concept.
2. RGB LED color mixing with PWM (`analogWrite`).
3. LCD display: show a welcome message.
4. Traffic Signal with three LEDs and timing.
5. Buzzer alert sound.
6. Servo motor angle control from Serial Monitor.

The 7-segment counter, melodies, and Smart Classroom Display challenge
continue in extended time.

## Equipment per team

- Arduino Uno R3 and USB data cable
- Breadboard and jumper wires
- RGB LED (common cathode) and 330 ohm resistors (x3)
- Standard LEDs: red, yellow, green and 330 ohm resistors
- 16x2 LCD display with I2C backpack module
- Common cathode 7-segment display and 330 ohm resistors (x7)
- Active buzzer
- Passive buzzer
- SG90 micro servo motor
- Potentiometer (10 kilohm)
- Multimeter
