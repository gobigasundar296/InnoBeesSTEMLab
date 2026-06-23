# Chapter 3: DC Motors and Gear Motors

## DC Motor

A DC (Direct Current) motor converts electrical energy into continuous
rotational motion.

### How it works

1. Current flows through a wire coil inside the motor.
2. The coil sits inside a magnetic field (from permanent magnets).
3. The magnetic force on the current-carrying coil makes it rotate.
4. A commutator reverses current direction every half-turn to keep
   rotation continuous.

### Key properties

| Property | Typical small motor |
|---|---|
| Voltage | 3-6 V (or 6-12 V) |
| Current | 100-500 mA (no load) |
| Speed | 3000-15000 RPM |
| Torque | Low |
| Direction | Reversible by swapping polarity |

### DC motor characteristics

- **Fast** but **weak** (low torque).
- Spins continuously (unlike servo which holds an angle).
- Speed depends on voltage.
- Direction depends on current polarity.
- No built-in position feedback.

### Two wires only

A DC motor has just two terminals. There is no signal wire:

- Connect terminal A to positive, B to negative → spins one way.
- Swap the connections → spins the other way.
- More voltage → faster speed (within rated range).

## Gear Motor

A gear motor is a DC motor with a **gearbox** attached to the output shaft.

### Why gears?

The gearbox trades speed for torque:

```text
DC Motor alone:     Fast speed, low torque
                    (wheel spins fast but can't push hard)

Gear Motor:         Slower speed, high torque
                    (wheel spins slower but can push/carry weight)
```

### Gear ratio

| Gear ratio | Speed | Torque |
|---|---|---|
| 1:1 | Same as motor | Same as motor |
| 1:10 | 1/10 of motor speed | 10x motor torque |
| 1:48 | 1/48 of motor speed | 48x motor torque |
| 1:100 | 1/100 of motor speed | 100x motor torque |

Common gear motors for hobby robots use ratios like 1:48 or 1:120.

### Gear motor applications

- Robot wheels (needs torque to move the robot body).
- Conveyor belts.
- Automatic blinds.
- Robotic arms (low joints).
- Model vehicles.

## Comparing motor types

| Feature | DC motor | Gear motor | Servo motor |
|---|---|---|---|
| Motion type | Continuous rotation | Continuous rotation | Angle positioning |
| Speed | Very fast | Moderate to slow | Moderate |
| Torque | Low | High | Moderate |
| Control | Voltage polarity | Voltage polarity | PWM signal |
| Position feedback | None | None | Built-in |
| Driver needed | Yes | Yes | No (for small servos) |
| Best for | Fans, spinners | Wheels, mechanisms | Gates, arms, pointers |

## Motor polarity and direction

### Simple direction rule

```text
+V → Motor terminal A → Motor terminal B → GND  ===  Forward
+V → Motor terminal B → Motor terminal A → GND  ===  Reverse
```

An H-bridge motor driver can swap polarity electronically without physically
rewiring.

## Motor specifications to check

Before using a motor:

1. **Rated voltage:** Don't exceed it (e.g., don't put 12V on a 6V motor).
2. **No-load current:** Current when spinning freely.
3. **Stall current:** Maximum current when motor is blocked (very high!).
4. **No-load speed:** RPM when spinning freely.
5. **Stall torque:** Maximum force the motor can apply.

## Flyback diodes

When a motor is suddenly turned off, the collapsing magnetic field creates
a voltage spike. A **flyback diode** (like 1N4007) placed across the motor
terminals absorbs this spike.

```text
Motor terminal A ──┬── to driver
                   │
              ┌────┴────┐
              │  Diode   │  (cathode toward +)
              └────┬────┘
                   │
Motor terminal B ──┴── to driver
```

Most motor driver modules (L298N) include these diodes internally.
