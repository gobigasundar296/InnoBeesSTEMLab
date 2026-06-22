# Chapter 1: What Are Electricity and Electronics?

## Electricity

Electricity is the movement or presence of electric charge. In a simple
battery circuit, chemical energy in the battery creates an electrical
potential difference. When a complete conducting path is connected, charge
moves through the circuit and electrical energy can be converted into light,
sound, heat, or motion.

Electricity exists in nature and technology:

- lightning is a large electrical discharge;
- static electricity can make hair stand up;
- a battery creates a DC voltage;
- a wall socket supplies dangerous AC voltage;
- nerves use electrochemical signals.

This course uses only safe, low-voltage DC circuits. Students must never
experiment with wall electricity.

## Electronics

Electronics is the use of components and circuits to control electrical
energy and information. Electronic systems can sense, decide, communicate,
and act.

Examples:

| System | Input | Electronic processing | Output |
|---|---|---|---|
| Automatic night light | Light level | Compares level with a threshold | Lamp turns on |
| School bell | Time | Controller checks schedule | Buzzer or speaker sounds |
| Television remote | Button press | Encodes a command | Infrared signal |
| Smartphone | Touch, microphone, camera | Processor runs software | Screen, sound, radio signal |
| Robot | Distance sensor | Microcontroller follows code | Motors change direction |

Electricity supplies the energy. Electronics controls what that energy does.

## Four important electrical quantities

### Voltage - V

Voltage is electrical potential difference. It provides the push that can
move charge through a circuit.

- Symbol: `V`
- Unit: volt
- Measured across two points
- Practical example: a USB-powered Arduino uses 5 V logic

Water analogy: voltage is similar to pressure difference. It is not water and
it does not flow, but greater pressure difference can drive more flow.

### Current - I

Current is the rate of flow of electric charge.

- Symbol: `I`
- Unit: ampere or amp
- `1 A = 1000 mA`
- Measured through a path, so an ammeter is connected in series

Practical example: a beginner LED may be designed for approximately 5-15 mA.
Arduino Uno R3 circuits in this module are kept at or below 20 mA per I/O pin.

### Resistance - R

Resistance is opposition to current.

- Symbol: `R`
- Unit: ohm
- `1000 ohm = 1 kilohm`
- A resistor can limit current and divide voltage.

Practical example: an LED connected to 5 V usually needs a resistor such as
220 ohm or 330 ohm.

### Power - P

Power is the rate at which electrical energy is transferred.

```text
P = V x I
```

Power is measured in watts. A resistor must have a sufficient power rating.
Most low-current LED examples are safe with a common 0.25 W resistor.

## Ohm's law

For an ohmic resistor:

```text
V = I x R
I = V / R
R = V / I
```

The triangle memory aid:

```text
       V
     -----
      I R
```

Cover the quantity you need:

- Cover `V`: multiply `I x R`.
- Cover `I`: divide `V / R`.
- Cover `R`: divide `V / I`.

## Practical examples

### Example 1: Find current

A 5 V supply is connected across a 1000 ohm resistor.

```text
I = V / R
I = 5 / 1000
I = 0.005 A = 5 mA
```

### Example 2: Find resistance

We want 10 mA from a 3 V voltage drop.

```text
R = V / I
R = 3 / 0.010
R = 300 ohm
```

### Example 3: Find voltage

Current through a 220 ohm resistor is 10 mA.

```text
V = I x R
V = 0.010 x 220
V = 2.2 V
```

### Example 4: Calculate power

A 330 ohm resistor drops 3 V.

```text
I = 3 / 330 = 0.0091 A
P = V x I = 3 x 0.0091 = 0.0273 W
```

A 0.25 W resistor has plenty of margin for this example.

## Important limitation

An LED is not an ohmic resistor. Its resistance is not constant, so we do not
connect it directly to a voltage source and apply `I = V / R` to the LED
alone. Instead, we use the LED's approximate forward voltage and calculate a
series resistor:

```text
R = (supply voltage - LED forward voltage) / desired LED current
```

This calculation is developed fully in
[Chapter 3](03-circuits-and-resistors.md).
