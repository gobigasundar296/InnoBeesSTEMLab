# Teacher Answer Key: Session 3 Workbook

## Part A

1. Button=INPUT, LED=OUTPUT, LDR=INPUT, Buzzer=OUTPUT, PIR=INPUT,
   LCD=OUTPUT, Servo=OUTPUT, Ultrasonic=INPUT.

2. Ultrasonic sensor detects person nearby. Arduino decides to open the gate.
   Servo moves to 90 degrees (open position).

3. Digital output gives 2 states: HIGH and LOW. PWM gives 256 levels by
   switching rapidly. Range: 0 to 255. PWM pins: D3, D5, D6, D9, D10, D11.

## Part B

1. Red, Green, Blue, Yellow, Magenta, Cyan, White.

2. Answers vary. Check that values are 0-255 and the color description is
   reasonable for those values.

3. Each RGB color channel has a different forward voltage. Without separate
   resistors, current distribution would be unequal and potentially unsafe.

4. `analogWrite(RED_PIN, 255)`, `analogWrite(GREEN_PIN, 127)`,
   `analogWrite(BLUE_PIN, 0)`. This produces an orange-like color
   (full red + half green).

## Part C

1. Liquid Crystal Display.

2. Total: 32. Rows: 2. Columns: 16.

3. Without I2C: 6+ data wires. With I2C: 2 data wires (SDA and SCL).

4. `lcd.setCursor(0, 0)` for name, `lcd.setCursor(0, 1)` for class.
   Accept any valid text.

5. Check the I2C address (try 0x27 or 0x3F). Adjust the contrast
   potentiometer on the I2C backpack module. Verify SDA→A4 and SCL→A5.

## Part D

1. 7 segments (labeled a through g, plus optional decimal point).

2. Digit 0: a,b,c,d,e,f on (all except g). Digit 3: a,b,c,d,g on.
   Digit 7: a,b,c on.

3. When you only need to show numbers, need high visibility from a distance,
   or want a simple low-cost solution.

## Part E

1. Active: No frequency needed, cannot play notes, use `digitalWrite()`.
   Passive: Needs frequency, can play notes, use `tone()`.

2. 440 Hz.

3. Answers vary. Check that pattern has defined on/off times and repetition.

## Part F

1. A servo rotates to a specific angle and holds position. A regular motor
   spins continuously without position control.

2. 0 degrees to 180 degrees.

3. Brown/Black = GND. Red = 5V (power). Orange/Yellow = Signal.

4. `#include <Servo.h>`, `myServo.attach(9)`, `myServo.write(90)`.

5. Examples: automatic gate/barrier, robot arm joint, radar scanner,
   bin lid opener, steering mechanism.

## Part G

Challenge 1: Green 5s → Yellow 2s → Red 5s is a typical sequence.
Accept reasonable timing choices.

Challenge 2: Accept any appropriate welcome message within 16 characters
per line.

Challenge 3: Must include at least 3 outputs, at least 1 sensor, and a
clear behavioral description.
