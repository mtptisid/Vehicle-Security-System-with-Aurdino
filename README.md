# Smart Car Security System with ESP8266 and Blynk

This project implements a **smart car security system** using an ESP8266 microcontroller. It integrates features like password-protected access via a keypad, motion detection using a proximity sensor, and IoT-based remote notifications with the Blynk platform. 

---

## Features

1. **Wi-Fi Connectivity**
   - Connects to a Wi-Fi network using the ESP8266.
   - Controlled and monitored remotely using the Blynk app.

2. **Password-Based Access**
   - Utilizes a 4x4 keypad for password input.
   - Grants access if the entered password matches the predefined password.
   - Locks the system after 3 incorrect attempts and sends a notification.

3. **Motion Detection**
   - Proximity sensor detects movement (e.g., unauthorized entry).
   - Sends real-time alerts via Blynk.

4. **Real-Time Monitoring**
   - Uses Blynk to update and monitor system parameters.
   - Notifications are sent for security events like unauthorized access attempts or motion detection.

5. **Extensibility**
   - Analog input from an additional sensor (connected to pin A0) can be monitored for extended functionalities.

---

## Components Required

1. **Hardware**
   - ESP8266 microcontroller
   - 4x4 Keypad
   - Proximity sensor (e.g., IR sensor or ultrasonic sensor)
   - Additional analog sensor (optional)
   - Connecting wires and breadboard

2. **Software**
   - Arduino IDE
   - Blynk app (available on Android and iOS)

---

## Getting Started

### 1. Hardware Setup
- Connect the **4x4 keypad** to the ESP8266 pins:
  - Rows: `D7`, `D6`, `D5`, `D4`
  - Columns: `D3`, `D2`, `D1`, `D0`
- Connect the **proximity sensor** to pin `10` (ProxSensor).
- Optionally, connect an **analog sensor** to pin `A0`.

### 2. Software Setup
- Install the following libraries in the Arduino IDE:
  - `ESP8266WiFi`
  - `Blynk`
  - `Keypad`
- Replace the placeholders in the code with your own Blynk authentication token, Wi-Fi SSID, and password:
  ```cpp
  char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
  char ssid[] = "YOUR_WIFI_SSID";
  char pass[] = "YOUR_WIFI_PASSWORD";
  ```

### 3. Uploading the Code
- Connect the ESP8266 to your computer using a USB cable.
- Select the correct board (`Generic ESP8266 Module`) and port in the Arduino IDE.
- Upload the code.

### 4. Blynk App Setup
1. Download and install the Blynk app.
2. Create a new project and add the required widgets:
   - Notification widget
   - Buttons or virtual pins to monitor `V1` and `V15`.
3. Use the authentication token provided by Blynk in the Arduino code.

---

## Usage

1. **Power On**
   - Power the ESP8266 module and ensure it connects to Wi-Fi.
   - Open the Blynk app to monitor the system.

2. **Enter Password**
   - Use the keypad to input the predefined password (`2005` by default).
   - Correct password grants access; incorrect attempts trigger a lockout after 3 tries.

3. **Proximity Alerts**
   - Any motion detected by the proximity sensor triggers a notification.

4. **Monitor Sensor Data**
   - Check additional sensor readings on pin `A0` via serial monitor (or extend to Blynk for visualization).

---

## Customization

- Change the default password in the code:
  ```cpp
  String password = "NEW_PASSWORD";
  ```
- Adjust the max allowed attempts by modifying:
  ```cpp
  int max_attempts = 3;
  ```
- Add more functionality using the available pins or extend the Blynk integration for enhanced monitoring and control.

---

## Troubleshooting

1. **Wi-Fi Not Connecting**
   - Double-check the SSID and password.
   - Ensure the ESP8266 is within range of the Wi-Fi network.

2. **Keypad Not Responding**
   - Verify the wiring of the keypad.
   - Ensure the correct pin mappings in the code.

3. **No Notifications**
   - Ensure the Blynk app is properly configured and the device is online.

---

## Future Enhancements

- Add a buzzer or LED to indicate incorrect password attempts.
- Integrate additional sensors like temperature or humidity for enhanced monitoring.
- Use a relay module to control physical locks.

---

## License
This project is open-source and available for educational purposes. Feel free to modify and extend it as needed.

Happy Building! 🚗🔒

