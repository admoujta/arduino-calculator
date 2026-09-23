<div align="center">

# 🧮 Arduino Calculator

### A hardware calculator built with Arduino Uno, a 4×4 keypad and a 16×2 I²C LCD.

[![Arduino](https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C%2B%2B-Arduino-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](ArduinoCalculator.ino)
[![Tinkercad](https://img.shields.io/badge/Tinkercad-Simulation-1477D1?style=for-the-badge)](https://www.tinkercad.com/things/8Jtw3pfhN7P-projet-arduino-g32-g3/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits)

</div>

---

## 📌 Overview

This project implements a simple calculator using an **Arduino Uno**, a **4×4 matrix keypad**, and a **16×2 LCD connected through I²C**.

The user enters numbers and arithmetic operators from the keypad. The Arduino processes the input and displays values, operators, results, and error messages on the LCD.

The circuit was designed and simulated with **Autodesk Tinkercad**.

## ✨ Features

- Addition, subtraction, multiplication and division
- Multi-digit number input
- 4×4 matrix keypad
- 16×2 I²C LCD output
- Clear/reset key
- Chained calculations
- Division-by-zero protection
- Tinkercad circuit simulation

## 🛠️ Components

| Component | Quantity |
|---|:---:|
| Arduino Uno | 1 |
| 4×4 Matrix Keypad | 1 |
| 16×2 LCD Display | 1 |
| I²C LCD Interface | 1 |
| Jumper Wires | Several |

## 🔌 Wiring

### Keypad

| Keypad | Arduino Uno |
|---|---|
| Row 1 | D7 |
| Row 2 | D6 |
| Row 3 | D5 |
| Row 4 | D4 |
| Column 1 | D3 |
| Column 2 | D2 |
| Column 3 | D1 |
| Column 4 | D0 |

### I²C LCD

| LCD | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

> The LCD I²C address used by the sketch is `0x27`.

## ⌨️ Keypad Layout

```text
┌───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ + │
├───┼───┼───┼───┤
│ 4 │ 5 │ 6 │ - │
├───┼───┼───┼───┤
│ 7 │ 8 │ 9 │ * │
├───┼───┼───┼───┤
│ C │ 0 │ = │ / │
└───┴───┴───┴───┘
```

| Key | Function |
|---|---|
| `0-9` | Enter numbers |
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `=` | Calculate result |
| `C` | Clear / reset |

## ⚙️ How It Works

1. The LCD displays **Calculatrice** when the Arduino starts.
2. The first number is entered using the keypad.
3. An arithmetic operator is selected.
4. The second number is entered.
5. Pressing `=` performs the calculation.
6. The result is displayed on the LCD.
7. Pressing `C` clears the current calculation.
8. A division by zero displays an error message and resets the calculator.

The sketch also supports chained operations: selecting another operator after entering a second number calculates the current operation first and continues with the result.

## 🖼️ Circuit Preview

<p align="center">
  <img src="assets/circuit-preview.png" alt="Arduino calculator circuit in Tinkercad" width="900">
</p>

The electrical schematic is available in [`docs/schematic.pdf`](docs/schematic.pdf).

## 🧪 Tinkercad Simulation

### 👉 [Open the Arduino Calculator in Tinkercad](https://www.tinkercad.com/things/8Jtw3pfhN7P-projet-arduino-g32-g3/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits)

## 🚀 Getting Started

### Requirements

Install:

- `Keypad`
- `LiquidCrystal_I2C`
- `Wire` (included with Arduino)

### Upload

```bash
git clone https://github.com/admoujta/arduino-calculator.git
cd arduino-calculator
```

Then:

1. Open `ArduinoCalculator.ino` in Arduino IDE.
2. Connect the Arduino Uno.
3. Select **Tools → Board → Arduino Uno**.
4. Select the correct serial port.
5. Compile and upload the sketch.

## 📂 Project Structure

```text
arduino-calculator/
├── ArduinoCalculator.ino
├── assets/
│   └── circuit-preview.png
├── docs/
│   └── schematic.pdf
├── .gitignore
├── LICENSE
└── README.md
```

## 🧠 Concepts Practiced

- Arduino programming
- Embedded C/C++
- Matrix keypad scanning
- I²C communication
- LCD control
- Input/state management
- Arithmetic processing
- Basic error handling
- Hardware/software integration

## 🔮 Possible Improvements

- Decimal number input
- Negative number input
- Memory functions
- Scientific operations
- Calculation history
- Improved error handling
- Custom PCB version

## 👨‍💻 Author

**Adam Moujtahid**

Computer Engineering & Networks Student  
Future AI & Big Data Engineer

---

<div align="center">

If you found this project useful, consider giving the repository a ⭐.

</div>
