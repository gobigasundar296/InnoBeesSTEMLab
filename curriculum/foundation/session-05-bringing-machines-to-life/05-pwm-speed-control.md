# Chapter 5: Speed Control with PWM

## Review: PWM basics

PWM (Pulse Width Modulation) rapidly switches a pin between HIGH and LOW.
The ratio of ON time to total time is the **duty cycle**.

```text
100% duty (255): ████████████████  Full speed
 75% duty (191): ████████████░░░░  
 50% duty (127): ████████░░░░░░░░  Half speed
 25% duty (64):  ████░░░░░░░░░░░░  
  0% duty (0):   ░░░░░░░░░░░░░░░░  Stopped
```

## PWM for motor speed

When we apply PWM to the motor driver's enable pin:

- The motor receives power in bursts.
- Higher duty cycle = more average power = faster speed.
- Lower duty cycle = less average power = slower speed.
- The motor's inertia smooths out the pulsing — it doesn't jerk.

```cpp
analogWrite(ENA, 64);   // ~25% speed
analogWrite(ENA, 128);  // ~50% speed
analogWrite(ENA, 192);  // ~75% speed
analogWrite(ENA, 255);  // 100% speed
```

## Minimum starting speed

Most motors have a **minimum PWM value** below which they don't have enough
torque to start spinning. This varies by motor and load.

Typical range for hobby motors: PWM 50-80 is usually the minimum to start
moving. Below that, the motor hums but doesn't spin.

**Tip:** Test your motor to find its minimum starting value:

```cpp
for (int speed = 0; speed <= 255; speed += 5) {
  analogWrite(ENA, speed);
  Serial.print("Speed: ");
  Serial.println(speed);
  delay(500);
}
```

## Speed control from a potentiometer

A potentiometer provides variable analog input (0-1023). Map it to PWM
range (0-255) for intuitive speed control:

```cpp
const int POT_PIN = A0;
const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);
  analogWrite(ENA, motorSpeed);

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print(" → Speed: ");
  Serial.println(motorSpeed);
  delay(100);
}
```

## The map() function

`map(value, fromLow, fromHigh, toLow, toHigh)` converts a number from one
range to another.

| Input range | Output range | Example |
|---|---|---|
| 0-1023 (analog read) | 0-255 (PWM) | Pot → motor speed |
| 0-1023 (analog read) | 0-180 (servo) | Pot → servo angle |
| 2-400 (ultrasonic cm) | 255-0 (PWM) | Distance → buzzer intensity |

## Speed ramp (acceleration and deceleration)

Sudden speed changes can cause mechanical stress. Ramp speed gradually:

```cpp
void accelerate(int targetSpeed, int rampTime) {
  int currentSpeed = 0;
  int steps = targetSpeed;
  int stepDelay = rampTime / steps;

  for (int s = 0; s <= targetSpeed; s++) {
    analogWrite(ENA, s);
    delay(stepDelay);
  }
}

void decelerate(int currentSpeed, int rampTime) {
  int steps = currentSpeed;
  int stepDelay = rampTime / steps;

  for (int s = currentSpeed; s >= 0; s--) {
    analogWrite(ENA, s);
    delay(stepDelay);
  }
}
```

## Speed zones based on sensor input

Combine distance sensor with motor speed for smart behavior:

```cpp
float distance = getDistance();  // from ultrasonic sensor

if (distance > 100) {
  analogWrite(ENA, 255);  // far away: full speed
} else if (distance > 50) {
  analogWrite(ENA, 150);  // medium: moderate speed
} else if (distance > 20) {
  analogWrite(ENA, 80);   // close: slow speed
} else {
  analogWrite(ENA, 0);    // very close: stop!
}
```

## PWM frequency consideration

Arduino Uno PWM frequency:

- Pins D5, D6: ~980 Hz
- Pins D3, D9, D10, D11: ~490 Hz

For most hobby motors, both frequencies work fine. Some motors may produce
an audible whine at certain PWM frequencies — this is normal and not harmful.

## Braking vs. coasting

| Method | How | Result |
|---|---|---|
| Coast | Set IN1=LOW, IN2=LOW | Motor spins freely, slows gradually |
| Brake | Set IN1=HIGH, IN2=HIGH | Motor terminals shorted, stops quickly |
| PWM stop | Set ENA=0 | Same as coast (no power) |

For precise stopping (like a conveyor belt), use brake mode.
For smooth deceleration, use coast with ramp-down.
