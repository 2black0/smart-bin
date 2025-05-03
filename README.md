# 🗑️ Smart Bin — Intelligent Trash Can with Humidity & Distance Sensing

This project implements a **smart trash bin system** using Arduino, ultrasonic and humidity sensors, and two servo motors. It automatically opens when someone approaches and responds to trash humidity (wet/dry classification) to trigger directional sorting.

---

## 🔧 Features

* ✋ **Automatic lid opening** via ultrasonic proximity detection
* 💧 **Trash classification** based on humidity sensor readings
* 🔁 **Servo-based sorting** for wet vs dry waste
* 📟 **Serial monitor** debugging for sensor values

---

## 🧰 Hardware Components

| Component         | Quantity | Description                                   |
| ----------------- | -------- | --------------------------------------------- |
| Arduino Uno/Nano  | 1        | Microcontroller board                         |
| Ultrasonic Sensor | 1        | HC-SR04 (Distance detection)                  |
| Humidity Sensor   | 1        | Analog sensor (e.g., moisture sensor or MQ-3) |
| Servo Motor       | 2        | One for lid, one for sorting arm              |
| Jumper Wires      | -        | Male to Male/Female                           |
| Breadboard        | 1        | For prototyping                               |
| Power Supply      | 1        | 5V USB or battery pack                        |
| LED (optional)    | 1        | Status indicator                              |

---

## 🪛 Wiring Diagram

| Arduino Pin | Connected To               |
| ----------- | -------------------------- |
| `A0`        | Humidity sensor analog out |
| `4`         | Ultrasonic Echo            |
| `5`         | Ultrasonic Trigger         |
| `7`         | Lid Servo (autoServo)      |
| `9`         | Sorting Servo (humServo)   |
| `10`        | LED (optional indicator)   |
| `GND`       | All sensor/servo grounds   |
| `5V`        | Power to sensors/servos    |

> ⚠️ Use a power regulator or external 5V if both servos are used simultaneously to avoid brownouts.

---

## 📦 Project Structure

```
.
├── Project/
│   └── main.ino      # Arduino source code
├── LICENSE
└── README.md
```

---

## 🚀 How It Works

1. **Standby Mode**
   The system waits and checks ultrasonic sensor readings periodically.

2. **Lid Activation**
   If an object (hand/trash) is detected within 50 cm, the lid opens automatically.

3. **Humidity Detection**
   The trash's humidity is read. If the value is **above 50**, it's treated as *wet*, otherwise *dry*.

4. **Servo Sorting**
   Based on humidity:

   * `Wet Trash`: Sorting servo rotates right
   * `Dry Trash`: Sorting servo rotates left

5. **Reset State**
   System resets and waits for next detection cycle.

---

## 🖥️ Serial Output Example

```
Smart-Bin
Nilai Ultrasonic: 25
Servo Auto ON
Nilai Kelembaban: 66
Servo Hum RIGHT
Menunggu....
```

---

## 🔄 Customization

You can modify:

* Detection threshold (`disVal < 50`)
* Humidity classification threshold (`humVal > 50`)
* Servo angles (`0`, `90`, `180`) for specific bin mechanics

---

## 🪪 License

This project is licensed under the [MIT License](./LICENSE) – feel free to use, modify, and share!

---

## 🙋 Author

Developed by [2black0@gmail.com](mailto:2black0@gmail.com) — Educational prototype for Smart Waste Management Systems.

---