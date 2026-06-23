# Chapter 1: Arduino vs. ESP32 — Why Go Wireless?

## Looking back at Sessions 1-3

In the previous sessions, all our projects were connected by physical wires:

- Sensors connected to Arduino with jumper wires.
- Outputs connected directly to Arduino pins.
- Programs uploaded via USB cable.
- Serial Monitor viewed on the connected computer.

**Limitation:** The system only works within arm's reach of the computer.

## What if we could control things without wires?

Imagine:

- Turning on your room light from bed using your phone.
- Checking soil moisture in a garden from inside the house.
- Opening a gate for a visitor without walking to the door.
- Monitoring classroom temperature from the staff room.

This is what **wireless communication** enables.

## Arduino Uno — great for learning, limited for wireless

| Feature | Arduino Uno |
|---|---|
| Microcontroller | ATmega328P |
| Clock speed | 16 MHz |
| Digital pins | 14 |
| Analog pins | 6 |
| Flash memory | 32 KB |
| RAM | 2 KB |
| Wi-Fi | None built-in |
| Bluetooth | None built-in |
| Operating voltage | 5 V |
| Cost | Low |

Arduino Uno is excellent for learning electronics and programming. But it
has **no built-in wireless communication**.

To add wireless to Arduino, you need external modules:
- HC-05/HC-06 for Bluetooth
- ESP-01 for Wi-Fi
- NRF24L01 for radio

## ESP32 — Arduino's wireless cousin

| Feature | ESP32 |
|---|---|
| Microcontroller | Xtensa dual-core |
| Clock speed | 240 MHz |
| Digital pins | ~25+ (varies by board) |
| Analog pins | Up to 18 |
| Flash memory | 4 MB (typical) |
| RAM | 520 KB |
| Wi-Fi | Built-in (802.11 b/g/n) |
| Bluetooth | Built-in (Classic + BLE) |
| Operating voltage | 3.3 V |
| Cost | Slightly higher than Uno |

ESP32 is programmed the same way as Arduino (using Arduino IDE) but comes
with **Wi-Fi and Bluetooth built in**.

## Side-by-side comparison

| Capability | Arduino Uno | ESP32 |
|---|---|---|
| LED blink | Yes | Yes |
| Read sensors | Yes | Yes |
| Control servo | Yes | Yes |
| Serial Monitor | Yes | Yes |
| Bluetooth control | Need HC-05 module | Built-in |
| Wi-Fi web server | Need ESP-01 module | Built-in |
| IoT cloud | Very difficult | Easy |
| Programming language | C/C++ (Arduino) | C/C++ (Arduino) |
| IDE | Arduino IDE | Arduino IDE |

## Key point: same code, more features

Because ESP32 uses the Arduino framework, most code from Sessions 1-3 works
on ESP32 with minimal changes. You're not starting over — you're upgrading.

```cpp
// This works on BOTH Arduino and ESP32
void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}
```

## When to use which?

| Scenario | Best choice | Why |
|---|---|---|
| Learning basic circuits | Arduino Uno | Simpler, 5V, well-documented |
| Wired sensor projects | Arduino Uno | Sufficient and cheaper |
| Phone-controlled projects | ESP32 | Built-in Bluetooth + Wi-Fi |
| IoT / cloud connected | ESP32 | Wi-Fi enables internet access |
| Battery-powered wireless | ESP32 | Has deep sleep modes |
| Large school project | ESP32 | More pins, more memory, more capable |

## Important voltage difference

- Arduino Uno: **5 V** logic
- ESP32: **3.3 V** logic

**Warning:** Never connect a 5V signal directly to an ESP32 pin. It may
damage the chip. Use level shifters or voltage dividers when interfacing
5V sensors with ESP32.

Most sensor modules that work at 3.3-5V range will work fine with ESP32.
Always check the module specifications.
