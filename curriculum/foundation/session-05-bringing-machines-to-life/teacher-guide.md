# Teacher Guide: Bringing Machines to Life

## Why this module matters

Motion is what transforms electronics from displays and beeps into machines
that physically interact with the world. This session completes the
sensor-process-actuate loop and gives students the skills to build robots,
automated gates, smart fans, and mechanical systems.

## Recommended delivery

### Block 1 - Understanding motors (50 minutes)

- Review: complete system (sensor → brain → actuator): 5 minutes
- Why motors need drivers (current demonstration): 15 minutes
- Servo motor review and smooth movement: 10 minutes
- DC motor and gear motor physical comparison: 10 minutes
- H-bridge concept and L298N wiring: 10 minutes

### Block 2 - Hands-on motor control (70 minutes)

- Hands-on: DC motor with L298N — forward, reverse, stop: 20 minutes
- PWM speed control with potentiometer: 15 minutes
- Hands-on: Automatic Gate (ultrasonic + servo): 20 minutes
- Hands-on: Smart Fan Controller (LDR + DC motor): 15 minutes

### Extended Block (optional 60 minutes)

- Speed ramp (acceleration/deceleration): 10 minutes
- Sensor-based speed zones: 10 minutes
- Challenge: Design a Motion-Based Solution: 30 minutes
- Presentations: 10 minutes

## Pre-session preparation

### Hardware setup

- Pre-test all DC motors to confirm they spin with direct battery connection.
- Pre-wire one L298N demo board for live demonstration.
- Ensure all batteries are fresh (weak batteries cause confusing behavior).
- Have spare motors — students occasionally reverse-polarity the driver.
- Attach fan blades to motors in advance (hot glue or press-fit).

### Key demonstration

**Why a driver is needed:**

1. Connect an LED to a digital pin → works (10 mA).
2. Try connecting a motor directly to a pin → barely moves or doesn't.
3. Measure motor current with ammeter → shows 200+ mA.
4. "The pin can only give 20 mA. The motor needs 200 mA. We need a helper."
5. Introduce the L298N: "It takes Arduino's command and uses battery power
   to drive the motor."

## Teaching method

For motor projects:

1. **Observe:** Show the physical motor. Spin it by hand. Identify terminals.
2. **Explain:** Why direct connection fails. What the driver does.
3. **Wire:** Connect with power OFF. Check all connections.
4. **Test:** Run basic forward/reverse code.
5. **Control:** Add speed control with PWM.
6. **Integrate:** Add sensor for automatic behavior.

## Common misconceptions to correct

- **Motors are like LEDs but bigger.** Motors draw much more current, create
  back-EMF, and have inertia. They require fundamentally different driving.
- **Faster = better.** Gear motors show that slower with more torque is often
  more useful than fast with no pushing power.
- **The L298N powers the Arduino.** It can, but the primary purpose is to
  provide motor power from a battery. Keep the concepts of logic power and
  motor power separate.
- **PWM makes the motor pulse.** Due to inertia, the motor smoothly varies
  speed rather than jerking on/off.
- **All motors go to exact positions.** Only servos do. DC motors spin
  continuously without position feedback.

## Safety briefing

Before the lab, students confirm:

> I will always wire with power disconnected. I will not stall the motor
> intentionally. I will keep fingers and hair away from spinning shafts.

Teacher checks:

- Battery polarity is correct on L298N (VMS=+, GND=-).
- Common ground between Arduino and motor driver.
- No loose wires near spinning motor shafts.
- Fan blades are secure and balanced.
- Students wear safety glasses if using exposed spinning shafts.

## Assessment evidence

Students should be able to:

- explain why a motor cannot connect directly to an Arduino I/O pin;
- describe the difference between a DC motor and a servo motor;
- explain what a gear motor trades (speed for torque);
- identify the role of IN1, IN2, and ENA on an L298N;
- control motor direction and speed with code;
- combine a sensor reading with motor control for automatic behavior;
- use `map()` to convert sensor range to motor speed range.

## Suggested team roles

- **Mechanical engineer:** handles motor mounting and connections.
- **Electrical engineer:** wires the motor driver and checks power.
- **Programmer:** writes and uploads motor control code.
- **Sensor specialist:** connects and calibrates the trigger sensor.
- **Quality tester:** verifies system behavior matches design.

## Final challenge: Design a Motion-Based Solution

Teams identify a real problem and solve it with motion:

Requirements:

- Uses at least one motor (servo or DC).
- Triggered or controlled by at least one sensor.
- Has defined threshold values (tested with Serial Monitor).
- Includes a status indicator (LED or buzzer).
- Team presents: problem, solution, demonstration, one improvement.

Judging criteria:

| Criterion | Points |
|---|---|
| Problem clearly defined | 2 |
| Appropriate motor choice | 2 |
| Sensor integration works | 3 |
| Code is functional | 3 |
| Presentation quality | 2 |
| Creativity | 2 |
