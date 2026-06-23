# Chapter 4: IoT Concepts and Applications

## What is IoT?

**IoT** stands for **Internet of Things**. It refers to everyday physical
objects connected to the internet, able to collect data, communicate, and be
controlled remotely.

> "IoT is when 'things' become 'smart things' by connecting to the internet."

## The IoT model

```text
SENSE → CONNECT → PROCESS → ACT
  |         |          |        |
Sensors   Wi-Fi/    Cloud/    Outputs
          Bluetooth  Local    (LED, motor,
                     Logic    notification)
```

## Examples of IoT in everyday life

| IoT device | Sensors | Connection | Action |
|---|---|---|---|
| Smart light bulb | — | Wi-Fi | Turn on/off from phone |
| Fitness band | Accelerometer, heart rate | Bluetooth | Send data to phone app |
| Smart thermostat | Temperature sensor | Wi-Fi | Adjust heating/cooling |
| Smart doorbell | Camera, button | Wi-Fi | Send video to phone |
| Smart irrigation | Soil moisture | Wi-Fi | Activate water pump |
| Connected car | GPS, speed, fuel | Cellular | Track location, diagnostics |
| Smart factory | Temperature, pressure | Industrial IoT | Alert operators |

## IoT vs. regular electronics

| Feature | Regular circuit | IoT system |
|---|---|---|
| Control | Physical buttons only | Phone, voice, automatic |
| Monitoring | Must be present | View from anywhere |
| Data storage | None | Cloud stores history |
| Automation | Fixed program | Can learn and adapt |
| Updates | Reprogram manually | Over-the-air updates |

## IoT architecture layers

### 1. Perception layer (sensing)

- Sensors collect data from the physical world.
- Examples: temperature, humidity, motion, light.

### 2. Network layer (connecting)

- Data is transmitted wirelessly.
- Technologies: Wi-Fi, Bluetooth, Zigbee, LoRa, Cellular (4G/5G).

### 3. Application layer (using)

- Data is processed, displayed, and acted upon.
- Examples: phone apps, web dashboards, automated responses.

## IoT communication protocols

| Protocol | Best for | Used by |
|---|---|---|
| Wi-Fi | High data, home range | Smart home devices |
| Bluetooth/BLE | Short range, low power | Wearables, beacons |
| Zigbee | Mesh network, low power | Smart lighting (Philips Hue) |
| LoRa | Long range, low data | Agriculture, city sensors |
| Cellular (4G/5G) | Wide area, mobile | Connected cars, trackers |
| MQTT | IoT messaging | Most cloud IoT platforms |

## Smart Home — IoT at home

A smart home uses IoT to automate and remotely control home functions:

| Room | Smart feature | Benefit |
|---|---|---|
| Living room | Smart lights | Control brightness, color, schedule |
| Kitchen | Smart plug | Turn off appliances remotely |
| Bedroom | Smart AC | Adjust temperature from bed |
| Garden | Smart irrigation | Water only when soil is dry |
| Entrance | Smart lock | Unlock with phone, see visitors |
| Whole house | Voice assistant | Control everything by speaking |

## IoT challenges

1. **Security:** Devices can be hacked if not properly secured.
2. **Privacy:** Devices collect personal data about habits and routines.
3. **Reliability:** Internet outages can disable smart systems.
4. **Compatibility:** Different brands may not work together.
5. **Power:** Battery-powered IoT devices need efficient design.
6. **Complexity:** More connected devices = more things that can go wrong.

## Our IoT projects

In this session, we build simplified IoT projects:

| Project | Sense | Connect | Act |
|---|---|---|---|
| Bluetooth LED | Phone command | Bluetooth | LED on/off |
| Wi-Fi LED | Phone browser | Wi-Fi | LED on/off |
| Wi-Fi servo | Phone browser | Wi-Fi | Gate opens |
| Sensor dashboard | LDR reading | Wi-Fi | Display on phone |
| Smart home demo | Multiple sensors | Wi-Fi | Multiple outputs |

These are real IoT principles scaled to classroom size!

## The future of IoT

- **Smart cities:** Traffic management, waste collection, air quality.
- **Smart agriculture:** Precision farming with sensor networks.
- **Smart health:** Remote patient monitoring, wearable diagnostics.
- **Smart industry:** Predictive maintenance, automated quality control.
- **Smart energy:** Grid optimization, home energy management.

Students working with ESP32 today are learning the fundamentals that power
these billion-dollar industries.
