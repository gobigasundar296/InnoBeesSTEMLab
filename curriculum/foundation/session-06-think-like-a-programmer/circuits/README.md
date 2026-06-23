# Session 6: Circuit Diagrams

## Planned diagrams

The following circuit diagrams are needed for Session 6 programs:

### 1. Traffic light timer
- 3 LEDs (red, yellow, green) each with 330 ohm resistors
- Connected to pins 4, 3, 2

### 2. Temperature alarm
- Potentiometer on A0 (simulating temperature sensor)
- 4 LEDs (blue, green, yellow, red) with 330 ohm resistors on pins 2-5
- Buzzer on pin 6

### 3. Pattern generator
- 4 LEDs with 330 ohm resistors
- Connected to pins 2, 3, 4, 5

### 4. Reaction time game
- 1 LED with 330 ohm resistor on pin 8
- Push button on pin 2 (INPUT_PULLUP)
- Buzzer on pin 6

### 5. Password lock
- Green LED on pin 3, Red LED on pin 4 (each with 330 ohm resistor)
- Buzzer on pin 5
- Servo on pin 9
- Serial Monitor for input (no additional wiring for keyboard)

### 6. Debug challenge (smart nightlight)
- LDR with 10k resistor (voltage divider) on A0
- LED on pin 9 (PWM capable) with 330 ohm resistor
- Push button on pin 2 (INPUT_PULLUP)

## Notes

- All circuits use Arduino Uno R3 with USB power.
- All LEDs require 330 ohm current-limiting resistors.
- Buttons use internal pull-up (INPUT_PULLUP) — connect button between
  pin and GND.
- Diagrams can be generated with Fritzing or Tinkercad Circuits.
