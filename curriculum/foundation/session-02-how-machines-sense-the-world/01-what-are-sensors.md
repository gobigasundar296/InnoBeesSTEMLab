# Chapter 1: What Are Sensors?

## The human body as a sensing system

Humans sense the world through eyes, ears, nose, tongue, and skin. Each sense
organ detects a specific type of physical change — light, sound, chemicals,
temperature, or pressure — and sends signals to the brain.

Electronic systems work similarly:

| Human sense | Physical quantity | Electronic sensor example |
|---|---|---|
| Eyes | Light | LDR, photodiode |
| Ears | Sound | Microphone, sound sensor |
| Skin (touch) | Pressure, contact | Push button, touch sensor |
| Skin (heat) | Temperature | Thermistor, temperature sensor |
| Nose | Gas concentration | Gas sensor (MQ series) |

## What is a sensor?

A sensor is a device that detects a change in the physical environment and
converts it into an electrical signal that a circuit or microcontroller can
read.

**Key idea:** Sensors are the *inputs* of an electronic system. They answer
the question: *What is happening in the world right now?*

## The Input-Process-Output model

Every smart system follows this pattern:

```text
INPUT (sensor) → PROCESS (microcontroller) → OUTPUT (actuator)
```

Examples:

| System | Input sensor | Processing | Output |
|---|---|---|---|
| Automatic street light | LDR detects darkness | Arduino checks threshold | LED turns on |
| Visitor alert | PIR detects motion | Arduino triggers alarm | Buzzer sounds |
| Smart irrigation | Soil moisture sensor | Arduino checks dryness | Water pump activates |
| Parking assistant | Ultrasonic sensor | Arduino measures distance | Buzzer beeps faster |

## Types of sensor signals

### Digital sensors

A digital sensor gives only two states:

- **HIGH (1):** something is detected, or button is pressed.
- **LOW (0):** nothing is detected, or button is released.

Examples: push button, touch sensor, PIR sensor (output pin), flame sensor
(digital output).

Arduino reads digital sensors with `digitalRead(pin)`.

### Analog sensors

An analog sensor gives a range of values. The signal varies continuously
depending on the physical quantity.

Examples: LDR (through voltage divider), soil moisture sensor, sound sensor
(analog output).

Arduino reads analog sensors with `analogRead(pin)`, returning values from
0 to 1023.

## Sensor specifications to look for

When choosing or using a sensor:

1. **Operating voltage:** Most modules work at 3.3 V or 5 V.
2. **Output type:** Digital, analog, or both.
3. **Detection range:** Maximum and minimum the sensor can measure.
4. **Response time:** How quickly the sensor reacts.
5. **Current draw:** Ensure the Arduino pin or supply can handle it.

## Real-world sensor applications

- **Home security:** PIR sensors in motion detectors.
- **Smartphones:** Accelerometer, proximity sensor, ambient light sensor.
- **Cars:** Ultrasonic parking sensors, rain sensors on wipers.
- **Agriculture:** Soil moisture sensors for smart irrigation.
- **Industry:** Temperature, pressure, and gas sensors in factories.
- **Weather stations:** Wind speed, humidity, UV level sensors.

## Safety with sensors

- Always check the sensor operating voltage before connecting.
- Never apply 5 V to a sensor rated for 3.3 V only.
- Handle sensor modules by the edges; avoid touching exposed pins.
- Some sensors (flame, gas) detect dangerous conditions — never create real
  hazards to test them in a classroom.
