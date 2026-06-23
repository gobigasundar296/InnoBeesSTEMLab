# Chapter 6: Motor Projects with Sensors

## Combining sensors and motors

The real power of motion control comes from combining what we learned in
previous sessions:

- **Session 2:** Sensors detect conditions.
- **Session 3:** Outputs communicate information.
- **Session 5:** Motors create physical action.

Now we combine them: sensors trigger motors to create intelligent machines.

## Project 1: Automatic Gate

### Concept

An ultrasonic sensor detects when a person approaches. A servo motor opens
the gate automatically and closes after a delay.

### Components

- Arduino Uno
- HC-SR04 ultrasonic sensor
- SG90 servo motor
- LED (green = open, red = closed)

### Behavior

```text
Person approaches (< 30 cm) → Gate opens (servo 90°) → Green LED on
Wait 5 seconds → Person leaves → Gate closes (servo 0°) → Red LED on
```

### Code

```cpp
#include <Servo.h>

Servo gateServo;
const int TRIG = 9;
const int ECHO = 10;
const int SERVO_PIN = 6;
const int GREEN_LED = 4;
const int RED_LED = 5;

const int OPEN_DISTANCE = 30;  // cm
bool gateOpen = false;

void setup() {
  gateServo.attach(SERVO_PIN);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  gateServo.write(0);
  digitalWrite(RED_LED, HIGH);
  Serial.begin(9600);
  Serial.println("Automatic Gate Ready");
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH, 30000);
  if (duration == 0) return 999;
  return (duration * 0.034) / 2.0;
}

void openGate() {
  if (!gateOpen) {
    for (int a = 0; a <= 90; a++) {
      gateServo.write(a);
      delay(15);
    }
    gateOpen = true;
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    Serial.println("Gate OPEN");
  }
}

void closeGate() {
  if (gateOpen) {
    for (int a = 90; a >= 0; a--) {
      gateServo.write(a);
      delay(15);
    }
    gateOpen = false;
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    Serial.println("Gate CLOSED");
  }
}

void loop() {
  float dist = getDistance();
  Serial.print("Distance: ");
  Serial.println(dist);

  if (dist < OPEN_DISTANCE && dist > 0) {
    openGate();
    delay(5000);  // keep open for 5 seconds
  } else {
    closeGate();
  }
  delay(200);
}
```

## Project 2: Smart Fan Controller

### Concept

A DC motor (with fan blade) automatically adjusts speed based on ambient
light or temperature. Brighter/hotter = faster fan.

### Using LDR (light-based)

```text
Bright light (hot day simulation) → Fan spins fast
Dim light (cool day simulation) → Fan spins slow or off
```

### Components

- Arduino Uno
- L298N motor driver
- Small DC motor with fan blade
- LDR + 10k resistor (voltage divider)
- 9V battery

### Code

```cpp
const int ENA = 5;   // PWM speed
const int IN1 = 6;   // direction
const int IN2 = 7;   // direction
const int LDR_PIN = A0;

const int FAN_OFF_THRESHOLD = 200;
const int FAN_MAX_THRESHOLD = 800;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  digitalWrite(IN1, HIGH);  // always forward
  digitalWrite(IN2, LOW);
  Serial.begin(9600);
  Serial.println("Smart Fan Controller Active");
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);

  int fanSpeed;
  if (lightLevel < FAN_OFF_THRESHOLD) {
    fanSpeed = 0;
  } else if (lightLevel > FAN_MAX_THRESHOLD) {
    fanSpeed = 255;
  } else {
    fanSpeed = map(lightLevel, FAN_OFF_THRESHOLD, FAN_MAX_THRESHOLD, 60, 255);
  }

  analogWrite(ENA, fanSpeed);

  Serial.print("Light: ");
  Serial.print(lightLevel);
  Serial.print(" → Fan speed: ");
  Serial.println(fanSpeed);
  delay(300);
}
```

## Project 3: Parking Barrier

### Concept

A vehicle approaches → ultrasonic detects it → servo raises the barrier.
When the vehicle passes, the barrier lowers.

Similar to the Automatic Gate but oriented as a horizontal barrier arm.

## Project 4: Conveyor Belt (demonstration)

### Concept

A DC motor drives a conveyor belt. Objects are detected by an ultrasonic
sensor at the end. The belt stops when an object reaches the end position.

### Behavior

```text
Start belt → Object placed on belt → Belt moves object →
Ultrasonic detects object at end → Belt stops → Buzzer alerts
```

## Project 5: Robot arm joint (advanced)

### Concept

Control a servo-based joint using a potentiometer as a "master" control:

```cpp
#include <Servo.h>

Servo armJoint;
const int POT_PIN = A0;

void setup() {
  armJoint.attach(9);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int angle = map(potValue, 0, 1023, 0, 180);
  armJoint.write(angle);
  delay(15);
}
```

Turn the potentiometer → the servo follows in real-time. This is the
principle behind remote-operated robotic arms.

## Design challenge: Motion-Based Solution

Teams identify a problem that can be solved with a motor:

| Problem | Sensor | Motor type | Behavior |
|---|---|---|---|
| Automatic door | PIR or ultrasonic | Servo | Open when approached |
| Smart vent | Temperature sensor | Servo | Open when hot |
| Auto-watering | Soil moisture | DC motor (pump) | Pump when dry |
| Smart blinds | LDR | DC motor + gears | Close when bright |
| Alert flag | Sound sensor | Servo | Raise flag on loud noise |

### Design requirements

1. Clearly state the problem.
2. Choose appropriate sensor and motor.
3. Define threshold values.
4. Write pseudocode for the behavior.
5. Build and demonstrate the system.
6. Explain one improvement you would make.
