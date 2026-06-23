# Teacher Answer Key: Session 2 Workbook

## Part A

1. A sensor is a device that detects a change in the physical environment
   and converts it into an electrical signal.

2. Input: LDR detects light level. Process: Arduino checks if light is below
   threshold. Output: LED turns on.

3. Digital: gives only two states (HIGH/LOW, 1/0). Analog: gives a range of
   values (0-1023 on Arduino).

4. Eyes → Light → LDR/photodiode. Ears → Sound → Sound sensor/microphone.
   Skin (touch) → Pressure/contact → Push button/touch sensor.
   Skin (temperature) → Heat → Thermistor/temperature sensor.

## Part B

1. Without a pull-up or pull-down resistor, an unpressed button leaves the
   pin floating (neither HIGH nor LOW), causing unpredictable readings.

2. Pull-down: pressed = HIGH, released = LOW.
   INPUT_PULLUP: pressed = LOW, released = HIGH.

3. `pinMode(2, INPUT_PULLUP);` and `int state = digitalRead(2);`

## Part C

1. When light increases, resistance decreases. When light decreases,
   resistance increases.

2. 5V → LDR → A0 → 10k resistor → GND.

3. Values will vary by LDR and environment. Typical: dark = 50-200,
   bright = 700-1000. Threshold should be between these values.

4. `analogRead(LDR_PIN)`, `<` (less than), `HIGH`, `LOW`.

## Part D

1. Step 1: 10 µs HIGH pulse. Step 2: ultrasonic (40 kHz) pulses. Step 3:
   object. Step 4: HIGH. Step 5: distance.

2. `(Time in microseconds × 0.034) / 2`. Divide by 2 because the sound
   travels to the object and back (round trip).

3. Actual values will vary. Sensor is typically accurate within 2-3 mm for
   distances between 2 cm and 200 cm. Beyond 300 cm, readings may become
   unreliable.

## Part E

1. Passive Infrared.

2. It detects changes in infrared radiation caused by warm moving objects.

3. The pyroelectric sensor needs time to stabilize and establish a baseline
   reading of the ambient infrared environment.

4. PIR detects a standing person: **False** (detects motion/change only).
   PIR can detect animals: **True** (any warm moving body).
   PIR uses infrared radiation: **True**.
   PIR measures exact distance: **False** (only detects presence/motion).
   PIR output is digital: **True** (HIGH when motion detected).

## Part F

| Sensor | Detects | Type | Function |
|---|---|---|---|
| Push button | Physical press | Digital | `digitalRead()` |
| Touch sensor | Finger proximity | Digital | `digitalRead()` |
| LDR | Light intensity | Analog | `analogRead()` |
| HC-SR04 | Distance | Digital (pulse) | `pulseIn()` |
| PIR | Motion | Digital | `digitalRead()` |
| Soil moisture | Water in soil | Analog + Digital | `analogRead()` |
| Sound sensor | Sound level | Analog + Digital | Both |
| Flame sensor | IR from fire | Analog + Digital | Both |

## Part G

Answers vary by team. Key assessment criteria:

- Challenge 1: PIR triggers buzzer and LED correctly. Students explain the
  warm-up requirement and what triggers the sensor.
- Challenge 2: LDR threshold is determined experimentally using Serial
  Monitor. LED turns on in dark, off in light.
- Challenge 3: At least two sensors and two outputs. System behavior is
  clearly explained. Threshold values are justified.
