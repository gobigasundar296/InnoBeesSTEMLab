# Chapter 2: Servo Motors — Precision Positioning

## Review from Session 3

A servo motor rotates to a **specific angle** and holds that position.
We used `Servo.write(angle)` to command positions from 0° to 180°.

## How a servo achieves precision

Inside the servo:

```text
┌────────────────────────────────┐
│  Signal → Control Circuit      │
│              ↓                  │
│       Compare desired vs.      │
│       actual position          │
│              ↓                  │
│       DC Motor + Gears         │
│              ↓                  │
│       Position Sensor (pot)    │
│              ↓                  │
│       Feedback to control      │
└────────────────────────────────┘
```

This is a **closed-loop** system — the servo continuously checks its position
and corrects itself.

## Servo signal details

The servo expects a PWM signal at 50 Hz (one pulse every 20 ms):

| Pulse width | Angle |
|---|---|
| ~0.5 ms | 0° |
| ~1.0 ms | 45° |
| ~1.5 ms | 90° (center) |
| ~2.0 ms | 135° |
| ~2.5 ms | 180° |

Arduino's `Servo` library handles this automatically.

## Multiple servo positions

```cpp
#include <Servo.h>

Servo gateServo;
const int SERVO_PIN = 9;

void setup() {
  gateServo.attach(SERVO_PIN);
}

void openGate() {
  gateServo.write(90);   // 90° = open
}

void closeGate() {
  gateServo.write(0);    // 0° = closed
}

void halfOpen() {
  gateServo.write(45);   // 45° = partially open
}
```

## Smooth servo movement

Instead of jumping instantly, move gradually for realistic motion:

```cpp
void smoothMove(Servo &servo, int targetAngle, int stepDelay) {
  int current = servo.read();

  if (current < targetAngle) {
    for (int a = current; a <= targetAngle; a++) {
      servo.write(a);
      delay(stepDelay);
    }
  } else {
    for (int a = current; a >= targetAngle; a--) {
      servo.write(a);
      delay(stepDelay);
    }
  }
}
```

A `stepDelay` of 15-20 ms gives smooth, visible motion.

## Servo applications in this session

| Application | Closed angle | Open angle | Trigger |
|---|---|---|---|
| Automatic gate | 0° | 90° | Ultrasonic < 30 cm |
| Parking barrier | 0° | 80° | Button press |
| Pet feeder | 0° | 45° | Timer or phone command |
| Bin lid | 0° | 60° | Hand wave (PIR/ultrasonic) |
| Traffic barrier | 0° | 90° | Sensor detection |

## Servo power considerations

| Scenario | Power source |
|---|---|
| 1 SG90, light load | Arduino 5V pin (USB) |
| 1 SG90, heavy load | External 5V, 1A supply |
| 2-3 SG90 servos | External 5V, 2A supply |
| Large servo (MG996R) | External 6V, 2A supply |

**Always connect GND** between external supply and Arduino.

## Servo jitter

If the servo vibrates/jitters at rest:

1. **Cause:** Noisy power supply or signal interference.
2. **Fix 1:** Add a 100µF capacitor across servo power wires.
3. **Fix 2:** Use `servo.detach()` when position holding isn't needed.
4. **Fix 3:** Use a dedicated power supply.

## Continuous rotation servos

Some servos are modified for continuous rotation:

- `write(90)` = stop
- `write(0)` = full speed one direction
- `write(180)` = full speed other direction

These are essentially speed-controlled motors, not position-controlled. They
are useful for wheels on small robots.
