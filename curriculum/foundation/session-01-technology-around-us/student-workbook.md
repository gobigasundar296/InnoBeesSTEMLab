# Student Workbook: Electricity, Electronics and Arduino

**Name:** _________________________  
**Class:** _________________________  
**Team:** _________________________  
**Date:** _________________________

## Safety promise

Tick each rule before starting.

- [ ] I will disconnect power before changing wires.
- [ ] I will never connect 5 V directly to GND.
- [ ] I will use a resistor with every LED branch.
- [ ] I will use resistance and continuity modes only on unpowered circuits.
- [ ] I will check the multimeter mode and probe sockets before measuring.
- [ ] I will ask the teacher before connecting an unfamiliar load to Arduino.

## Part A - Electricity and electronics

### 1. Explain the difference

Electricity is:

____________________________________________________________________

Electronics is:

____________________________________________________________________

### 2. Input, process and output

Choose a smart system from home or school.

**System:** _________________________________________________________

| Input | Processing or decision | Output |
|---|---|---|
| | | |

### 3. Match the quantity

Write `voltage`, `current`, `resistance`, or `power`.

1. Electrical push or potential difference: ______________________
2. Rate of charge flow: __________________________________________
3. Opposition to current: ________________________________________
4. Rate of energy transfer: ______________________________________

### 4. Units

| Quantity | Symbol | Unit |
|---|---|---|
| Voltage | | |
| Current | | |
| Resistance | | |
| Power | | |

## Part B - Ohm's law

Use:

```text
V = I x R
I = V / R
R = V / I
```

Show working and include units.

1. A 1000 ohm resistor has 5 V across it. Find current.

____________________________________________________________________

2. A circuit needs 10 mA with a 3 V resistor drop. Find resistance.

____________________________________________________________________

3. A 220 ohm resistor carries 10 mA. Find its voltage drop.

____________________________________________________________________

4. Convert `0.015 A` to milliamps: _________________________________

5. Convert `2.2 kilohm` to ohms: __________________________________

## Part C - LED and RGB LED

1. LED stands for _________________________________________________.
2. The long leg is usually the __________________________.
3. The short leg and flat rim usually mark the ____________________.
4. Why does an LED need a resistor?

____________________________________________________________________

5. Why does each RGB color channel need its own resistor?

____________________________________________________________________

6. For a common-cathode RGB LED, the common pin connects to:
   **5 V / GND**

### RGB color prediction

| Colors on | Predicted mixed color | Observed color |
|---|---|---|
| Red + green | | |
| Red + blue | | |
| Green + blue | | |
| Red + green + blue | | |

## Part D - Breadboard investigation

Use continuity mode with the board unpowered.

| Test points | Prediction | Result |
|---|---|---|
| Two holes in one group of five | | |
| Two holes across the center gap | | |
| Two points on the same power rail | | |
| Two points across the center of a split rail | | |

Draw the hidden connection pattern of one breadboard row:

```text
 a  b  c  d  e       f  g  h  i  j


```

Why should a four-leg tactile button normally cross the center gap?

____________________________________________________________________

## Part E - Circuit types

Classify each description as `open`, `closed`, `series`, or `parallel`.

1. A wire is disconnected, so no current can complete the loop:
   ______________________
2. Two LEDs are in one path and carry the same current:
   ______________________
3. A switch is pressed and the complete safe path conducts:
   ______________________
4. Two LED branches are connected across the same supply:
   ______________________

Complete the rules:

- In a series circuit, __________________ is the same through each component.
- In parallel branches, __________________ is the same across each branch.
- Series resistances are found by __________________________________.
- Parallel branch currents are found by _____________________________.

## Part F - Calculate LED resistors

Use:

```text
R = (V_supply - V_LED) / I_LED
```

Convert milliamps to amps before calculating.

### 1. Red LED

`V_supply = 5 V`, `V_LED = 2.0 V`, desired `I = 10 mA`

```text
R = _________________________________________________
```

Calculated value: __________ ohm  
Chosen common value: __________ ohm

### 2. Blue LED

`V_supply = 5 V`, `V_LED = 3.2 V`, desired `I = 10 mA`

```text
R = _________________________________________________
```

Calculated value: __________ ohm  
Chosen common value: __________ ohm

### 3. Two red LEDs in series

`V_supply = 5 V`, each `V_LED = 2.0 V`, desired `I = 8 mA`

```text
V_LED_total = _______________________________________
R = _________________________________________________
```

Calculated value: __________ ohm  
Chosen common value: __________ ohm

### 4. Two LEDs in parallel

Explain why each branch receives its own resistor:

____________________________________________________________________

## Part G - Ten practical circuits

Use [the circuit diagrams](circuits/README.md). For each circuit, complete one
record.

| # | Circuit | Prediction | Calculation | Measured result | Fault/fix |
|---:|---|---|---|---|---|
| 1 | Single LED | | | | |
| 2 | Button open/closed | | | | |
| 3 | Two LEDs series | | | | |
| 4 | Two LEDs parallel | | | | |
| 5 | Series resistors | | | | |
| 6 | Button + buzzer | | | | |
| 7 | LED + buzzer parallel | | | | |
| 8 | RGB mixer | | | | |
| 9 | Arduino LED | | | | |
| 10 | Arduino chaser | | | | |

## Part H - Multimeter

### Select the correct connection

Write `series` or `parallel`.

1. Voltage is measured in __________________.
2. Current is measured in __________________.

Write `power on` or `power off`.

3. Resistance is measured with __________________.
4. Continuity is tested with __________________.
5. DC voltage is measured with __________________.

### Measure Circuit 1

| Measurement | Predicted | Measured |
|---|---:|---:|
| Supply voltage | | |
| LED voltage | | |
| Resistor voltage | | |
| Calculated current using resistor voltage | | |
| Directly measured current | | |

Does `V_supply` approximately equal `V_LED + V_resistor`?

____________________________________________________________________

### Critical safety question

Why must a current meter never be connected directly between 5 V and GND?

____________________________________________________________________

## Part I - Arduino

### Label the function

| Arduino item | Function |
|---|---|
| USB connector | |
| ATmega328P | |
| D0/RX and D1/TX | |
| PWM pin marked `~` | |
| A0-A5 | |
| 5V | |
| GND | |
| RESET | |

### Read the blink program

1. Which pin controls the LED? __________________
2. Which line configures the pin as an output?

____________________________________________________________________

3. What does `HIGH` do? ____________________________________________
4. What does `LOW` do? _____________________________________________
5. How long is `delay(500)` in seconds? _____________________________

### Modify a program

Choose one:

- [ ] Make the blink twice as fast.
- [ ] Make the blink twice as slow.
- [ ] Reverse the chaser direction.
- [ ] Create a two-on, two-off pattern.
- [ ] Add a pause after the fourth LED.

Describe your code change:

____________________________________________________________________

Observed result:

____________________________________________________________________

## Part J - Debugging log

**Symptom:** ________________________________________________________

**My first prediction:** ___________________________________________

**One test I performed:** __________________________________________

**Result:** _________________________________________________________

**Next action:** ____________________________________________________

**Final cause:** ____________________________________________________

## Exit assessment

1. Explain `V = I x R` using one real circuit.

____________________________________________________________________

2. Explain the difference between series lights and Arduino sequential
   lights.

____________________________________________________________________

3. Name one measurement that must be performed with power off.

____________________________________________________________________

4. Name one measurement that is performed with power on.

____________________________________________________________________

5. Draw a new circuit containing one button, two LEDs, two resistors, and an
   Arduino. Label the pins and current paths.






