# Teacher Answer Key: Session 1 Workbook

## Part A

Electricity: presence or movement of electric charge and the transfer of
electrical energy. Electronics: circuits and components that control
electrical energy or information.

Quantities: voltage, current, resistance, power.

| Quantity | Symbol | Unit |
|---|---|---|
| Voltage | V | volt |
| Current | I | ampere |
| Resistance | R | ohm |
| Power | P | watt |

## Part B

1. `I = 5 / 1000 = 0.005 A = 5 mA`
2. `R = 3 / 0.010 = 300 ohm`
3. `V = 0.010 x 220 = 2.2 V`
4. `15 mA`
5. `2200 ohm`

## Part C

1. Light-emitting diode
2. Anode
3. Cathode
4. To limit current and prevent excessive current from damaging the LED or
   controller.
5. Each internal color is a separate LED and may have a different forward
   voltage. Each branch requires controlled current.
6. GND

Color predictions: yellow-like, magenta-like, cyan-like, white-like.

## Part D

Typical breadboard:

- same group of five: connected;
- across center gap: not connected;
- same continuous power rail: connected;
- across a split rail: not connected unless linked.

A tactile button crosses the gap so its permanently connected pairs are on
opposite sides and pressing the button creates a new connection.

## Part E

1. Open
2. Series
3. Closed
4. Parallel

Series current is the same. Parallel branch voltage is the same. Series
resistances are added. Parallel branch currents are added.

## Part F

1. Red:
   `R = (5 - 2.0) / 0.010 = 300 ohm`; choose 330 ohm.
2. Blue:
   `R = (5 - 3.2) / 0.010 = 180 ohm`; choose 220 ohm.
3. Two red in series:
   `V_LED_total = 4.0 V`;
   `R = (5 - 4.0) / 0.008 = 125 ohm`; choose 150 ohm.
4. Separate resistors prevent component variation from causing unequal or
   unsafe branch current.

## Part H

1. Parallel
2. Series
3. Power off
4. Power off
5. Power on

For the example red LED circuit, expected values are approximately:

- supply: 5 V;
- LED: about 2 V;
- resistor: about 3 V;
- current: `3 / 330 = 9.1 mA`.

Actual values vary. The direct current measurement should be reasonably close
to the current calculated from resistor voltage.

A current meter connected directly across 5 V and GND creates a very
low-resistance path, potentially blowing the meter fuse or damaging equipment.

## Part I

- USB: power, upload, and serial connection.
- ATmega328P: executes the program and controls I/O.
- D0/RX and D1/TX: hardware serial communication.
- PWM pin: can output pulse-width modulation with `analogWrite()`.
- A0-A5: analog voltage inputs.
- 5V: regulated 5 V rail/output in the normal supported power arrangement.
- GND: circuit reference and current return.
- RESET: restarts the sketch.

Blink:

1. D8
2. `pinMode(LED_PIN, OUTPUT);`
3. Sets the output HIGH, approximately 5 V.
4. Sets the output LOW, approximately 0 V.
5. 0.5 seconds.
