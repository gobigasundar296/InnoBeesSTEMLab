# Teacher Guide: Control Everything From Your Phone

## Why this module matters

Wireless control is what makes modern technology feel "smart." This session
bridges the gap between wired classroom projects and the connected world
students live in. By controlling hardware from their own phones, students
experience the real power of IoT and understand that the concepts from
Sessions 1-3 are the foundation of billion-dollar industries.

## Recommended delivery

### Block 1 - Understanding wireless (50 minutes)

- Review: What we've built so far (sensors + outputs): 5 minutes
- Arduino vs. ESP32 comparison: 10 minutes
- IoT concepts and real-world examples: 10 minutes
- Bluetooth vs. Wi-Fi: 10 minutes
- ESP32 setup in Arduino IDE (teacher-led): 15 minutes

### Block 2 - Hands-on wireless control (70 minutes)

- Hands-on: Bluetooth LED control from phone: 25 minutes
- Hands-on: Wi-Fi LED control from phone browser: 25 minutes
- Demonstration: Servo control from web page: 10 minutes
- Discussion: Design a Smart Home feature: 10 minutes

### Extended Block (optional 60 minutes)

- Sensor dashboard on phone: 20 minutes
- Smart Home demo build: 25 minutes
- Team presentations: 15 minutes

## Pre-session preparation (critical!)

This session requires more setup than previous ones:

### Before class day

1. **Install ESP32 board package** on all computers (takes time to download).
2. **Test USB drivers** — some ESP32 boards need CP2102 or CH340 drivers.
3. **Pre-pair Bluetooth** on a test phone to verify it works.
4. **Install phone apps** on at least one demonstration phone.
5. **Test the Wi-Fi AP** — ensure phones can connect and access 192.168.4.1.
6. **Prepare backup code** — have working .ino files ready to flash if
   students have typing errors.

### Day of class

- Have ESP32 boards connected and verified before students arrive.
- Have at least one working demo of each project ready to show first.
- Ensure "Serial Bluetooth Terminal" app is available (share APK or Play
  Store link).

## Teaching method

For wireless projects:

1. **Show:** Demonstrate the finished working project.
2. **Explain:** What technology makes this possible?
3. **Setup:** Guide students through connections and code.
4. **Test:** Students verify on their own phones.
5. **Extend:** Can you add another feature?

## Key demonstrations

### Arduino vs. ESP32 side-by-side

1. Show both boards physically.
2. Point out: "Same pins, same USB upload, same coding — but ESP32 has
   Wi-Fi and Bluetooth built in."
3. Run the same blink sketch on both.
4. Then show the ESP32 doing something the Uno cannot: wireless control.

### First Bluetooth connection

1. Upload the Bluetooth LED code to ESP32.
2. On your phone, show pairing process step by step.
3. Open the Bluetooth terminal app.
4. Send "1" — LED turns on. Students react!
5. Send "0" — LED turns off.
6. This is the "wow moment" of the session.

### Web server demonstration

1. Upload Wi-Fi AP code.
2. Connect phone to "InnoBees_Lab" Wi-Fi.
3. Open browser → 192.168.4.1.
4. Show the styled web page with buttons.
5. Click ON — LED lights up.
6. "This is how smart home apps work!"

## Common issues and solutions

| Problem | Cause | Solution |
|---|---|---|
| ESP32 not recognized | Missing USB driver | Install CP2102 or CH340 driver |
| Upload fails | Wrong board selected | Tools → Board → ESP32 Dev Module |
| Upload fails | COM port wrong | Check Device Manager for correct port |
| BT not found | Code not running | Check Serial Monitor for startup message |
| BT paired but no response | App not connected | Must connect in app after pairing |
| Wi-Fi AP not visible | Code error or crash | Check Serial Monitor, restart ESP32 |
| Web page not loading | Wrong IP typed | Use exactly 192.168.4.1 |
| Analog reads 0 with Wi-Fi | Using ADC2 pin | Switch to ADC1 (GPIO 32-39) |

## Safety briefing

Before the lab, students confirm:

> I will only connect to devices I am authorized to use. I will not store
> personal passwords in code. I will disconnect Bluetooth when done.

Teacher checks:

- ESP32 voltage is 3.3V — no 5V signals connected to GPIO pins.
- Wi-Fi AP passwords are temporary classroom ones, not personal passwords.
- Students do not attempt to connect to school or personal networks without
  permission.

## Assessment evidence

Students should be able to:

- explain why ESP32 is used instead of Arduino Uno for wireless projects;
- describe the difference between Bluetooth and Wi-Fi;
- explain what IoT means with at least two real-world examples;
- successfully control an LED from their phone;
- explain the basic flow: phone sends command → ESP32 receives → controls output;
- identify the 3.3V logic difference and why it matters;
- describe at least one Smart Home feature they would build.

## Suggested team roles

- **Hardware engineer:** connects ESP32 and components.
- **Programmer:** types and uploads the code.
- **Network tester:** handles phone pairing and connection.
- **UI designer:** suggests web page improvements.
- **Presenter:** demonstrates and explains to the class.

## Final challenge: Build a Smart Home Feature

Teams design and (if time allows) build ONE smart home feature:

Requirements:

- Controlled from a phone (Bluetooth or Wi-Fi).
- Uses at least one sensor OR one physical output (LED, buzzer, servo).
- Has a clear purpose that solves a real problem.
- Team can explain how it works.

Example ideas:

- Smart door lock (servo controlled from phone).
- Remote garden monitor (soil moisture displayed on phone).
- Party lights (RGB LED colors set from phone).
- Bedside lamp (phone turns light on/off).
- Security alert (PIR triggers phone notification via BT).

Teams present their idea even if they don't finish building. The design
thinking matters as much as the implementation.
