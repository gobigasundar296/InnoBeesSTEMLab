# Session 1: Electricity, Electronics and Arduino Foundations

This module gives students the foundation required before they begin robotics
or sensor projects. It starts with electricity and Ohm's law, moves through
components and circuit construction, and finishes with Arduino-controlled
light programs.

**Audience:** Classes 6-9  
**Recommended delivery:** Four 2-hour lessons or one intensive workshop  
**Learning cycle:** Explain -> Predict -> Calculate -> Build -> Measure -> Code

> The original curriculum allocates two hours to Session 1. The requested
> depth is larger than one safe beginner lesson, so this material is organized
> as four blocks. A teacher can select the Core Path for a two-hour class or
> teach the complete module over eight hours.

## What students learn

1. The difference between electricity and electronics.
2. Voltage, current, resistance, power, and `V = I x R`.
3. LED and RGB LED construction, polarity, color, and current limiting.
4. How breadboard holes and power rails are connected internally.
5. How push buttons, active buzzers, and passive buzzers work.
6. Open, closed, series, and parallel circuits.
7. How to calculate and select a safe resistor value.
8. How to measure continuity, resistance, voltage, and current with a
   multimeter.
9. Arduino Uno external pins and its internal functional blocks.
10. How to wire and program LEDs and sequential light patterns.

## Learning documents

- [Teacher guide and delivery plan](teacher-guide.md)
- [Chapter 1: Electricity and electronics](01-electricity-and-electronics.md)
- [Chapter 2: LEDs, RGB LEDs, buttons, buzzers and breadboards](02-components-and-breadboard.md)
- [Chapter 3: Circuits, Ohm's law and resistor calculations](03-circuits-and-resistors.md)
- [Chapter 4: Ten practical breadboard circuits](04-ten-practical-circuits.md)
- [Chapter 5: How to use a digital multimeter](05-multimeter.md)
- [Chapter 6: Arduino pins, internal blocks and LED programming](06-arduino-foundations.md)
- [Student workbook](student-workbook.md)
- [Teacher answer key](teacher-answer-key.md)

## Visual library

- [Breadboard internal connections](diagrams/breadboard-internal-connections.svg)
- [LED and RGB LED guide](diagrams/led-and-rgb-led.svg)
- [Circuit types](diagrams/circuit-types.svg)
- [Multimeter guide](diagrams/multimeter-guide.svg)
- [Arduino Uno external pins](diagrams/arduino-uno-pin-map.svg)
- [Arduino internal block diagram](diagrams/arduino-internal-blocks.svg)
- [Ten breadboard circuit diagrams](circuits/README.md)

All diagrams are editable SVG files and can be displayed directly by GitHub.

## Arduino programs

- [External LED blink](arduino/01_external_led_blink/01_external_led_blink.ino)
- [Two LEDs alternate](arduino/02_two_led_alternate/02_two_led_alternate.ino)
- [Four LED chaser](arduino/03_four_led_chaser/03_four_led_chaser.ino)
- [Four LED bounce](arduino/04_four_led_bounce/04_four_led_bounce.ino)
- [Serial Monitor LED control](arduino/05_serial_monitor_led/05_serial_monitor_led.ino)
- [RGB color cycle](arduino/06_rgb_color_cycle/06_rgb_color_cycle.ino)

## Core Path for a two-hour class

If only two hours are available, teach:

1. Electricity, voltage, current, resistance, and `V = I x R`.
2. LED polarity and resistor calculation.
3. Breadboard internal connections.
4. Practical Circuit 1: single LED.
5. Multimeter continuity and DC voltage.
6. Arduino external LED blink.

The remaining circuit types, RGB LED, buzzer, resistor combinations, and
sequential programs should continue in the next lab.

## Equipment per team

- Arduino Uno R3 or compatible board and USB data cable
- Full-size or half-size breadboard
- 5 red LEDs, 1 green LED, 1 blue LED
- 1 common-cathode RGB LED
- 10 resistors of 220 ohm or 330 ohm
- Assorted resistors: 100 ohm, 1 kilohm, 10 kilohm
- 2 tactile push buttons
- 1 tested low-current 5 V active buzzer
- 15 male-to-male jumper wires
- Digital multimeter with probes
- Computer with Arduino IDE

## Non-negotiable safety rules

- Disconnect power before changing circuit wiring.
- Never connect 5 V directly to GND.
- Never connect an LED without a current-limiting resistor.
- Use one resistor for each parallel LED branch.
- Use resistance and continuity modes only on unpowered circuits.
- Never place multimeter probes across a supply while the meter is in current
  mode.
- Arduino Uno R3 I/O pins should be designed for no more than 20 mA per pin.
- Only a tested low-current active buzzer may be driven directly in these
  beginner circuits. Use a transistor driver for larger loads.

## Technical reference

Arduino Uno R3 pin names and limits in this module follow the official Arduino
Uno R3 documentation:

- <https://docs.arduino.cc/hardware/uno-rev3/>
- <https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf>
