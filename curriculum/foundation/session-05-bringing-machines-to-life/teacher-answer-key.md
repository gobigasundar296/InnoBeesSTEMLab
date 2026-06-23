# Teacher Answer Key: Session 5 Workbook

## Part A

1. Maximum 20 mA per I/O pin.

2. Typically 100-500 mA (varies by motor).

3. The pin cannot supply enough current — the motor barely moves or doesn't
   spin at all. The Arduino pin may overheat or be damaged. Motor back-EMF
   noise may reset the Arduino.

4. (1) Amplifies the small Arduino signal to provide high motor current.
   (2) Isolates Arduino from motor noise and back-EMF.
   (3) Controls motor direction and speed.

5. Arduino (brain) → control signal → Motor Driver (muscle) → power → Motor.
   Arduino powered by USB/computer. Motor Driver powered by battery.

## Part B

1. DC motor: continuous rotation, very fast, low torque, no position
   control, driver needed, best for fans/spinners.
   Gear motor: continuous rotation, moderate/slow, high torque, no position
   control, driver needed, best for wheels/mechanisms.
   Servo: angle positioning, moderate, moderate torque, yes position
   control, no driver (small), best for gates/arms.

2. Trades speed for torque.

3. Speed is 1/48 of DC motor speed. Torque is 48× DC motor torque.

## Part C

1. VMS=Battery positive (6-12V). GND=Battery negative AND Arduino GND.
   IN1=Arduino digital pin. IN2=Arduino digital pin. ENA=Arduino PWM pin.
   OUT1/OUT2=Motor terminals.

2. HIGH/LOW=Forward. LOW/HIGH=Reverse. LOW/LOW=Stop (coast).

3. Without common ground, the logic signals have no voltage reference.
   The motor driver cannot interpret HIGH and LOW correctly.

4. PWM 0=stopped. PWM 128=approximately half speed. PWM 255=full speed.

## Part D

1. Converts a value from the range 0-1023 to the range 0-255. Used to
   translate analog sensor readings to PWM output values.

2. Values vary by setup. Key: pot minimum → low/zero motor speed,
   pot maximum → full motor speed.

3. Typically 50-80 for most hobby motors. Accept any value the student
   actually measured.

## Part E

Challenge 1: Ultrasonic sensor (HC-SR04), servo motor. Threshold typically
20-40 cm. Gate should open smoothly (using for loop), close after delay.

Challenge 2: LDR (or potentiometer for testing), DC motor with L298N.
Students should identify three zones with different speeds.

Challenge 3: Assess based on:
- Clear problem definition.
- Appropriate sensor and motor choice.
- Threshold values determined experimentally.
- Pseudocode shows logical flow.
- System demonstration works (or near-works with identified issue).

## Part F

1. A servo moves to a specific angle and holds; a DC motor spins
   continuously without position control.

2. Gear motors provide higher torque needed to move the robot body/wheels,
   while regular DC motors spin too fast with too little force.

3. Examples: Washing machine (water level sensor + spin motor), automatic
   door (PIR sensor + door motor), car wipers (rain sensor + wiper motor),
   elevator (floor sensor + lift motor).
