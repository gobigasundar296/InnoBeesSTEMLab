# Student Workbook: Bringing Machines to Life

**Name:** _________________________  
**Class:** _________________________  
**Team:** _________________________  
**Date:** _________________________

## Safety promise

Tick each rule before starting.

- [ ] I will disconnect power before changing any wires.
- [ ] I will not connect a motor directly to an Arduino I/O pin.
- [ ] I will keep fingers and hair away from spinning motor shafts.
- [ ] I will check battery polarity before connecting to the motor driver.
- [ ] I will not intentionally stall (block) a running motor.
- [ ] I will ask the teacher before testing with higher voltage batteries.

## Part A - Why motors need drivers

### 1. What is the maximum current an Arduino I/O pin can provide?

_______ mA

### 2. How much current does a typical small DC motor need?

_______ mA

### 3. What happens if you connect a motor directly to an Arduino pin?

____________________________________________________________________

____________________________________________________________________

### 4. What does a motor driver do? (three functions)

1. ________________________________________________________________
2. ________________________________________________________________
3. ________________________________________________________________

### 5. Draw the power flow diagram

```text
[_________] → control signal → [___________] → power → [_______]
  (brain)                        (muscle)                (moves)
      ↑                              ↑
  _________                    ___________
  (power source)              (power source)
```

## Part B - Motor types comparison

### 1. Fill in the table

| Feature | DC motor | Gear motor | Servo motor |
|---|---|---|---|
| Motion type | | | |
| Speed | | | |
| Torque | | | |
| Position control | | | |
| Driver needed? | | | |
| Best application | | | |

### 2. What does a gearbox do?

It trades _____________ for _____________.

### 3. A gear motor with ratio 1:48 means:

Speed is _______ of the DC motor speed.

Torque is _______ of the DC motor torque.

## Part C - Motor driver (L298N)

### 1. Label the connections

| L298N pin | What to connect |
|---|---|
| VMS (+12V) | |
| GND | |
| IN1 | |
| IN2 | |
| ENA | |
| OUT1, OUT2 | |

### 2. Direction control

| IN1 | IN2 | Motor does |
|---|---|---|
| HIGH | LOW | |
| LOW | HIGH | |
| LOW | LOW | |

### 3. Why must Arduino GND connect to the motor driver GND?

____________________________________________________________________

### 4. What happens to motor speed when you change the ENA PWM value?

`analogWrite(ENA, 0)` → motor speed: _____________

`analogWrite(ENA, 128)` → motor speed: _____________

`analogWrite(ENA, 255)` → motor speed: _____________

## Part D - Speed control with PWM

### 1. What does `map(value, 0, 1023, 0, 255)` do?

____________________________________________________________________

### 2. Potentiometer speed control

Turn the pot and record:

| Pot position | analogRead value | Motor speed (PWM) | Motor behavior |
|---|---|---|---|
| Minimum | | | |
| Middle | | | |
| Maximum | | | |

### 3. What is the minimum PWM value that makes your motor start spinning?

PWM value: _______

## Part E - Build challenges

### Challenge 1: Automatic Gate

**Objective:** Gate opens when person approaches, closes when they leave.

Sensor used: _________________________

Motor used: _________________________

Open distance threshold: _______ cm

Observations:

- Does the gate open smoothly? ____________
- Does it close reliably? ____________
- How long does it stay open? ____________ seconds

What would you improve?

____________________________________________________________________

### Challenge 2: Smart Fan Controller

**Objective:** Fan speed adjusts automatically based on light/heat level.

Sensor used: _________________________

Motor used: _________________________

| Sensor reading | Fan speed | Behavior |
|---|---|---|
| Low value (dark/cool) | | |
| Medium value | | |
| High value (bright/hot) | | |

Threshold values:
- Fan OFF below: _______
- Fan MAX above: _______

### Challenge 3: Motion-Based Solution (team challenge)

**Problem you are solving:**

____________________________________________________________________

**Components:**

| Component | Role in system |
|---|---|
| Sensor: | |
| Motor: | |
| Indicator: | |

**Threshold values (from Serial Monitor testing):**

____________________________________________________________________

**Pseudocode (step-by-step logic):**

```text
1. 
2. 
3. 
4. 
5. 
```

**Did it work?** ____________

**One improvement you would make:**

____________________________________________________________________

## Part F - Reflection

### 1. What is the difference between a servo and a DC motor in one sentence?

____________________________________________________________________

### 2. Why are gear motors used in robots instead of regular DC motors?

____________________________________________________________________

### 3. Name one machine in daily life that uses a motor with a sensor.

Machine: __________________________

Sensor: __________________________

Motor action: __________________________
