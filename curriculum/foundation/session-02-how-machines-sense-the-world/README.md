# Session 2: How Machines Sense the World

This module introduces students to the concept of sensors — how electronic
systems detect changes in the physical environment. Students learn the
working principles of common sensors and build Arduino-based projects that
respond to touch, light, distance, motion, and more.

**Audience:** Classes 6-9  
**Duration:** 2 hours (extendable to 4 hours with all activities)  
**Learning cycle:** Explore → Understand → Build → Code → Challenge → Present

## What students learn

1. What a sensor is and how it converts physical quantities to electrical signals.
2. How a push button and touch sensor work as digital inputs.
3. How an LDR measures light intensity using resistance change.
4. How an ultrasonic sensor measures distance using sound waves.
5. How a PIR sensor detects motion using infrared radiation.
6. How soil moisture, sound, and flame sensors work.
7. How to connect sensors to Arduino and read their values.
8. How to use `digitalRead()` and `analogRead()` in Arduino programs.
9. How to use Serial Monitor to observe sensor data.
10. How to combine sensors to build smart systems.

## Learning documents

- [Teacher guide and delivery plan](teacher-guide.md)
- [Chapter 1: What are sensors?](01-what-are-sensors.md)
- [Chapter 2: Digital sensors — buttons and touch](02-digital-sensors.md)
- [Chapter 3: Analog sensors — LDR and soil moisture](03-analog-sensors.md)
- [Chapter 4: Distance and motion — ultrasonic and PIR](04-distance-and-motion-sensors.md)
- [Chapter 5: Sound and flame sensors](05-sound-and-flame-sensors.md)
- [Chapter 6: Arduino sensor programs](06-arduino-sensor-programs.md)
- [Student workbook](student-workbook.md)
- [Teacher answer key](teacher-answer-key.md)

## Arduino programs

- [Button LED control](arduino/01_button_led_control/01_button_led_control.ino)
- [Touch sensor LED](arduino/02_touch_sensor_led/02_touch_sensor_led.ino)
- [LDR smart street light](arduino/03_ldr_street_light/03_ldr_street_light.ino)
- [Ultrasonic distance meter](arduino/04_ultrasonic_distance/04_ultrasonic_distance.ino)
- [PIR visitor alert](arduino/05_pir_visitor_alert/05_pir_visitor_alert.ino)
- [Multi-sensor smart classroom](arduino/06_smart_classroom/06_smart_classroom.ino)

## Core Path for a two-hour class

If only two hours are available, teach:

1. What sensors are and the input-process-output model.
2. Push button with `digitalRead()`.
3. LDR with `analogRead()` and Serial Monitor.
4. Ultrasonic distance measurement.
5. Hands-on: Visitor Alert system (PIR + buzzer).
6. Hands-on: Smart Street Light (LDR + LED).

The remaining sensors and the Smart Classroom challenge continue in extended
time or as homework design.

## Equipment per team

- Arduino Uno R3 and USB data cable
- Breadboard and jumper wires
- Push button (tactile switch)
- Touch sensor module (TTP223 or similar)
- LDR (light-dependent resistor) and 10 kilohm resistor
- HC-SR04 ultrasonic sensor
- HC-SR501 PIR motion sensor
- Soil moisture sensor module
- Sound sensor module (KY-038 or similar)
- Flame sensor module (KY-026 or similar)
- LEDs (red, green, yellow) and 330 ohm resistors
- Active buzzer
- Multimeter
