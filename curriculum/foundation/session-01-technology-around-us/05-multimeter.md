# Chapter 5: How to Use a Digital Multimeter

A multimeter can measure several electrical quantities. The exact controls
vary, so inspect the labels on the classroom meter before use.

See the [multimeter connection guide](diagrams/multimeter-guide.svg).

## Probe sockets

Most meters have:

- **COM:** black probe for all normal measurements;
- **V/ohm/mA:** red probe for voltage, resistance, continuity, diode test, and
  low current within the socket's fuse rating;
- **10 A or high-current socket:** red probe only for the specified high-current
  range and duration.

Return the red lead to the V/ohm socket after current measurement. This habit
prevents an accidental short during the next voltage test.

## Measure resistance

1. Disconnect all power.
2. Isolate the resistor from parallel circuit paths; remove one leg if needed.
3. Black lead to COM and red lead to V/ohm.
4. Select resistance mode and a suitable range.
5. Place one probe on each resistor lead.
6. Read the value and unit: ohm, kilohm, or megohm.

Do not measure resistance on a powered circuit.

## Test continuity

1. Disconnect power.
2. Select continuity mode.
3. Touch probes together to confirm the meter responds.
4. Place probes across the path being tested.
5. A beep or near-zero reading usually means a conducting connection.

Continuity mode is useful for:

- mapping breadboard rows and rails;
- checking a push button;
- finding a broken jumper;
- confirming a ground connection.

A beep does not prove that a circuit is wired correctly. It proves only that
the tested points have a low-resistance connection.

## Measure DC voltage

1. Power the circuit.
2. Select DC voltage, marked `V` with a straight/dashed line.
3. Choose a range above the expected voltage, or use auto-range.
4. Keep the black probe at the circuit reference, usually GND.
5. Touch the red probe to the point being measured.
6. Voltage is measured **in parallel across two points**.

Examples:

- Arduino 5 V rail to GND: approximately 5 V;
- voltage across a powered red LED: often around 2 V;
- voltage across the resistor: supply voltage minus LED voltage.

A negative value means the probes are reversed relative to the selected
reference.

## Measure DC current

Current measurement changes the circuit and carries greater risk of meter
damage.

1. Power off.
2. Estimate the expected current.
3. Move the red lead to the correct current socket if required.
4. Select DC current and begin with a safe higher range.
5. Open the circuit at the measurement point.
6. Insert the meter so current flows **through** it.
7. Power on briefly and read the result.
8. Power off before removing the meter.
9. Return the red lead to the V/ohm socket.

> Never place a meter in current mode directly between 5 V and GND. In current
> mode the meter has very low internal resistance and can create a short
> circuit.

## Test an LED with diode mode

1. Disconnect the LED from power.
2. Select diode-test mode.
3. Red probe to the suspected anode and black probe to the cathode.
4. A small LED may glow faintly, and the meter may display forward voltage.
5. Reverse the probes. The display should indicate open or over-range.

Not every meter supplies enough test voltage to light blue or white LEDs.

## Measurement lab

For Circuit 1, record:

| Measurement | Predicted | Measured |
|---|---:|---:|
| Supply voltage | 5 V | |
| LED voltage | about 2 V for red | |
| Resistor voltage | about 3 V | |
| Current calculated from resistor voltage | `V_R / 330` | |
| Current measured in series | about 9 mA | |

The voltage drops should approximately satisfy:

```text
V_supply = V_resistor + V_LED
```

## Troubleshooting readings

| Reading | Possible meaning |
|---|---|
| `OL` in resistance mode | Open path or selected range too low |
| Near 0 ohm | Direct connection, closed switch, or possible short |
| 0 V across supply | Power missing, wrong reference, or poor connection |
| Supply voltage across an unlit LED | LED path may be open or reversed |
| 0 V across an unlit LED | Both LED terminals may be at the same potential |
| Negative DC voltage | Probe polarity is reversed |
| Current remains 0 mA | Open path, wrong socket/range, or blown meter fuse |
