# Session 4: Control Everything From Your Phone

This module introduces students to wireless communication and the Internet of
Things (IoT). Students learn the difference between Arduino and ESP32, explore
Bluetooth and Wi-Fi concepts, and build projects that can be controlled from
a mobile phone.

**Audience:** Classes 6-9  
**Duration:** 2 hours (extendable to 4 hours with all activities)  
**Learning cycle:** Explore → Understand → Build → Code → Challenge → Present

## What students learn

1. The difference between Arduino Uno and ESP32.
2. What Bluetooth is and how it enables short-range wireless communication.
3. What Wi-Fi is and how it connects devices to networks and the internet.
4. What IoT (Internet of Things) means and real-world examples.
5. How to set up the ESP32 board in Arduino IDE.
6. How to control an LED wirelessly via Bluetooth from a phone app.
7. How to create a simple web server on ESP32 for Wi-Fi control.
8. How to control a servo motor from a mobile phone.
9. How to read sensor data remotely over Wi-Fi.
10. How to design a Smart Home feature using wireless control.

## Learning documents

- [Teacher guide and delivery plan](teacher-guide.md)
- [Chapter 1: Arduino vs. ESP32 — why go wireless?](01-arduino-vs-esp32.md)
- [Chapter 2: Bluetooth communication](02-bluetooth-communication.md)
- [Chapter 3: Wi-Fi and web server basics](03-wifi-web-server.md)
- [Chapter 4: IoT concepts and applications](04-iot-concepts.md)
- [Chapter 5: Mobile app control](05-mobile-app-control.md)
- [Chapter 6: ESP32 wireless projects](06-esp32-projects.md)
- [Student workbook](student-workbook.md)
- [Teacher answer key](teacher-answer-key.md)

## Image illustrations

- [Editable SVG diagram index](circuits/README.md)

## Arduino/ESP32 programs

- [ESP32 Bluetooth LED control](arduino/01_bluetooth_led/01_bluetooth_led.ino)
- [ESP32 Wi-Fi LED web server](arduino/02_wifi_led_server/02_wifi_led_server.ino)
- [ESP32 servo web control](arduino/03_wifi_servo_control/03_wifi_servo_control.ino)
- [ESP32 sensor web dashboard](arduino/04_sensor_dashboard/04_sensor_dashboard.ino)
- [ESP32 smart home demo](arduino/05_smart_home_demo/05_smart_home_demo.ino)
- [Arduino Bluetooth module (HC-05)](arduino/06_arduino_hc05_bluetooth/06_arduino_hc05_bluetooth.ino)

## Core Path for a two-hour class

If only two hours are available, teach:

1. Arduino vs. ESP32 comparison and why wireless matters.
2. IoT concepts with real-world examples.
3. ESP32 setup in Arduino IDE.
4. Hands-on: Bluetooth LED control from phone.
5. Hands-on: Wi-Fi LED control from phone browser.
6. Discussion: Design a Smart Home feature.

The servo control, sensor dashboard, and full Smart Home build continue
in extended time.

## Equipment per team

- ESP32 development board (e.g., ESP32-WROOM-32 DevKit)
- USB micro/Type-C cable (for ESP32)
- Arduino Uno R3 and USB cable (for comparison)
- Breadboard and jumper wires
- LEDs (red, green, blue) and 330 ohm resistors
- SG90 micro servo motor
- LDR and 10 kilohm resistor (for sensor demo)
- Active buzzer
- Smartphones with Bluetooth Serial app installed
  (e.g., "Serial Bluetooth Terminal" for Android)
- Wi-Fi access point (can be phone hotspot or classroom router)
- HC-05 Bluetooth module (optional, for Arduino-based Bluetooth)

## Software requirements

- Arduino IDE with ESP32 board package installed
- Bluetooth terminal app on student phones
- Web browser on student phones (for Wi-Fi projects)
