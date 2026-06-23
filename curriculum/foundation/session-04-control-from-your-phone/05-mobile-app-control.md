# Chapter 5: Mobile App Control

## Three ways to control from a phone

| Method | Technology | App needed | Works on |
|---|---|---|---|
| Bluetooth Serial | Bluetooth Classic | Terminal app | Android |
| Web interface | Wi-Fi | Web browser | Android + iOS |
| BLE + custom app | Bluetooth Low Energy | Specialized app | Android + iOS |

For classroom use, we focus on **Bluetooth Serial** (Android) and **Web
interface** (all phones).

## Method 1: Bluetooth Serial app

### Setup steps (Android)

1. **Install app:** "Serial Bluetooth Terminal" from Play Store.
2. **Upload code:** Flash the Bluetooth LED program to ESP32.
3. **Pair device:** Go to phone Settings → Bluetooth → Pair "InnoBees_LED".
4. **Open app:** Launch Serial Bluetooth Terminal.
5. **Connect:** Tap the menu → Devices → Select "InnoBees_LED".
6. **Send commands:** Type "1" → Send (LED turns on). Type "0" → Send.

### Configuring buttons in the app

Most Bluetooth terminal apps let you create custom buttons:

1. Long-press the button bar area.
2. Add button: Name = "ON", Value = "1".
3. Add button: Name = "OFF", Value = "0".
4. Now you have one-tap control!

### Multiple device control

You can send multiple commands for different outputs:

| Command | Action |
|---|---|
| 1 | LED 1 ON |
| 2 | LED 1 OFF |
| 3 | LED 2 ON |
| 4 | LED 2 OFF |
| 5 | Buzzer ON |
| 6 | Buzzer OFF |
| 7 | Servo to 0° |
| 8 | Servo to 90° |
| 9 | Servo to 180° |

## Method 2: Wi-Fi web interface

### Setup steps (any phone)

1. **Upload code:** Flash the Wi-Fi LED server program to ESP32.
2. **Connect to ESP32 Wi-Fi:** Go to phone Wi-Fi settings → Connect to
   "InnoBees_Lab" with password "stem1234".
3. **Open browser:** Type `192.168.4.1` in the address bar.
4. **Control:** Tap the ON/OFF buttons on the web page.

### Advantages of web interface

- Works on ALL phones (Android, iOS, any device with a browser).
- No app installation needed.
- Can be made visually attractive with HTML/CSS.
- Multiple students can access simultaneously.

### Making the interface look good

CSS styling makes the web page look like a real app:

```html
<style>
  body { font-family: Arial; text-align: center; background: #1a1a2e; color: white; }
  .btn { padding: 15px 30px; font-size: 18px; margin: 10px;
         border: none; border-radius: 8px; color: white; }
  .on { background: #4CAF50; }
  .off { background: #f44336; }
  h1 { color: #00d4ff; }
</style>
```

## Designing a command protocol

When controlling multiple devices, design a clear command structure:

### Simple character commands (Bluetooth)

```text
Command | Action
--------|--------
A       | LED Red ON
a       | LED Red OFF
B       | LED Green ON
b       | LED Green OFF
S       | Servo to 90°
s       | Servo to 0°
```

### URL path commands (Wi-Fi)

```text
Path     | Action
---------|--------
/led/on  | LED ON
/led/off | LED OFF
/servo/0 | Servo to 0°
/servo/90| Servo to 90°
```

## Reading data back

Control is two-way. The phone can also **receive** data from ESP32:

### Bluetooth response

```cpp
if (command == 't') {
  int temp = analogRead(A0);  // read sensor
  SerialBT.print("Temperature: ");
  SerialBT.println(temp);
}
```

### Web page with live data

```cpp
html += "<p>Light Level: " + String(analogRead(LDR_PIN)) + "</p>";
html += "<p>Last updated: " + String(millis()/1000) + " sec</p>";
```

## Tips for reliable control

1. **Clear commands:** Use single characters or short strings.
2. **Feedback:** Always send a response back to confirm the action.
3. **Error handling:** Ignore unknown commands gracefully.
4. **Debounce:** Add small delays to prevent rapid repeated triggers.
5. **Status display:** Show current state on both the device and phone.

## Privacy and safety

- Only control devices you own or have permission to use.
- Do not connect to other people's Bluetooth devices.
- The classroom Wi-Fi network is for learning only.
- Never put personal information in your code.
- Always disconnect when you're done.
