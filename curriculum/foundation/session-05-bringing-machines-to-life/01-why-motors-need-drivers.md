# Chapter 1: Why Motors Need Drivers

## The Arduino pin limitation

In previous sessions, we connected LEDs and buzzers directly to Arduino pins.
This worked because LEDs need only 10-20 mA of current.

**Motors are different.** Even a small DC motor needs 100-500 mA or more.

| Device | Typical current | Arduino pin can supply |
|---|---|---|
| LED | 10-20 mA | Yes (max 20 mA per pin) |
| Active buzzer | 5-15 mA | Yes |
| Small servo (SG90) | 100-250 mA | Yes (from 5V pin, not I/O) |
| Small DC motor | 100-500 mA | **NO** |
| Gear motor | 200-800 mA | **NO** |
| Large servo | 500-1500 mA | **NO** |

## What happens if you connect a motor directly?

If you connect a DC motor directly to an Arduino I/O pin:

1. The pin cannot supply enough current — the motor stalls or barely moves.
2. The Arduino pin may be damaged by the excess current demand.
3. The motor creates electrical noise (back-EMF) that can reset or damage
   the Arduino.

**Rule:** Never connect a DC motor directly to an Arduino I/O pin.

## The solution: motor drivers

A motor driver is a circuit that:

1. **Amplifies:** Takes a small control signal from Arduino and provides
   high current from a separate power source.
2. **Isolates:** Protects Arduino from motor noise and back-EMF.
3. **Controls:** Allows direction change and speed control.

```text
Arduino pin (signal) → Motor Driver → Motor (power from battery)
                              ↑
                        Battery/Power supply
```

## The concept of separate power

```text
┌─────────────┐     Control signal     ┌──────────────┐     High current     ┌───────┐
│   Arduino   │ ──────────────────────→ │ Motor Driver │ ──────────────────→  │ Motor │
│  (brain)    │                         │ (muscle)     │                       └───────┘
└─────────────┘                         └──────────────┘
      │                                        ↑
      │ USB power (logic)            Battery (motor power)
      ↓                                        │
   Computer                              9V or 6V supply
```

**Key insight:** Arduino is the brain (gives commands). The motor driver is
the muscle (provides power). The battery feeds the muscle.

## Back-EMF: why motors are electrically "noisy"

When a motor spins, it also acts as a generator. When you suddenly stop or
reverse a motor, it produces a voltage spike called **back-EMF** (back
electromotive force).

This spike can:
- Damage the Arduino.
- Reset the microcontroller.
- Corrupt program execution.

Motor drivers include protection diodes to absorb these spikes safely.

## Servo motors: the exception

SG90 micro servos can be powered from the Arduino's 5V pin (not I/O pin)
because:

- They draw power from the 5V rail, not the signal pin.
- The signal pin only sends a tiny PWM pulse.
- A single SG90 draws 100-250 mA, within USB power limits.

For multiple servos or larger servos, use external power.

## Summary: when to use what

| Motor type | Power source | Control | Driver needed? |
|---|---|---|---|
| SG90 servo (1 unit) | Arduino 5V pin | Signal pin | No (Servo library) |
| Multiple servos | External 5V | Signal pins | No, but external power |
| Small DC motor | Battery (6-12V) | Driver module | **Yes** |
| Gear motor | Battery (6-12V) | Driver module | **Yes** |
| Stepper motor | External supply | Driver module | **Yes** |
