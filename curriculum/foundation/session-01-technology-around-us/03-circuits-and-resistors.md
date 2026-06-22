# Chapter 3: Circuit Types and Resistor Calculations

## What is a circuit?

A circuit is a path through which electric current can flow. A basic circuit
contains:

- an energy source;
- conducting wires or breadboard connections;
- one or more loads, such as an LED or buzzer;
- a return path to the source.

## Open circuit

An open circuit has a break in its path. Current cannot complete the loop.

Examples:

- switch released;
- disconnected jumper;
- LED leg placed in the wrong breadboard row;
- broken wire.

The supply voltage can still exist even though the current is zero.

## Closed circuit

A closed circuit has a complete path. Current can flow from the source,
through the components, and back to the source.

A closed circuit is not automatically safe. A direct 5 V-to-GND wire is a
closed path with very low resistance: a **short circuit**.

## Series circuit

Components are in series when the same current must pass through them one
after another along a single path.

```text
5 V -> resistor -> LED 1 -> LED 2 -> GND
```

Properties:

- current is the same through every component;
- voltage drops add to the supply voltage;
- resistances add:

```text
R_total = R1 + R2 + R3 + ...
```

- opening any point stops the whole circuit.

## Parallel circuit

Components are in parallel when they are connected across the same two nodes,
creating multiple current paths.

Properties:

- voltage is the same across every branch;
- branch currents add:

```text
I_total = I1 + I2 + I3 + ...
```

- one open branch does not necessarily stop the others;
- equivalent resistance is:

```text
1 / R_total = 1 / R1 + 1 / R2 + ...
```

For two resistors:

```text
R_total = (R1 x R2) / (R1 + R2)
```

Parallel LEDs should use one current-limiting resistor per LED branch.

See [circuit types diagram](diagrams/circuit-types.svg).

## How to calculate an LED resistor

Use:

```text
R = (V_supply - V_LED) / I_LED
```

Where:

- `V_supply` is the source or output voltage;
- `V_LED` is the approximate LED forward voltage;
- `I_LED` is the chosen LED current in amperes;
- `R` is the series resistor in ohms.

### Safe design process

1. Find the supply voltage.
2. Find or estimate the LED forward voltage.
3. Choose a conservative current. `0.010 A` or 10 mA is suitable for many
   classroom indicator LEDs.
4. Calculate resistance.
5. Choose the next higher common resistor value.
6. Calculate resistor power and select a rating with margin.

## Ten solved resistor examples

### 1. Red LED from 5 V at 10 mA

Assume `V_LED = 2.0 V`.

```text
R = (5 - 2.0) / 0.010 = 300 ohm
```

Choose the next common value: **330 ohm**.

Actual estimated current:

```text
I = (5 - 2.0) / 330 = 0.0091 A = 9.1 mA
```

### 2. Red LED from 3.3 V at 5 mA

```text
R = (3.3 - 2.0) / 0.005 = 260 ohm
```

Choose **270 ohm** or the more commonly available **330 ohm** for a dimmer,
safer result.

### 3. Blue LED from 5 V at 10 mA

Assume `V_LED = 3.2 V`.

```text
R = (5 - 3.2) / 0.010 = 180 ohm
```

Choose **220 ohm**.

### 4. Green LED from 5 V at 8 mA

Assume `V_LED = 2.2 V`.

```text
R = (5 - 2.2) / 0.008 = 350 ohm
```

Choose **390 ohm**. If only 330 ohm is available, estimated current is about
8.5 mA and is normally acceptable for a typical indicator LED after checking
its datasheet.

### 5. Two red LEDs in series from 5 V at 8 mA

```text
V_LED_total = 2.0 + 2.0 = 4.0 V
R = (5 - 4.0) / 0.008 = 125 ohm
```

Choose **150 ohm**.

### 6. Two blue LEDs in series from 5 V

Estimated LED voltage is `3.2 + 3.2 = 6.4 V`, which is greater than the 5 V
supply. There is no valid positive resistor calculation. Use a higher suitable
supply with correct design, or place the LEDs in separate parallel branches
with individual resistors.

### 7. Two red LEDs in parallel

Calculate one resistor for each branch:

```text
R_branch = (5 - 2.0) / 0.010 = 300 ohm
```

Use **two 330 ohm resistors**, one per LED.

Estimated total current:

```text
I_total = 9.1 mA + 9.1 mA = 18.2 mA
```

### 8. RGB LED red channel

Assume red forward voltage is 2.0 V and desired current is 8 mA:

```text
R_red = (5 - 2.0) / 0.008 = 375 ohm
```

Choose **390 ohm**.

### 9. RGB LED blue channel

Assume blue forward voltage is 3.2 V and desired current is 8 mA:

```text
R_blue = (5 - 3.2) / 0.008 = 225 ohm
```

Choose **270 ohm**. Using 330 ohm is also safe and makes classroom kits
simpler.

### 10. Check resistor power

For a 330 ohm resistor carrying 9.1 mA:

```text
P = I x I x R
P = 0.0091 x 0.0091 x 330
P = approximately 0.027 W
```

A standard **0.25 W resistor** provides comfortable margin.

## Combining resistors

### Series example

Two 330 ohm resistors in series:

```text
R_total = 330 + 330 = 660 ohm
```

### Parallel example

Two 330 ohm resistors in parallel:

```text
R_total = (330 x 330) / (330 + 330)
R_total = 165 ohm
```

### Make 550 ohm

Connect 220 ohm and 330 ohm in series:

```text
R_total = 220 + 330 = 550 ohm
```

## Choosing a standard value

When a calculation gives a value such as 300 ohm:

- select 330 ohm if it is the next common value;
- a higher value gives lower current and usually lower brightness;
- do not select a lower value unless the new current has been calculated and
  checked against the LED and controller limits.

## Measurement versus calculation

Calculations use typical LED forward voltage. Real components vary. After
building:

1. Measure supply voltage.
2. Measure voltage across the LED.
3. Measure voltage across the resistor.
4. Calculate current using `I = V_resistor / R`.
5. If required, measure current directly by inserting the meter in series.

Small differences between prediction and measurement are normal because of
component tolerance, LED variation, and meter accuracy.
