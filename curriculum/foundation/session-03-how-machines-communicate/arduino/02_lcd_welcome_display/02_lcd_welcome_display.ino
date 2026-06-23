// InnoBees STEM Lab - LCD Welcome Display
// LCD with I2C backpack: SDA -> A4, SCL -> A5, VCC -> 5V, GND -> GND
// Displays welcome message and optional sensor data
// Library required: LiquidCrystal_I2C

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Common I2C address is 0x27. Try 0x3F if display is blank.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("InnoBees STEM!");

  delay(3000);
  lcd.clear();
}

void loop() {
  // Display time counter
  unsigned long seconds = millis() / 1000;
  unsigned long minutes = seconds / 60;
  seconds = seconds % 60;

  lcd.setCursor(0, 0);
  lcd.print("InnoBees Lab    ");

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print("   ");

  delay(1000);
}
