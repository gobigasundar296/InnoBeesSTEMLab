# Chapter 3: Analog Sensors — LDR and Soil Moisture

## Light-Dependent Resistor (LDR)

An LDR (also called a photoresistor) changes its resistance based on the
amount of light falling on it.

### How it works

The LDR is made of a semiconductor material (typically cadmium sulfide) whose
resistance decreases when exposed to light.

| Condition | Resistance |
|---|---|
| Bright light | Low (a few hundred ohms) |
| Darkness | High (tens of kilohms to megohms) |

### Voltage divider circuit

Arduino cannot read resistance directly. We create a voltage divider with the
LDR and a fixed resistor (typically 10 kilohm) to convert resistance change
into voltage change.

```text
5V --- LDR --- A0 --- 10k resistor --- GND
```

- In bright light: LDR resistance is low → more voltage drops across the
  10k resistor → A0 reads a **higher** value.
- In darkness: LDR resistance is high → less voltage drops across the
  10k resistor → A0 reads a **lower** value.

### Reading LDR with Arduino

```cpp
const int LDR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  Serial.print("Light level: ");
  Serial.println(lightValue);
  delay(500);
}
```

The value ranges from 0 (complete darkness) to 1023 (very bright light),
depending on the exact circuit and LDR characteristics.

### Smart Street Light logic

```cpp
const int LDR_PIN = A0;
const int LED_PIN = 8;
const int THRESHOLD = 300;  // adjust based on testing

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN);
  Serial.println(lightValue);

  if (lightValue < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  // dark: turn on light
  } else {
    digitalWrite(LED_PIN, LOW);   // bright: turn off light
  }
  delay(200);
}
```

## Soil Moisture Sensor

A soil moisture sensor measures the water content in soil by measuring
electrical conductivity between two probes.

### How it works

- Two metal probes are inserted into soil.
- Water in soil conducts electricity. More water means lower resistance
  between the probes.
- The module's comparator circuit outputs both an analog signal (varying
  voltage) and a digital signal (above/below threshold set by onboard
  potentiometer).

### Connections

| Module pin | Connects to |
|---|---|
| VCC | Arduino 5V |
| GND | Arduino GND |
| A0 (analog out) | Arduino analog pin (e.g., A1) |
| D0 (digital out) | Arduino digital pin (optional) |

### Reading soil moisture

```cpp
const int SOIL_PIN = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(SOIL_PIN);
  Serial.print("Soil moisture: ");
  Serial.println(moisture);

  if (moisture < 400) {
    Serial.println("Status: DRY - needs water!");
  } else if (moisture < 700) {
    Serial.println("Status: MOIST - OK");
  } else {
    Serial.println("Status: WET - no watering needed");
  }
  delay(1000);
}
```

Note: Actual threshold values depend on the specific sensor module and soil
type. Always calibrate by testing in dry soil and wet soil first.

### Sensor care

- Do not leave the sensor powered continuously in soil. Electrolysis will
  corrode the probes over time.
- Power the sensor only when taking a reading, or use a capacitive soil
  moisture sensor for longer-term projects.

## Comparing LDR and soil moisture sensor

| Feature | LDR | Soil moisture sensor |
|---|---|---|
| Measures | Light intensity | Water content in soil |
| Output type | Analog (voltage divider) | Analog + digital |
| Needs external resistor | Yes (voltage divider) | No (built into module) |
| Typical application | Street lights, displays | Smart irrigation |
| Arduino function | `analogRead()` | `analogRead()` or `digitalRead()` |

## Key concept: thresholds

Both sensors produce a range of values. The programmer decides at which value
to trigger an action. This decision point is called a **threshold**.

Choosing a good threshold:

1. Read the sensor in the "action needed" condition. Note the value.
2. Read the sensor in the "no action needed" condition. Note the value.
3. Choose a threshold between these two values.
4. Test and adjust until the system behaves reliably.
