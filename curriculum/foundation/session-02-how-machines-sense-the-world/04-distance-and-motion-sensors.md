# Chapter 4: Distance and Motion — Ultrasonic and PIR Sensors

## HC-SR04 Ultrasonic Sensor

The HC-SR04 measures distance by sending an ultrasonic pulse and measuring
the time it takes for the echo to return.

### How it works

1. The Arduino sends a short HIGH pulse (10 microseconds) to the TRIG pin.
2. The sensor emits eight 40 kHz ultrasonic pulses from the transmitter.
3. The pulses travel through air, hit an object, and bounce back.
4. The receiver detects the reflected pulses.
5. The ECHO pin goes HIGH for the duration the sound traveled.
6. The Arduino measures this pulse duration to calculate distance.

### Distance formula

```text
Distance (cm) = (Time in microseconds × 0.034) / 2
```

The speed of sound in air is approximately 340 m/s (0.034 cm/µs). We divide
by 2 because the sound travels to the object and back.

### Specifications

| Parameter | Value |
|---|---|
| Operating voltage | 5 V |
| Measuring range | 2 cm to 400 cm |
| Measuring angle | ~15 degrees |
| Trigger pulse | 10 µs HIGH |
| Echo pulse | proportional to distance |

### Connections

| HC-SR04 pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| TRIG | Arduino digital pin (e.g., D9) |
| ECHO | Arduino digital pin (e.g., D10) |

### Arduino program

```cpp
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  float distance = (duration * 0.034) / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(200);
}
```

### Common issues

- **Out of range:** If no echo returns, `pulseIn()` times out. Add a timeout
  parameter: `pulseIn(ECHO_PIN, HIGH, 30000)`.
- **Soft surfaces:** Fabrics and foam absorb sound and may give weak echoes.
- **Angles:** The object must be roughly perpendicular to the sensor face.
- **Minimum distance:** Below 2 cm, readings are unreliable.

## HC-SR501 PIR Motion Sensor

PIR (Passive Infrared) sensors detect movement of warm bodies (humans,
animals) by sensing changes in infrared radiation.

### How it works

1. All objects above absolute zero emit infrared radiation.
2. The PIR sensor has a pyroelectric element that generates voltage when
   infrared radiation changes.
3. The Fresnel lens on the front focuses infrared from different zones.
4. When a warm body moves across zones, the sensor detects the change.
5. The output pin goes HIGH for a set duration (adjustable with a
   potentiometer).

**Important:** PIR detects *motion* (change), not presence. A stationary
person will not trigger it again until they move.

### Specifications

| Parameter | Value |
|---|---|
| Operating voltage | 5-20 V (typically 5 V) |
| Output | Digital HIGH (3.3 V) when triggered |
| Detection range | Up to 7 meters |
| Detection angle | ~120 degrees |
| Delay time | Adjustable (seconds to minutes) |
| Sensitivity | Adjustable via potentiometer |

### Connections

| HC-SR501 pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| OUT | Arduino digital pin (e.g., D4) |

### Warm-up time

The HC-SR501 needs 30-60 seconds after power-on to stabilize. During this
time, it may give false readings. Wait for stabilization before trusting
the output.

### Arduino program: visitor alert

```cpp
const int PIR_PIN = 4;
const int BUZZER_PIN = 7;
const int LED_PIN = 8;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR warming up... wait 30 seconds");
  delay(30000);
  Serial.println("PIR ready!");
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2000);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}
```

### Adjustments on HC-SR501

The module has two potentiometers:

1. **Sensitivity (Sx):** Adjust detection range (closer or farther).
2. **Time delay (Tx):** Adjust how long the output stays HIGH after
   detection (from a few seconds to several minutes).

There is also a jumper for retriggering mode:

- **H (repeatable trigger):** Output stays HIGH as long as motion continues.
- **L (single trigger):** Output goes HIGH once, then LOW, then waits before
  it can trigger again.

## Combining sensors: distance zones

A parking-assist style system using the ultrasonic sensor:

```cpp
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_GREEN = 5;
const int LED_YELLOW = 6;
const int LED_RED = 7;
const int BUZZER_PIN = 8;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  return (duration * 0.034) / 2.0;
}

void loop() {
  float dist = getDistance();
  Serial.print("Distance: ");
  Serial.println(dist);

  // Turn off all
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  if (dist > 0 && dist < 10) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else if (dist < 30) {
    digitalWrite(LED_YELLOW, HIGH);
  } else if (dist < 100) {
    digitalWrite(LED_GREEN, HIGH);
  }
  delay(200);
}
```
