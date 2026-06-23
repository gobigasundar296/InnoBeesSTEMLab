# Teacher Guide: How Machines Sense the World

## Why this module matters

Sensors are the bridge between the physical world and digital systems. Without
sensors, a microcontroller has no awareness of its environment. This session
transforms students from circuit builders into system designers who can make
machines respond intelligently to the real world.

## Recommended delivery

### Block 1 - Understanding sensors (50 minutes)

- Ice breaker — "Five senses challenge": 10 minutes
- What is a sensor and the Input-Process-Output model: 15 minutes
- Digital vs. analog sensor signals: 10 minutes
- Push button with pull-up resistor: 15 minutes

### Block 2 - Hands-on sensing (70 minutes)

- Touch sensor module demonstration: 10 minutes
- LDR and voltage divider circuit: 15 minutes
- Hands-on: Smart Street Light build and code: 20 minutes
- Ultrasonic sensor demonstration and distance display: 15 minutes
- Hands-on: Visitor Alert with PIR: 10 minutes

### Extended Block (optional 60 minutes)

- Sound and flame sensor demonstrations: 15 minutes
- Multi-sensor Smart Classroom challenge: 30 minutes
- Presentations and debugging: 15 minutes

## Teaching method

Use the same routine for each sensor:

1. **Show:** Present the physical sensor module. Students identify pins.
2. **Explain:** How does it detect the physical quantity?
3. **Connect:** Wire it to Arduino with guidance.
4. **Observe:** Use Serial Monitor to see live data.
5. **Apply:** Add logic to control an output based on the sensor reading.

## Ice breaker: Five Senses Challenge (10 minutes)

1. Blindfold a volunteer. Ask them to identify objects by touch.
2. Ask: "How do our senses help us understand the world?"
3. Connect: "Electronic sensors do the same job for machines."
4. Show a collection of sensor modules and ask students to guess what each
   might detect.

## Key demonstrations

### Push button floating pin

1. Connect a button between D2 and 5V with NO resistor.
2. Open Serial Monitor and print `digitalRead(2)`.
3. Show that unpressed readings are random (floating).
4. Add a 10k pull-down resistor to GND. Now unpressed reads 0 reliably.
5. Alternatively, use `INPUT_PULLUP` and connect button to GND.

### LDR live readings

1. Connect LDR voltage divider circuit.
2. Open Serial Monitor to show live values.
3. Cover the LDR with a hand — values drop.
4. Shine a phone flashlight — values rise.
5. Ask students to find the threshold value for their specific LDR.

### Ultrasonic distance

1. Connect HC-SR04 and run the distance program.
2. Place a book at various measured distances (use a ruler).
3. Compare the sensor reading with the actual distance.
4. Discuss accuracy and when readings might be unreliable.

### PIR motion detection

1. Power up and wait 30-60 seconds for warm-up.
2. Have a student walk past — output triggers.
3. Have a student stand completely still — no re-trigger.
4. Explain: PIR detects *change* in infrared, not presence.

## Common misconceptions to correct

- **Sensors measure exact values.** All sensors have tolerances and noise.
  Teach students to use ranges and thresholds, not exact numbers.
- **Digital means better than analog.** They serve different purposes.
  Digital gives yes/no; analog gives how much.
- **The Arduino "knows" what the sensor measures.** The Arduino only reads a
  voltage or logic level. The programmer's code interprets the meaning.
- **PIR detects people.** PIR detects infrared radiation changes from any
  warm moving object, including animals and heat sources.
- **Ultrasonic sensor uses light.** It uses sound waves above human hearing.

## Safety briefing

Before the lab, students confirm:

> I will check sensor voltage ratings. I will not touch powered circuits.
> I will use Serial Monitor to observe before adding outputs.

Teacher checks:

- All sensor modules are rated for 5 V operation.
- PIR warm-up time is allocated before testing.
- No open flames for flame sensor testing — use IR LED or remote control.
- Ultrasonic sensors are not pointed directly at ears.

## Assessment evidence

Students should be able to:

- explain the difference between a digital and analog sensor;
- describe the Input-Process-Output model with an example;
- connect a push button with a pull-up or pull-down resistor;
- read an LDR value and explain what the number means;
- explain how ultrasonic distance measurement works;
- identify what a PIR sensor detects and its limitations;
- set a threshold value based on Serial Monitor observations;
- write a simple Arduino program that reads a sensor and controls an output.

## Suggested team roles

- **Sensor specialist:** identifies pins and explains how the sensor works.
- **Circuit builder:** connects the sensor to the breadboard and Arduino.
- **Programmer:** writes and uploads the Arduino sketch.
- **Data analyst:** uses Serial Monitor to find threshold values.
- **Presenter:** explains the team's system to the class.

Rotate roles between the Street Light and Visitor Alert activities.

## Final challenge: Smart Classroom Sensor System

Teams design a sensor system for their classroom that includes:

- at least two different sensors;
- at least two different outputs (LED, buzzer, Serial message);
- clear threshold values justified by Serial Monitor observations;
- a written description of what the system does;
- a demonstration to the class.

Example ideas:

- Auto-light that turns on when dark AND someone is present.
- Noise monitor that warns when the classroom is too loud.
- Door alert when someone enters.
- Occupancy indicator for a study room.
