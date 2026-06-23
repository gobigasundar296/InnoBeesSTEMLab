# Chapter 4: H-Bridge and Motor Driver Modules

## What is an H-Bridge?

An H-bridge is a circuit that can drive a motor in both directions by
controlling four switches arranged in an "H" shape.

```text
    +V                    +V
     │                     │
   ┌─┴─┐               ┌─┴─┐
   │S1 │               │S2 │
   └─┬─┘               └─┬─┘
     │                     │
     ├─── Motor Terminal A ┤
     │         ⚡          │
     ├─── Motor Terminal B ┤
     │                     │
   ┌─┴─┐               ┌─┴─┐
   │S3 │               │S4 │
   └─┬─┘               └─┬─┘
     │                     │
    GND                   GND
```

### How it controls direction

| S1 | S2 | S3 | S4 | Result |
|---|---|---|---|---|
| ON | OFF | OFF | ON | Motor forward |
| OFF | ON | ON | OFF | Motor reverse |
| OFF | OFF | OFF | OFF | Motor coast (free spin) |
| ON | OFF | ON | OFF | Motor brake (short circuit!) |

In practice, the motor driver IC handles this with simple input pins.

## L298N Motor Driver Module

The L298N is the most common beginner motor driver. It can control **two DC
motors** independently.

### Specifications

| Parameter | Value |
|---|---|
| Motor supply voltage | 5-35 V |
| Logic voltage | 5 V |
| Max current per channel | 2 A |
| Number of motors | 2 DC motors (or 1 stepper) |
| Control | 2 direction pins + 1 enable (PWM) per motor |

### Pin layout

| L298N pin | Function | Connect to |
|---|---|---|
| VMS / +12V | Motor power supply input | Battery + (6-12V) |
| GND | Common ground | Battery - AND Arduino GND |
| 5V | Logic power (output if jumper on) | Arduino 5V (or leave) |
| IN1 | Motor A direction 1 | Arduino digital pin |
| IN2 | Motor A direction 2 | Arduino digital pin |
| ENA | Motor A enable (speed) | Arduino PWM pin |
| IN3 | Motor B direction 1 | Arduino digital pin |
| IN4 | Motor B direction 2 | Arduino digital pin |
| ENB | Motor B enable (speed) | Arduino PWM pin |
| OUT1, OUT2 | Motor A terminals | Motor A wires |
| OUT3, OUT4 | Motor B terminals | Motor B wires |

### The 5V jumper

- **Jumper ON:** The board's onboard regulator provides 5V to the logic
  circuit. VMS must be 7V or higher. The 5V pin becomes an OUTPUT (can
  power Arduino).
- **Jumper OFF:** You must supply 5V separately to the 5V pin for logic.
  Use this when motor supply is below 7V.

### Direction control logic

| IN1 | IN2 | Motor A action |
|---|---|---|
| HIGH | LOW | Forward |
| LOW | HIGH | Reverse |
| LOW | LOW | Stop (coast) |
| HIGH | HIGH | Brake |

### Speed control

The ENA pin controls speed via PWM:

- `analogWrite(ENA, 0)` = stopped
- `analogWrite(ENA, 128)` = half speed
- `analogWrite(ENA, 255)` = full speed

If ENA has its jumper cap on, the motor runs at full speed whenever IN1/IN2
command a direction. Remove the jumper and connect to a PWM pin for speed
control.

## L293D Motor Driver IC

The L293D is a smaller, breadboard-friendly alternative.

### Specifications

| Parameter | Value |
|---|---|
| Motor supply voltage | 4.5-36 V |
| Logic voltage | 5 V |
| Max current per channel | 600 mA |
| Number of motors | 2 DC motors |
| Package | 16-pin DIP |
| Built-in diodes | Yes (L293D version) |

### Pin functions

| Pin | Function |
|---|---|
| 1 (Enable 1,2) | Enable Motor A (PWM for speed) |
| 2 (Input 1) | Motor A direction 1 |
| 3 (Output 1) | Motor A terminal 1 |
| 4, 5 (GND) | Ground |
| 6 (Output 2) | Motor A terminal 2 |
| 7 (Input 2) | Motor A direction 2 |
| 8 (VS) | Motor power supply |
| 9 (Enable 3,4) | Enable Motor B |
| 10-15 | Mirror of pins 2-7 for Motor B |
| 16 (VSS) | Logic power (5V) |

## Wiring example: L298N with one motor

```text
Battery 9V (+) → L298N VMS
Battery 9V (-) → L298N GND → Arduino GND
Arduino D5 (PWM) → L298N ENA (remove jumper cap)
Arduino D6 → L298N IN1
Arduino D7 → L298N IN2
L298N OUT1 → Motor wire 1
L298N OUT2 → Motor wire 2
```

## Arduino code: L298N motor control

```cpp
const int ENA = 5;   // PWM speed control
const int IN1 = 6;   // direction
const int IN2 = 7;   // direction

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void motorForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

void motorReverse(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void loop() {
  motorForward(200);
  delay(3000);
  motorStop();
  delay(1000);
  motorReverse(150);
  delay(3000);
  motorStop();
  delay(1000);
}
```

## Common ground rule

**Critical:** The battery GND and Arduino GND must be connected together.
Without a common ground, the control signals have no reference and the motor
driver will not work.

```text
Battery (-) ─── L298N GND ─── Arduino GND
```

## Safety notes

- Never exceed the motor driver's voltage or current rating.
- Never swap motor power supply polarity on the driver.
- If the motor stalls (blocked), disconnect power quickly — stall current
  can overheat the driver.
- The L298N has a heat sink — it gets warm during normal operation. This is
  expected, but if it's too hot to touch, reduce the load.
