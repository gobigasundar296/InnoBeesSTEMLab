# Teacher Guide: Electricity, Electronics and Arduino Foundations

## Why this module comes first

Students can copy a wiring picture without understanding it. That produces a
working project once, but it does not produce an independent maker. This
module teaches students to answer four questions:

1. Where does electrical energy come from?
2. What path will current follow?
3. What value protects each component?
4. How can we measure whether our prediction is correct?

Arduino is introduced only after students can build, calculate, and test a
basic circuit.

## Recommended delivery

### Block 1 - Electricity and components (120 minutes)

- Technology ice breaker: 10 minutes
- Electricity versus electronics: 20 minutes
- Voltage, current, resistance and Ohm's law: 25 minutes
- LED and RGB LED: 20 minutes
- Breadboard internal connections: 25 minutes
- Build Practical Circuit 1: 20 minutes

### Block 2 - Circuit types and calculations (120 minutes)

- Review and prediction quiz: 10 minutes
- Open and closed circuits: 20 minutes
- Series and parallel circuits: 25 minutes
- Resistor calculation and standard values: 30 minutes
- Build Practical Circuits 2-5: 35 minutes

### Block 3 - Inputs, sound and measurement (120 minutes)

- Buttons and pull-up idea: 20 minutes
- Active and passive buzzers: 15 minutes
- Build Practical Circuits 6-8: 35 minutes
- Multimeter modes and probe sockets: 20 minutes
- Measurement stations: 30 minutes

### Block 4 - Arduino and sequential lights (120 minutes)

- Arduino external pin map: 20 minutes
- Arduino internal functional blocks: 15 minutes
- `setup()`, `loop()`, `pinMode()` and `digitalWrite()`: 20 minutes
- Build Practical Circuits 9-10: 25 minutes
- Upload blink and sequential-light programs: 30 minutes
- Debugging and presentation: 10 minutes

## Teaching method

Use the same five-step routine for every circuit:

1. **Predict:** What should happen, and why?
2. **Calculate:** What resistor or setting is required?
3. **Build:** Wire the circuit with power disconnected.
4. **Check:** Trace every connection from power to ground.
5. **Measure:** Power the circuit and compare measurements with predictions.

## Required demonstrations

### Current needs a complete path

Build a working LED circuit. Remove one jumper to create an open circuit.
Students should describe the difference before using the words open and
closed.

### Breadboard hidden connections

With power disconnected, use continuity mode to test:

- two holes in the same group of five;
- holes across the center channel;
- two holes on one power rail;
- two holes on opposite sides of a split power rail.

### One resistor per parallel LED branch

Show two LEDs in parallel with separate resistors. Explain that LED forward
voltage is not identical, even for LEDs that look the same. A shared resistor
does not guarantee safe or equal branch current.

### Correct voltage and current measurement

Connect a voltmeter across an LED. Then disconnect one wire and insert the
ammeter in series. Emphasize that these are different physical connections.

## Safety briefing

Before each lab, students repeat:

> Power off to build. Check the path. Choose the meter mode. Power on to test.

Teacher checks:

- Supply is 5 V from Arduino USB or a regulated 5 V source.
- Every LED branch contains a resistor.
- No component or bare jumper bridges 5 V directly to GND.
- Meter lead is returned from the high-current socket to the voltage/resistance
  socket after current measurement.
- Buzzers used for direct Arduino connection have been measured or documented
  below 20 mA.

## Assessment evidence

Students should be able to:

- explain electricity and electronics in their own words;
- use the water-flow analogy without treating it as a perfect model;
- rearrange `V = I x R` to find voltage, current, or resistance;
- identify anode and cathode on a standard LED;
- explain the purpose of all three current-limiting resistors on an RGB LED;
- map a breadboard row and rail using continuity mode;
- classify a circuit as open, closed, series, or parallel;
- calculate a safe LED resistor and choose the next higher common value;
- connect a multimeter correctly for resistance, voltage, and current;
- identify Arduino digital, PWM, analog, power, communication, and reset pins;
- upload and modify an LED sequence;
- debug by checking one possible fault at a time.

## Common misconceptions to correct

- **Voltage flows.** Voltage is electrical potential difference; current flows.
- **The battery sends a fixed current.** The source provides voltage, while
  circuit resistance and component behavior determine current.
- **A resistor uses up current.** Current is equal through a simple series
  path; the resistor produces a voltage drop and limits the circuit current.
- **LEDs are small lamps.** LEDs are diodes with polarity and a nonlinear
  current-voltage relationship.
- **All breadboard holes are connected.** Only specific groups are connected.
- **Parallel LEDs can share one resistor.** Each branch should have its own
  resistor.
- **The Arduino pin is a power supply.** It is a logic I/O pin with limited
  current capability.
- **Serial lights means LEDs are electrically in series.** In this module,
  sequential or running lights are separately wired LEDs switched one after
  another by software.

## Suggested team roles

- **Circuit designer:** reads and explains the diagram.
- **Builder:** places components and wires.
- **Safety checker:** traces 5 V to GND before power is connected.
- **Measurement engineer:** selects multimeter mode and records results.
- **Programmer:** uploads and changes the Arduino sketch.

Rotate roles after every two practical circuits.

## Final challenge

Teams design an alert panel with:

- at least three separately controlled LEDs;
- one button input;
- one buzzer output;
- a written resistor calculation;
- a breadboard diagram;
- an Arduino sequence containing at least two timing values.

Students must explain the circuit path and demonstrate one measurement before
presenting the program.
