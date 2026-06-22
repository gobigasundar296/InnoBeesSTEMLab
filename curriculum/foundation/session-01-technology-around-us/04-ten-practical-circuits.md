# Chapter 4: Ten Practical Breadboard Circuits

These circuits progress from a fixed LED to Arduino-controlled sequential
lights. Build with power disconnected and complete the safety check before
every test.

## Standard wiring colors

- Red: 5 V
- Black: GND
- Yellow/orange: LED signal
- Green: button signal
- Purple: buzzer or RGB signal

Wire color is a convention, not an electrical property.

## Circuit 1 - Single LED: simple closed circuit

**Concepts:** closed circuit, LED polarity, current limiting  
**Parts:** red LED, 330 ohm resistor, breadboard, 5 V and GND

**Path:** `5 V -> 330 ohm -> LED -> GND`

Expected current for a 2.0 V red LED:

```text
I = (5 - 2.0) / 330 = 9.1 mA
```

[Breadboard diagram](circuits/01-single-led-closed.svg)

## Circuit 2 - Open and closed LED circuit

**Concepts:** open circuit, closed circuit, switch  
**Parts:** red LED, 330 ohm resistor, push button

**Path:** `5 V -> button -> 330 ohm -> LED -> GND`

The released button creates an open circuit. Pressing the button closes the
path and lights the LED.

[Breadboard diagram](circuits/02-button-open-closed.svg)

## Circuit 3 - Two LEDs in series

**Concepts:** series path, equal current, added forward voltage  
**Parts:** two red LEDs, 150 ohm resistor

**Path:** `5 V -> 150 ohm -> LED 1 -> LED 2 -> GND`

Both LEDs carry the same current. Reversing or removing either LED opens the
whole circuit.

[Breadboard diagram](circuits/03-two-led-series.svg)

## Circuit 4 - Two LEDs in parallel

**Concepts:** branch current, same branch voltage, individual resistors  
**Parts:** two LEDs, two 330 ohm resistors

Each branch is:

```text
5 V -> 330 ohm -> LED -> GND
```

Never use one shared resistor after joining two LED branches in a beginner
design.

[Breadboard diagram](circuits/04-two-led-parallel.svg)

## Circuit 5 - Series resistors with one LED

**Concepts:** adding resistance, brightness and current  
**Parts:** red LED, 220 ohm resistor, 330 ohm resistor

```text
R_total = 220 + 330 = 550 ohm
I = (5 - 2.0) / 550 = 5.45 mA
```

Compare brightness with Circuit 1.

[Breadboard diagram](circuits/05-series-resistors-led.svg)

## Circuit 6 - Button-controlled active buzzer

**Concepts:** switch input without Arduino, polarity, sound output  
**Parts:** push button, tested low-current 5 V active buzzer

**Path:** `5 V -> button -> active buzzer (+) -> buzzer (-) -> GND`

Confirm the buzzer's rated voltage and current before use.

[Breadboard diagram](circuits/06-button-active-buzzer.svg)

## Circuit 7 - Button-controlled light and sound in parallel

**Concepts:** one switch controlling parallel output branches  
**Parts:** push button, LED, 330 ohm resistor, low-current active buzzer

After the button, current divides:

- branch 1: resistor and LED;
- branch 2: active buzzer.

Both outputs receive approximately the supply voltage.

[Breadboard diagram](circuits/07-button-led-buzzer-parallel.svg)

## Circuit 8 - Common-cathode RGB color mixer

**Concepts:** three LEDs in one package, separate resistors, color addition  
**Parts:** common-cathode RGB LED, three 330 ohm resistors

Connect the common cathode to GND. Connect each color anode to 5 V through its
own resistor, one color at a time.

- Red + green gives yellow-like light.
- Red + blue gives magenta-like light.
- Green + blue gives cyan-like light.
- All three approximate white, depending on LED balance.

[Breadboard diagram](circuits/08-rgb-color-mixer.svg)

## Circuit 9 - Arduino controls one external LED

**Concepts:** digital output, program control, common GND  
**Parts:** Arduino Uno, LED, 330 ohm resistor

**Path:** `D8 -> 330 ohm -> LED -> GND`

Upload [External LED Blink](arduino/01_external_led_blink/01_external_led_blink.ino).

[Breadboard diagram](circuits/09-arduino-external-led.svg)

## Circuit 10 - Arduino four-LED sequential light

**Concepts:** multiple outputs, arrays, loops, timing  
**Parts:** Arduino Uno, four LEDs, four 330 ohm resistors

| Arduino pin | Output |
|---|---|
| D4 | LED 1 |
| D5 | LED 2 |
| D6 | LED 3 |
| D7 | LED 4 |

Each pin has its own path:

`digital pin -> 330 ohm -> LED -> GND`

Upload either:

- [Four LED Chaser](arduino/03_four_led_chaser/03_four_led_chaser.ino)
- [Four LED Bounce](arduino/04_four_led_bounce/04_four_led_bounce.ino)

[Breadboard diagram](circuits/10-arduino-four-led-chaser.svg)

## Practical record table

For every circuit, students record:

| Item | Record |
|---|---|
| Circuit number | |
| Prediction | |
| Calculated resistance/current | |
| Measured supply voltage | |
| Measured LED or load voltage | |
| Observed result | |
| Fault found and corrected | |
