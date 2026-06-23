# Chapter 6: Arduino Sensor Programs

## Key Arduino functions for sensors

### digitalRead(pin)

Reads the state of a digital pin. Returns `HIGH` or `LOW`.

```cpp
int state = digitalRead(4);
```

Use for: push buttons, touch sensors, PIR output, flame sensor digital
output, sound sensor digital output.

### analogRead(pin)

Reads the voltage on an analog pin and converts it to a number between
0 and 1023.

```cpp
int value = analogRead(A0);
```

- 0 means 0 V at the pin.
- 1023 means approximately 5 V at the pin (on a 5 V Arduino).

Use for: LDR voltage divider, soil moisture analog output, sound sensor
analog output, flame sensor analog output.

### pulseIn(pin, value)

Measures the duration of a pulse on a pin. Returns time in microseconds.

```cpp
long duration = pulseIn(ECHO_PIN, HIGH);
```

Use for: HC-SR04 ultrasonic sensor echo measurement.

### Serial.begin(baud) and Serial.println(data)

Opens serial communication and prints data to the Serial Monitor for
observation and debugging.

```cpp
Serial.begin(9600);
Serial.println(sensorValue);
```

## Program 1: Button-controlled LED

```cpp
// Push button on D2 (INPUT_PULLUP), LED on D8
const int BUTTON_PIN = 2;
const int LED_PIN = 8;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
```

## Program 2: Touch sensor toggle

```cpp
// Touch sensor on D3, LED on D8
const int TOUCH_PIN = 3;
const int LED_PIN = 8;
bool ledState = false;
bool lastTouch = false;

void setup() {
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  bool currentTouch = digitalRead(TOUCH_PIN);

  if (currentTouch && !lastTouch) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    delay(50);
  }
  lastTouch = currentTouch;
}
```

## Program 3: LDR smart street light

```cpp
// LDR voltage divider on A0, LED on D8
const int LDR_PIN = A0;
const int LED_PIN = 8;
const int DARK_THRESHOLD = 300;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  Serial.print("Light: ");
  Serial.println(lightLevel);

  if (lightLevel < DARK_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Street light ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Street light OFF");
  }
  delay(500);
}
```

## Program 4: Ultrasonic distance with Serial Monitor

```cpp
// HC-SR04: TRIG on D9, ECHO on D10
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return (duration * 0.034) / 2.0;
}

void loop() {
  float distance = measureDistance();

  if (distance > 0) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("Out of range");
  }
  delay(250);
}
```

## Program 5: PIR visitor alert

```cpp
// PIR on D4, buzzer on D7, LED on D8
const int PIR_PIN = 4;
const int BUZZER_PIN = 7;
const int LED_PIN = 8;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Warming up PIR sensor...");
  delay(30000);
  Serial.println("System ready!");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    Serial.println("*** VISITOR DETECTED ***");
    digitalWrite(LED_PIN, HIGH);
    // Three short beeps
    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(500);
}
```

## Program 6: Multi-sensor smart classroom

```cpp
// LDR on A0, PIR on D4, sound on D5, LED on D8, buzzer on D7
const int LDR_PIN = A0;
const int PIR_PIN = 4;
const int SOUND_PIN = 5;
const int BUZZER_PIN = 7;
const int LED_PIN = 8;

const int DARK_THRESHOLD = 300;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Smart Classroom initializing...");
  delay(30000);
  Serial.println("System active!");
}

void loop() {
  int light = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);
  int sound = digitalRead(SOUND_PIN);

  Serial.print("Light: ");
  Serial.print(light);
  Serial.print(" | Motion: ");
  Serial.print(motion);
  Serial.print(" | Sound: ");
  Serial.println(sound);

  // Auto-light: turn on LED if dark AND someone is present
  if (light < DARK_THRESHOLD && motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("-> Lights ON (person in dark room)");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Noise alert: if loud sound detected, beep once
  if (sound == HIGH) {
    Serial.println("-> NOISE ALERT!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500);
}
```

## Debugging sensor programs

Common issues and solutions:

| Problem | Likely cause | Solution |
|---|---|---|
| Always reads 0 or 1023 | Wiring error, wrong pin | Check connections, verify pin number |
| Unstable readings | Floating pin, no pull resistor | Add pull-up/down or use INPUT_PULLUP |
| PIR always HIGH | Still warming up | Wait 30-60 seconds after power-on |
| Ultrasonic returns 0 | No echo received | Check for obstacles, verify TRIG/ECHO wires |
| Sensor value doesn't match expected | Wrong threshold | Use Serial Monitor to observe actual values |
| Digital output never changes | Potentiometer needs adjustment | Turn the onboard pot and test again |
