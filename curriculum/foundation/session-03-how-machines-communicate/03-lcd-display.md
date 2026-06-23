# Chapter 3: LCD Display with I2C

## What is an LCD?

LCD stands for **Liquid Crystal Display**. A 16x2 LCD can show 2 rows of 16
characters each — 32 characters total. This is enough to display sensor
readings, messages, menus, and status information.

## The I2C advantage

A standard 16x2 LCD needs 6+ data wires to connect to Arduino. An **I2C
backpack module** reduces this to just 2 data wires plus power:

| Without I2C | With I2C backpack |
|---|---|
| 6 data pins + 2 power | 2 data pins + 2 power |
| Complex wiring | Simple wiring |
| Uses many Arduino pins | Uses only A4 and A5 |

## I2C connections

| LCD I2C module | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| SDA | Arduino A4 |
| SCL | Arduino A5 |

That's it! Four wires for a full text display.

## I2C address

Each I2C device has an address. Common LCD I2C addresses:

- `0x27` (most common)
- `0x3F` (some modules)

If unsure, run an I2C scanner sketch to find the address.

## Required library

Install the **LiquidCrystal_I2C** library in Arduino IDE:

1. Open Arduino IDE.
2. Go to Sketch → Include Library → Manage Libraries.
3. Search for "LiquidCrystal I2C".
4. Install the library by Frank de Brabander or similar.

## Basic LCD program

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);       // column 0, row 0
  lcd.print("Hello World!");
  lcd.setCursor(0, 1);       // column 0, row 1
  lcd.print("InnoBees STEM");
}

void loop() {
  // static display, nothing to update
}
```

## Key LCD functions

| Function | What it does |
|---|---|
| `lcd.init()` | Initialize the LCD |
| `lcd.backlight()` | Turn on the backlight |
| `lcd.noBacklight()` | Turn off the backlight |
| `lcd.setCursor(col, row)` | Move cursor to position |
| `lcd.print("text")` | Print text at cursor |
| `lcd.print(number)` | Print a number at cursor |
| `lcd.clear()` | Clear all text |
| `lcd.home()` | Move cursor to (0,0) |

## Displaying sensor data

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int LDR_PIN = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Light Sensor");
}

void loop() {
  int light = analogRead(LDR_PIN);
  lcd.setCursor(0, 1);
  lcd.print("Level: ");
  lcd.print(light);
  lcd.print("    ");  // clear leftover characters
  delay(500);
}
```

## Scrolling text

For messages longer than 16 characters:

```cpp
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("InnoBees STEM Lab");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}
```

## LCD cursor positions

```text
Row 0: [0,0] [1,0] [2,0] ... [15,0]
Row 1: [0,1] [1,1] [2,1] ... [15,1]
```

The first parameter is the column (0-15), the second is the row (0-1).

## Practical tips

- Always call `lcd.init()` and `lcd.backlight()` in `setup()`.
- Use `lcd.clear()` sparingly — it causes flicker. Instead, overwrite with
  spaces.
- When printing variable-length numbers, add trailing spaces to clear old
  digits.
- If the display shows nothing, check the I2C address and adjust the
  contrast potentiometer on the backpack.
