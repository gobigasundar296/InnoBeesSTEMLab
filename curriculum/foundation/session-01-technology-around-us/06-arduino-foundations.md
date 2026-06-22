# Chapter 6: Arduino Foundations and LED Programs

## Arduino as the brain

Arduino Uno is a microcontroller development board. The ATmega328P executes
the program, reads electrical inputs, performs logic, and controls outputs.

The official Uno R3 has 14 digital I/O pins, six of which support PWM, and six
analog input pins. It operates with 5 V logic. The official pinout specifies a
maximum of 20 mA per I/O pin; good designs normally use less.

## External connections

See [Arduino Uno external pin map](diagrams/arduino-uno-pin-map.svg).

### USB connector

- supplies power from a computer;
- uploads programs;
- provides serial communication.

### Power pins

- `5V`: regulated 5 V output when appropriately powered;
- `3.3V`: 3.3 V output with limited current;
- `GND`: circuit reference and return path;
- `VIN`: external input to the board's regulator;
- `RESET`: restarts the running program;
- `IOREF`: indicates board logic reference voltage.

Do not connect an external supply to the 5 V pin unless the power design is
understood and supervised.

### Digital pins D0-D13

Digital pins can read or output two logic states: LOW and HIGH.

- D0/RX and D1/TX are used by hardware serial communication. Avoid them for
  beginner LEDs while uploading or using Serial Monitor.
- Pins marked `~` support PWM: D3, D5, D6, D9, D10, and D11.
- D13 is connected to the built-in `L` LED.
- D2 and D3 can be used for external interrupts.

### Analog inputs A0-A5

Analog inputs measure a voltage and convert it into a number. On Uno R3,
`analogRead()` normally returns 0-1023 for inputs between GND and the selected
analog reference.

- A4 is also SDA for I2C data.
- A5 is also SCL for I2C clock.

### Communication pins

- UART serial: D0/RX and D1/TX;
- I2C: SDA/A4 and SCL/A5;
- SPI: D10/SS, D11/COPI, D12/CIPO, D13/SCK and the ICSP header.

## Internal functional diagram

See [Arduino internal block diagram](diagrams/arduino-internal-blocks.svg).

Main blocks:

1. **USB interface:** links the board with the computer.
2. **ATmega16U2 USB-to-serial controller:** translates USB communication for
   the main controller on the classic Uno R3.
3. **ATmega328P microcontroller:** runs the uploaded sketch.
4. **Flash memory:** stores the program.
5. **SRAM:** stores changing variables while the program runs.
6. **EEPROM:** stores small values that remain after power is removed.
7. **Clock:** coordinates instruction timing.
8. **Digital I/O:** reads switches and controls digital devices.
9. **ADC:** converts analog input voltages into numbers.
10. **Timers/PWM:** create timing, PWM brightness, and other timed operations.
11. **Voltage regulation and protection:** condition supported power inputs.

The block diagram is an educational functional view, not a replacement for
the official electrical schematic.

## External LED connection

Use:

```text
D8 -> 330 ohm resistor -> LED anode
LED cathode -> GND
```

The resistor may be placed after the LED instead; it must remain in series.

## First program: blink one LED

```cpp
const int LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

- `const int` gives the pin a readable name.
- `setup()` runs once after reset.
- `pinMode()` configures D8 as an output.
- `loop()` repeats.
- `digitalWrite(HIGH)` makes the pin approximately 5 V.
- `digitalWrite(LOW)` makes the pin approximately 0 V.
- `delay(500)` waits 500 milliseconds.

Use the complete file:
[External LED Blink](arduino/01_external_led_blink/01_external_led_blink.ino).

## Sequential light programs

Sequential lights are separate LED branches controlled one after another.
The LEDs are not electrically connected in one series chain.

### Two LEDs alternate

LED 1 turns on while LED 2 is off, then the states exchange.

[Program](arduino/02_two_led_alternate/02_two_led_alternate.ino)

### Four LED chaser

An array stores the four pin numbers. A `for` loop lights each LED from left to
right.

[Program](arduino/03_four_led_chaser/03_four_led_chaser.ino)

### Four LED bounce

The light moves left to right and then right to left.

[Program](arduino/04_four_led_bounce/04_four_led_bounce.ino)

### Serial Monitor control

This program demonstrates actual serial communication. Send `1` to turn the
LED on, `0` to turn it off, or `b` to blink it.

[Program](arduino/05_serial_monitor_led/05_serial_monitor_led.ino)

### RGB color cycle

Three PWM pins change the red, green, and blue channels of a common-cathode
RGB LED.

[Program](arduino/06_rgb_color_cycle/06_rgb_color_cycle.ino)

## Upload checklist

1. Connect the board with a USB data cable.
2. Open the `.ino` file in Arduino IDE.
3. Select **Tools -> Board -> Arduino Uno**.
4. Select the correct port.
5. Verify/compile.
6. Disconnect external loads that conflict with D0/D1 if upload fails.
7. Upload.
8. Read the error message instead of repeatedly changing random settings.

## Arduino debugging order

1. Is the board powered?
2. Is the correct board selected?
3. Is the correct port selected?
4. Is the cable capable of data transfer?
5. Does the sketch compile?
6. Are pin numbers in code the same as the wiring?
7. Is every LED correctly oriented and protected by a resistor?
8. Do all components share Arduino GND?
9. Does a simpler blink sketch work?
10. Did one controlled change fix or change the symptom?

## Source references

- Arduino Uno R3 overview:
  <https://docs.arduino.cc/hardware/uno-rev3/>
- Official Uno R3 full pinout:
  <https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf>
- Official Uno R3 schematic:
  <https://docs.arduino.cc/resources/schematics/A000066-schematics.pdf>
