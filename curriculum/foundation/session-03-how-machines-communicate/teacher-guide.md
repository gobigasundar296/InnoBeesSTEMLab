# Teacher Guide: How Machines Communicate

## Why this module matters

In Session 2, students learned how machines sense the world. Now they learn
the other half — how machines communicate their findings back to humans
through displays, sounds, and motion. This completes the Input-Process-Output
model and enables students to build complete interactive systems.

## Recommended delivery

### Block 1 - Visual and audio outputs (60 minutes)

- Review: Input-Process-Output model: 5 minutes
- Output devices overview — what is an actuator?: 10 minutes
- RGB LED color mixing and PWM demonstration: 15 minutes
- Hands-on: RGB color mixer program: 15 minutes
- Buzzer types and alert patterns: 15 minutes

### Block 2 - Displays and motion (60 minutes)

- LCD display with I2C — wiring and first message: 15 minutes
- Hands-on: Welcome display with sensor data: 15 minutes
- Traffic Signal with three LEDs: 15 minutes
- Servo motor: angle control from Serial Monitor: 15 minutes

### Extended Block (optional 60 minutes)

- 7-segment display counter: 15 minutes
- Buzzer melody programming: 15 minutes
- Challenge: Smart Classroom Display System: 30 minutes

## Teaching method

For each output device:

1. **Show:** Display the component. Students predict what it does.
2. **Explain:** How does it work internally?
3. **Connect:** Wire it to Arduino with guidance.
4. **Control:** Write code to make it respond.
5. **Integrate:** Combine with a sensor input for a complete system.

## Key demonstrations

### PWM brightness control

1. Connect an LED to a PWM pin (D9).
2. Use `analogWrite(9, 0)` — LED off.
3. Gradually increase: 50, 100, 150, 200, 255.
4. Students observe smooth brightness change.
5. Explain: PWM switches rapidly; eyes see average brightness.

### RGB color prediction

1. Ask students to predict: "What color do red + green make?"
2. Set `analogWrite` for red and green at 255, blue at 0.
3. Show the result (yellow). Compare with paint mixing (subtractive vs.
   additive color).
4. Let students experiment with their own color combinations.

### LCD display

1. Show the I2C backpack — explain why 2 wires beats 6 wires.
2. Connect and display "Hello World!"
3. Show cursor positioning: `setCursor(col, row)`.
4. Display a live sensor reading that updates.
5. Common issue: If blank, adjust the contrast pot on the backpack.

### Servo movement

1. Attach servo and move to 0°, 90°, 180°.
2. Students observe the position holding.
3. Explain the feedback loop inside.
4. Let students control from Serial Monitor — type an angle, servo moves.
5. Build a simple automatic gate (sensor triggers servo open).

## Common misconceptions to correct

- **PWM is analog voltage.** PWM rapidly switches between 0V and 5V. The
  average effect looks like a lower voltage, but it's still digital switching.
- **Active and passive buzzers are the same.** Active has a built-in
  oscillator (fixed tone with DC). Passive needs a frequency signal (can
  play notes).
- **LCD shows graphics like a phone screen.** A 16x2 LCD shows only text
  characters. For graphics, use OLED or TFT displays.
- **Servo motors spin continuously.** Standard servos move to an angle and
  hold. Continuous rotation servos exist but are different.
- **More LEDs in the RGB = brighter white.** White is achieved by mixing
  all three at full brightness, not by adding more LEDs.

## Safety briefing

Before the lab, students confirm:

> I will check PWM pin numbers carefully. I will not force servo movement
> by hand. I will disconnect power before rewiring.

Teacher checks:

- RGB LED resistors are present on all three channels.
- LCD I2C connections are on A4/A5 (not other analog pins).
- Servo is not mechanically blocked.
- Buzzer current does not exceed 20 mA if directly on Arduino pin.

## Assessment evidence

Students should be able to:

- explain the difference between digital output and PWM;
- create a specific color using RGB values;
- display text on an LCD using I2C;
- explain why I2C uses fewer wires;
- program a traffic light sequence with correct timing;
- use `tone()` to play a note at a specific frequency;
- move a servo to a specific angle with code;
- combine a sensor input with an output device in a complete system.

## Suggested team roles

- **Designer:** plans the output behavior and timing.
- **Builder:** connects the output devices to the breadboard.
- **Programmer:** writes the Arduino sketch.
- **Tester:** verifies output matches the design specification.
- **Presenter:** explains the system to the class.

Rotate roles between the Traffic Signal and Welcome Display activities.

## Final challenge: Smart Classroom Display System

Teams design an output system for their classroom that includes:

- at least one visual display (LCD or 7-segment or RGB LED);
- at least one audio output (buzzer alert);
- at least one motion output (servo);
- connected to at least one sensor (from Session 2);
- a clear description of what each output communicates.

Example ideas:

- Welcome display that shows a greeting and opens a door when someone enters.
- Classroom noise level indicator with RGB LED (green=quiet, red=loud) and
  LCD showing the level.
- Digital timer with 7-segment display and buzzer alarm.
- Temperature display with overheat servo-activated fan.
