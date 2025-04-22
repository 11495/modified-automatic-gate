# Modified Automatic Gate System

## Project Overview
This project involves designing a **modified automatic gate system** using **IR sensors**, **DC motor**, **motor controller**, and **LED dot matrix** for display. The system opens the gate when a person approaches, displays a **"Welcome"** message on an LED dot matrix, and closes the gate when no obstacle is detected. Additionally, the system tracks visitors, and displays a **"Thank you for visiting"** message when they leave.

## Features
- **Motion Detection**: Uses IR sensors to detect entry and exit.
- **Gate Control**: Opens and closes the gate using a DC motor controlled by a motor driver.
- **LED Dot Matrix Display**: Displays a **Welcome** message when entering and a **Thank you for visiting** message when exiting.
- **Visitor Tracking**: Tracks the number of people who have entered and exited.
- **LED Indicators**: Displays green LEDs for entry and exit access.

## Technologies Used
- **Arduino** or **NodeMCU** for microcontroller.
- **IR Sensors**: To detect entry and exit.
- **DC Motor**: To open and close the gate.
- **Motor Driver**: To control the DC motor.
- **LED Dot Matrix**: For displaying messages.
- **LEDs**: To indicate access granted.

## Hardware Requirements
- Arduino or NodeMCU
- IR Sensors (2)
- DC Motor
- Motor Driver (L298N or similar)
- LED Dot Matrix
- LEDs (2)
- Jumper wires and breadboard

## Software Requirements
- Arduino IDE
- Libraries for Servo, IRremote, and Adafruit LED Matrix

## Setup and Installation
1. **Download Arduino IDE**: If you don’t have it installed, download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. **Install Libraries**:
   - **IRremote**: For IR sensor handling.
   - **Adafruit GFX**: For controlling the LED matrix.
   - **Adafruit LED Backpack**: For controlling the LED dot matrix.
3. **Upload Code**: Open the Arduino IDE, copy the code provided above, and upload it to your Arduino.

## Usage
1. When someone approaches the gate, the **entry IR sensor** triggers the system.
2. The gate opens, the **Welcome** message is displayed, and the **entry LED** lights up.
3. After a delay, the gate closes.
4. If someone exits, the **exit IR sensor** triggers the system, displaying a **Thank you for visiting** message, and the **exit LED** lights up.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
