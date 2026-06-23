# Chapter 5: Buzzer Sounds and Melodies

## Active vs. passive buzzer

### Active buzzer

- Contains a built-in oscillator circuit.
- Produces a single fixed tone when powered with DC voltage.
- Only needs `digitalWrite(pin, HIGH)` to sound.
- Cannot play different notes or melodies.

### Passive buzzer

- No built-in oscillator — just a piezoelectric element.
- Requires an AC signal (varying frequency) to produce sound.
- Can play different notes by changing the frequency.
- Use the Arduino `tone()` function.

### How to tell them apart

- Active buzzer: usually has a sealed top and a `+` marking. Sounds
  immediately when connected to 5V.
- Passive buzzer: may have an open top showing the circuit board. Does NOT
  sound with just DC voltage.

## Connecting a buzzer to Arduino

```text
Arduino D7 -> Buzzer (+) positive leg
Buzzer (-) negative leg -> GND
```

For active buzzers drawing less than 20 mA, direct connection to an Arduino
pin is acceptable. For louder or higher-current buzzers, use a transistor
driver.

## Active buzzer: simple alerts

```cpp
const int BUZZER_PIN = 7;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Three short beeps
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  delay(2000);  // pause between alert cycles
}
```

## Passive buzzer: playing notes with tone()

The `tone(pin, frequency, duration)` function generates a square wave at the
specified frequency.

### Musical note frequencies (Hz)

| Note | Frequency |
|---|---|
| C4 | 262 |
| D4 | 294 |
| E4 | 330 |
| F4 | 349 |
| G4 | 392 |
| A4 | 440 |
| B4 | 494 |
| C5 | 523 |

### Playing a simple scale

```cpp
const int BUZZER_PIN = 7;

int notes[] = {262, 294, 330, 349, 392, 440, 494, 523};
int numNotes = 8;

void setup() {
  // nothing needed
}

void loop() {
  for (int i = 0; i < numNotes; i++) {
    tone(BUZZER_PIN, notes[i], 400);
    delay(500);
  }
  delay(2000);
}
```

### Playing a melody (Twinkle Twinkle)

```cpp
const int BUZZER_PIN = 7;

// Notes: C C G G A A G - F F E E D D C
int melody[] = {262, 262, 392, 392, 440, 440, 392,
                349, 349, 330, 330, 294, 294, 262};
int durations[] = {400, 400, 400, 400, 400, 400, 800,
                   400, 400, 400, 400, 400, 400, 800};
int numNotes = 14;

void setup() {
  for (int i = 0; i < numNotes; i++) {
    tone(BUZZER_PIN, melody[i], durations[i]);
    delay(durations[i] + 50);  // gap between notes
  }
  noTone(BUZZER_PIN);
}

void loop() {
  // play once only
}
```

## Alert patterns

Different alert patterns communicate different meanings:

| Pattern | Meaning | Code pattern |
|---|---|---|
| Single long beep | Confirmation | 1000ms on |
| Three short beeps | Warning | 200ms on, 200ms off × 3 |
| Rapid beeping | Urgent alarm | 100ms on, 100ms off continuous |
| Two-tone siren | Emergency | Alternate 800Hz and 600Hz |

### Two-tone siren

```cpp
const int BUZZER_PIN = 7;

void loop() {
  tone(BUZZER_PIN, 800);
  delay(500);
  tone(BUZZER_PIN, 600);
  delay(500);
}
```

## Using noTone()

`noTone(pin)` stops the tone output on a pin. Always call this when you want
silence, especially if you used `tone()` without a duration parameter.

## Buzzer + sensor integration

Buzzers are commonly paired with sensors for alerts:

- PIR + buzzer = intruder alarm
- Ultrasonic + buzzer = parking sensor (beep rate changes with distance)
- Flame sensor + buzzer = fire alarm
- Temperature sensor + buzzer = overheat warning
