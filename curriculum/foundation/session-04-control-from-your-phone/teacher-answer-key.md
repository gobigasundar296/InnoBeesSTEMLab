# Teacher Answer Key: Session 4 Workbook

## Part A

1. Comparison:
   - Wi-Fi: Uno=No, ESP32=Yes.
   - Bluetooth: Uno=No, ESP32=Yes.
   - Logic voltage: Uno=5V, ESP32=3.3V.
   - IDE: Both use Arduino IDE.
   - Blink LED: Both=Yes.
   - Web server: Uno=No (without external module), ESP32=Yes.

2. When wireless communication is needed — phone control, IoT, remote
   monitoring, web interfaces.

3. 3.3V. Connecting a 5V signal directly can damage the ESP32 chip.

## Part B

1. Internet of Things.

2. SENSE → CONNECT → PROCESS → ACT (or similar: detect → send → decide → do).

3. Accept any valid IoT devices: smart lights, fitness bands, smart speakers,
   smart TVs, connected doorbells, smart plugs, etc.

4. Accept reasonable sensor/connection/output for each named device.

## Part C

1. Bluetooth is a wireless technology for exchanging data over short
   distances using radio waves.

2. ~10 meters.

3. Order: Wire LED (1) → Upload code (2) → Pair phone (3) → Open app (4) →
   Send command (5). Accept slight variations as long as wiring and upload
   come before pairing and app use.

## Part D

1. Bluetooth: ~10m range, no internet, usually 1 device, best for direct
   control. Wi-Fi: ~30-100m range, internet access, many devices, best for
   web control and IoT.

2. ESP32 creates its own Wi-Fi network that phones connect to directly
   (no external router needed).

3. 192.168.4.1

4. Phone types 192.168.4.1/on → ESP32 turns LED on → sends back updated
   HTML page → Phone shows "LED is ON" with buttons.

## Part E

1. Bluetooth: terminal app, not easily on iOS, yes Android, no internet
   needed, usually one phone.
   Wi-Fi: web browser (no install), yes iOS, yes Android, no internet needed
   (local), yes multiple phones.

2. Accept either choice with valid reasoning. Wi-Fi is often preferred for
   products because it works on all phones without app installation.

## Part F

Assess based on:

- Clear problem identification.
- Appropriate sensor and output choices.
- Reasonable wireless method choice with justification.
- Clear command protocol.
- System diagram shows understanding of connections.

Examples of good answers:

- Smart desk lamp: phone sends ON/OFF via Wi-Fi, LED responds.
- Garden monitor: soil sensor data shown on phone web page, buzzer alerts
  when too dry.
- Door opener: PIR detects visitor, notification via BT, servo opens on
  phone command.
