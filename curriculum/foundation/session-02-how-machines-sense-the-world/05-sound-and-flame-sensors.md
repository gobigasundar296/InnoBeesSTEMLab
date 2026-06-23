# Chapter 5: Sound and Flame Sensors

## Sound Sensor (KY-038 or similar)

A sound sensor module detects sound intensity in the environment using a
microphone and an amplifier circuit.

### How it works

1. A small electret microphone converts sound pressure waves into a tiny
   electrical signal.
2. An onboard amplifier (typically LM393 comparator) boosts the signal.
3. The module provides two outputs:
   - **Analog output (A0):** Varying voltage proportional to sound level.
   - **Digital output (D0):** HIGH when sound exceeds a threshold set by
     the onboard potentiometer.

### Connections

| Module pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| A0 | Arduino analog pin (e.g., A2) |
| D0 | Arduino digital pin (e.g., D5) |

### Adjusting sensitivity

The onboard potentiometer sets the threshold for the digital output. Turn
it to adjust how loud a sound must be to trigger a HIGH output.

### Arduino program: clap detector

```cpp
const int SOUND_DIGITAL_PIN = 5;
const int LED_PIN = 8;
bool ledState = false;

void setup() {
  pinMode(SOUND_DIGITAL_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(SOUND_DIGITAL_PIN) == HIGH) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "LED ON (clap)" : "LED OFF (clap)");
    delay(300);  // debounce to avoid double triggers
  }
}
```

### Reading analog sound level

```cpp
const int SOUND_ANALOG_PIN = A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int soundLevel = analogRead(SOUND_ANALOG_PIN);
  Serial.print("Sound level: ");
  Serial.println(soundLevel);
  delay(100);
}
```

### Limitations

- The module detects sound *intensity*, not specific sounds or words.
- It cannot distinguish between a clap, a voice, or background noise.
- Environmental noise may cause false triggers.
- For voice recognition, specialized modules or microcontrollers are needed.

## Flame Sensor (KY-026 or similar)

A flame sensor detects infrared radiation in the wavelength range emitted
by fire (approximately 760-1100 nm).

### How it works

1. An infrared photodiode detects IR radiation from a flame.
2. A comparator circuit on the module generates:
   - **Analog output:** Voltage varies with flame proximity/intensity.
   - **Digital output:** HIGH or LOW based on threshold (set by onboard
     potentiometer).

### Specifications

| Parameter | Value |
|---|---|
| Detection wavelength | 760-1100 nm |
| Detection angle | ~60 degrees |
| Detection distance | Up to ~80 cm (small flame) |
| Operating voltage | 3.3-5 V |

### Connections

| Module pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| A0 | Arduino analog pin (e.g., A3) |
| D0 | Arduino digital pin (e.g., D6) |

### Arduino program: fire alarm

```cpp
const int FLAME_DIGITAL_PIN = 6;
const int BUZZER_PIN = 7;
const int LED_RED = 8;

void setup() {
  pinMode(FLAME_DIGITAL_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int flame = digitalRead(FLAME_DIGITAL_PIN);

  if (flame == LOW) {  // many modules output LOW when flame detected
    Serial.println("FIRE DETECTED!");
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  } else {
    Serial.println("No flame.");
    digitalWrite(LED_RED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
  delay(200);
}
```

**Note:** Some flame sensor modules output LOW when a flame is detected and
HIGH when no flame is present. Always test your specific module to confirm
the logic.

### Safety warning

- **Never** create an actual fire in the classroom to test the sensor.
- Use a lighter held at arm's length briefly, or a candle behind a safety
  screen, with teacher supervision only.
- A TV remote or IR LED can also trigger the sensor safely for testing.

## Sensor comparison table

| Sensor | Detects | Output type | Arduino function | Typical use |
|---|---|---|---|---|
| Push button | Physical press | Digital | `digitalRead()` | User input |
| Touch (TTP223) | Finger proximity | Digital | `digitalRead()` | Touch control |
| LDR | Light level | Analog | `analogRead()` | Lighting control |
| Soil moisture | Water in soil | Analog + Digital | Both | Smart garden |
| HC-SR04 | Distance | Digital (pulse) | `pulseIn()` | Obstacle detection |
| PIR (HC-SR501) | Motion | Digital | `digitalRead()` | Security |
| Sound (KY-038) | Sound level | Analog + Digital | Both | Sound-activated |
| Flame (KY-026) | IR from fire | Analog + Digital | Both | Fire alarm |
