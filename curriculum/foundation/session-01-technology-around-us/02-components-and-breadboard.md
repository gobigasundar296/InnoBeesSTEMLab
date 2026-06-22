# Chapter 2: LEDs, RGB LEDs, Buttons, Buzzers and Breadboards

## Standard LED

LED means **light-emitting diode**. It converts electrical energy into light
and allows current mainly in one direction.

### Polarity

- **Anode (+):** usually the longer leg.
- **Cathode (-):** usually the shorter leg.
- The flat edge on the LED body usually marks the cathode.
- Inside a clear LED, the larger internal metal piece is commonly the
  cathode.

Always confirm with a datasheet or the multimeter diode-test mode when
polarity is uncertain.

### Why color matters

LED color is produced by its semiconductor material, not simply by colored
plastic. Different colors normally have different forward voltages.

Typical teaching estimates:

| LED color | Approximate forward voltage |
|---|---:|
| Red | 1.8-2.2 V |
| Yellow | 1.9-2.2 V |
| Green | 2.0-3.2 V |
| Blue | 2.8-3.4 V |
| White | 2.8-3.4 V |

These are estimates. Use the component datasheet or measure the actual LED for
precise design.

### Significance of LEDs

LEDs are important because they:

- use little power compared with many older lighting technologies;
- switch quickly;
- last a long time when operated correctly;
- can indicate status, warnings, data, or decoration;
- are the basis of displays, lighting, optical communication, and sensors.

## RGB LED

An RGB LED contains red, green, and blue LED chips in one package. By changing
the brightness of each chip, many colors can be mixed.

### Common cathode

All three cathodes share one negative pin. Connect the common pin to GND.
Apply a positive output through a separate resistor to each color pin.

### Common anode

All three anodes share one positive pin. Connect the common pin to the supply.
An Arduino output turns a color on by pulling its pin LOW through a resistor.
This logic is inverted compared with a common-cathode LED.

### One resistor per color

Red, green, and blue chips may have different forward voltages. Each color
requires its own current-limiting resistor.

See [LED and RGB LED diagram](diagrams/led-and-rgb-led.svg).

## Resistor

A resistor limits current and creates a voltage drop. Ordinary fixed resistors
have no polarity, so they may be inserted either way around.

Common beginner values:

- 100 ohm: low resistance;
- 220 or 330 ohm: common LED current limiting at 5 V;
- 1 kilohm: signal limiting;
- 10 kilohm: common pull-up or pull-down value.

### Four-band color code

1. First band: first digit.
2. Second band: second digit.
3. Third band: multiplier.
4. Fourth band: tolerance.

Examples:

| Value | Typical four-band colors |
|---|---|
| 100 ohm | Brown - Black - Brown - Gold |
| 220 ohm | Red - Red - Brown - Gold |
| 330 ohm | Orange - Orange - Brown - Gold |
| 1 kilohm | Brown - Black - Red - Gold |
| 10 kilohm | Brown - Black - Orange - Gold |

Color bands can be hard to distinguish. A multimeter resistance measurement
is the final check.

## Push button

A push button is a temporary switch.

- **Normally open:** no conducting path until pressed.
- **Pressed:** contacts close and current can flow.
- A common four-leg tactile button has two legs permanently joined on each
  side. Pressing the button joins the two sides.

Place a four-leg tactile button across the breadboard center channel. If it is
rotated incorrectly, both wires may already be connected to the same internal
side and pressing it will make no difference.

## Buzzer

### Active buzzer

An active buzzer contains an oscillator. Applying its rated DC voltage
produces a fixed sound. Observe its `+` and `-` markings.

### Passive buzzer

A passive buzzer needs a changing signal. Arduino's `tone()` function can
produce different pitches.

### Current warning

Do not assume every buzzer can connect directly to an Arduino pin. This module
allows direct connection only for a documented or measured low-current 5 V
active buzzer below 20 mA. Higher-current buzzers require a transistor driver
and usually a protection component.

## Breadboard

A solderless breadboard lets students build and change circuits without
soldering.

### Terminal strips

In the center area, each numbered row is normally divided into two groups:

```text
a b c d e   gap   f g h i j
```

The five holes `a-e` are connected internally. The five holes `f-j` are
connected internally. The center gap separates them.

### Power rails

Long rails near the edges are used for supply voltage and ground. Red and blue
lines are labels only; students still have to connect those rails to a power
source.

Some breadboards split each long rail at the center. Use continuity mode to
test the actual board before assuming the entire rail is connected.

### Correct breadboard workflow

1. Disconnect power.
2. Connect the positive supply to the red rail.
3. Connect GND to the blue or negative rail.
4. Place components so their legs do not enter the same connected group unless
   they are intended to join.
5. Use short, color-coded jumper wires.
6. Trace the full path from positive supply to GND.
7. Check for a direct short.
8. Connect power and observe.

See [breadboard internal connections](diagrams/breadboard-internal-connections.svg).
