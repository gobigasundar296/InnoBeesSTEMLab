# Student Workbook: Control Everything From Your Phone

**Name:** _________________________  
**Class:** _________________________  
**Team:** _________________________  
**Date:** _________________________

## Safety promise

Tick each rule before starting.

- [ ] I will only connect to devices I am authorized to use.
- [ ] I will not store personal passwords in any code.
- [ ] I will not connect to other students' Bluetooth devices without permission.
- [ ] I will disconnect Bluetooth and Wi-Fi when finished.
- [ ] I will not connect 5V signals to ESP32 GPIO pins (3.3V only).
- [ ] I will ask the teacher before connecting to any external network.

## Part A - Arduino vs. ESP32

### 1. Fill in the comparison

| Feature | Arduino Uno | ESP32 |
|---|---|---|
| Built-in Wi-Fi | | |
| Built-in Bluetooth | | |
| Logic voltage | | |
| Programming IDE | | |
| Can blink an LED | | |
| Can create a web server | | |

### 2. When would you use ESP32 instead of Arduino?

____________________________________________________________________

### 3. Important! What voltage are ESP32 GPIO pins?

______ V

Why does this matter?

____________________________________________________________________

## Part B - IoT (Internet of Things)

### 1. What does IoT stand for?

____________________________________________________________________

### 2. The IoT model: fill in the blanks

```text
_________ → _________ → _________ → _________
(detect)    (send)      (decide)    (do)
```

### 3. Name three IoT devices you use or have seen

1. ________________________________________________________________
2. ________________________________________________________________
3. ________________________________________________________________

### 4. For each IoT device above, identify:

| Device | Sensor (input) | Connection type | Output/Action |
|---|---|---|---|
| | | | |
| | | | |
| | | | |

## Part C - Bluetooth

### 1. What is Bluetooth?

____________________________________________________________________

### 2. What is the typical range of Bluetooth?

_______ meters

### 3. Steps to control an LED via Bluetooth (number them 1-5)

| Step | Order (1-5) |
|---|---|
| Open Bluetooth terminal app and connect | |
| Upload Bluetooth code to ESP32 | |
| Send command "1" to turn on LED | |
| Pair phone with "InnoBees_LED" in Bluetooth settings | |
| Wire LED to ESP32 pin | |

### 4. Did you successfully control the LED? 

Yes / No

If no, what problem did you encounter?

____________________________________________________________________

## Part D - Wi-Fi

### 1. What is the difference between Bluetooth and Wi-Fi?

| Feature | Bluetooth | Wi-Fi |
|---|---|---|
| Range | | |
| Internet access | | |
| Devices connected | | |
| Best for | | |

### 2. ESP32 Access Point mode means:

____________________________________________________________________

### 3. What IP address do you type in the phone browser?

____________________________________________________________________

### 4. How does web control work? (fill in the flow)

Phone browser → types ____________ → ESP32 receives request →

ESP32 turns ____________ → ESP32 sends back ____________ → 

Phone shows updated ____________

### 5. Did you successfully control the LED from the browser?

Yes / No

What did the web page look like?

____________________________________________________________________

## Part E - Comparing wireless methods

### 1. Complete the comparison

| Feature | Bluetooth | Wi-Fi Web Server |
|---|---|---|
| App needed | | |
| Works on iOS? | | |
| Works on Android? | | |
| Internet required? | | |
| Multiple phones can control? | | |

### 2. Which method would you choose for a product? Why?

____________________________________________________________________

____________________________________________________________________

## Part F - Smart Home Design Challenge

### 1. What problem in your home or school would you solve?

____________________________________________________________________

____________________________________________________________________

### 2. Your Smart Home feature name:

____________________________________________________________________

### 3. How does it work?

| Component | Role |
|---|---|
| Sensor (input): | |
| ESP32 (process): | |
| Output (action): | |
| Phone control: | |

### 4. Draw your system

```text



```

### 5. What wireless method would you use? (Bluetooth / Wi-Fi)

Choice: ________________

Why? _______________________________________________________________

### 6. What commands would the phone send?

| Command | Action |
|---|---|
| | |
| | |
| | |

## Part G - Reflection

### 1. What was the most exciting moment today?

____________________________________________________________________

### 2. How is today's session connected to Sessions 1-3?

____________________________________________________________________

____________________________________________________________________

### 3. Name one real product that uses the same technology you learned today.

____________________________________________________________________

### 4. If you could build any IoT device, what would it be?

____________________________________________________________________

____________________________________________________________________
