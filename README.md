
# Line Follower Robot

A fully autonomous Line Follower Robot built using ATmega16A microcontroller, TCRT5000 IR sensors, and L293D motor driver. This project is designed for accurate path-following based on IR sensor input, featuring a custom-designed PCB and modular embedded C code.

---

## Overview

The robot detects and follows a black line on a white surface using a curved array of 8 TCRT5000 IR sensors. Sensor input is processed by the ATmega16A to control motor direction and speed via PWM, allowing the robot to navigate along the line in real-time.

This project is an ideal entry point into embedded systems, robotics, and control systems.

---

## Hardware Components

| Component                 | Quantity | Description                                      |
|--------------------------|----------|--------------------------------------------------|
| ATmega16A                | 1        | Main microcontroller                            |
| TCRT5000 IR Sensor       | 8        | Infrared sensors for line detection              |
| L293D Motor Driver IC    | 1        | Dual H-bridge for motor control                  |
| BO Motors                | 2        | Geared DC motors                                 |
| LM7805 Voltage Regulator | 1        | 5V regulator for stable power supply             |
| Capacitors, Resistors    | -        | Supporting passive components                    |
| Custom PCB               | 1        | Designed for compact integration                 |
| Wheels, Chassis          | -        | Mechanical body of the robot                     |

---

## Working Principle

The robot moves along a black line using IR reflection: the sensors detect the contrast between the black line and the white surface. The microcontroller reads the digital values from the sensor array, processes the data, and adjusts motor behavior accordingly.

---

## Code and Logic

- Developed using **Atmel Studio 7** and **CodeVisionAVR**.
- Logic written in **embedded C**, optimized for speed and clarity.
- Uses **bit-wise operations** to read sensor states and control motor direction and speed via PWM.

```c
if(sensor_value == 0b00011000) {
    // Move forward
} else if(sensor_value == 0b00010000) {
    // Slight left
}
```





## Schematic Circuit

Below are the schematic diagrams and PCB layouts designed for the line follower robot. These circuits were created to ensure efficient component placement, signal flow, and compact integration for reliable performance.


![App Screenshot](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Schematic%20of%20main%20board.png)

## Sensor Array Circuit

![App Screenshot](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Sensor%20array%20Schematic.png)



## Main Board PCB

| ![Main PCB](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Main%20Board%20PCB.jpeg) | ![Main PCB 3D](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Main%20board%20PCB%203D.png) |
|:--:|:--:|
| Main PCB | Main PCB 3D View |



## Sensor Array PCB

| ![Main PCB](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Sensor%20Array%20PCB%202D.jpeg) | ![Main PCB 3D](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Sensor%20array%20PCB%203D.jpeg) |
|:--:|:--:|
| Main PCB | Main PCB 3D View |


## Final Photo

This the final bot.

![App Screenshot](https://raw.githubusercontent.com/KhushiJ2911/Line-Follower-Robot/refs/heads/main/Line%20Follower%20Media/Final%20Bot.jpeg)

