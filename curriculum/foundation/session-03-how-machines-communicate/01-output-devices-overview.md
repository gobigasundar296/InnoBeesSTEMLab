# Chapter 1: Output Devices — How Machines Talk Back

## From sensing to communicating

In Session 2, we learned how machines *sense* the world using sensors (inputs).
But sensing is only useful if the machine can *communicate* its findings or
*act* on them.

Output devices are how machines talk back to us or affect the physical world.

## The complete system

```text
INPUT (sensor) → PROCESS (Arduino) → OUTPUT (actuator/display)
```

| Role | Examples |
|---|---|
| Input (sensors) | Button, LDR, PIR, ultrasonic |
| Processing | Arduino reads data, makes decisions |
| Output (actuators/displays) | LED, LCD, buzzer, servo motor |

## Types of output devices

### Visual outputs (we can see)

| Device | What it does | Complexity |
|---|---|---|
| LED | On/off indicator or brightness | Simple |
| RGB LED | Multi-color light | Medium |
| 7-segment display | Shows numbers (0-9) | Medium |
| LCD display | Shows text and numbers | Medium-High |
| OLED display | Shows text, graphics | Advanced |

### Audio outputs (we can hear)

| Device | What it does | Complexity |
|---|---|---|
| Active buzzer | Single tone when powered | Simple |
| Passive buzzer | Different tones with PWM | Medium |
| Speaker | Music, voice (with amplifier) | Advanced |

### Motion outputs (we can see movement)

| Device | What it does | Complexity |
|---|---|---|
| Servo motor | Rotates to specific angle | Medium |
| DC motor | Continuous rotation | Medium |
| Stepper motor | Precise step-by-step rotation | Advanced |

## Digital vs. PWM output

### Digital output: `digitalWrite()`

Only two states: HIGH (5 V) or LOW (0 V).

- LED fully on or fully off.
- Buzzer sounding or silent.

### PWM output: `analogWrite()`

PWM (Pulse Width Modulation) rapidly switches between HIGH and LOW to simulate
intermediate values. The `analogWrite()` function accepts values from 0 to 255.

- 0 = always LOW (0% duty cycle)
- 127 = HIGH half the time (50% duty cycle)
- 255 = always HIGH (100% duty cycle)

**PWM pins on Arduino Uno:** D3, D5, D6, D9, D10, D11 (marked with `~`).

Applications:

- Control LED brightness smoothly.
- Mix RGB LED colors at different intensities.
- Control servo motor position.
- Control motor speed.

## Real-world output systems

| System | Visual output | Audio output | Motion output |
|---|---|---|---|
| Traffic light | Red/yellow/green LEDs | Pedestrian beep | — |
| Microwave | LCD timer display | Done beep | Turntable motor |
| Elevator | Floor number display | Arrival chime | Door servo |
| Car dashboard | Speed display, warning LEDs | Alert buzzer | — |
| Robot | Status LEDs | Voice speaker | Wheels, arms |

## Why outputs matter

A system with only inputs and processing but no outputs is useless to humans.
Outputs are how the system:

- **Informs:** Shows data (temperature on LCD).
- **Warns:** Alerts to danger (buzzer for fire).
- **Indicates:** Shows status (green LED = OK).
- **Acts:** Moves something (servo opens a gate).
- **Entertains:** Plays music, creates light shows.
