# Smart Home Embedded System

**Final Project – Interfacing with 8-Bit Microcontrollers**

**280-Hour Embedded Systems Diploma**

**Completed:** September 2024

---

## Overview

This repository contains the final project of the **Interfacing with 8-Bit Microcontrollers** module, completed as part of a **280-hour Embedded Systems Diploma**.

The project demonstrates the development of a **Smart Home embedded system** based on the **PIC18F46K20** microcontroller. It integrates multiple peripherals and communication protocols, including **UART**, **I²C**, **EEPROM**, **RTC**, temperature sensing and motor control. The complete system was designed and validated using **Proteus** before hardware implementation.

The Smart Home application utilizes the **MPLAB Code Configurator (MCC)** for peripheral initialization and driver generation on the PIC18F46K20.

In addition to the final project, this repository includes the **`diploma/`** directory, which contains the manually developed embedded software created throughout the diploma. The source code is organized using a layered architecture consisting of **MCAL (Microcontroller Abstraction Layer)** and **ECU Layer**, providing reusable peripheral and hardware abstraction drivers implemented without relying on **MCC**.

---

## Objectives

- Develop a Smart Home application using the PIC18F46K20
- Implement communication using UART and I²C
- Interface external peripherals and sensors
- Store persistent data using external EEPROM
- Read date and time from a DS1307 RTC
- Automatically control a cooling fan based on temperature measurements
- Validate the complete embedded system using Proteus simulation

---

## Features

- PIC18F46K20 microcontroller
- Embedded C
- MPLAB X IDE
- MPLAB Code Configurator (MCC)
- Proteus Professional simulation
- UART (EUSART)
- I²C (MSSP)
- DS1307 Real-Time Clock
- TC74 temperature sensor
- 2 × 24C02 EEPROM
- L298 motor driver
- DC motor (cooling fan)
- Persistent EEPROM storage
- UART terminal monitoring

---

## System Overview

The Smart Home system continuously monitors the ambient temperature using a **TC74 digital temperature sensor**.

When the measured temperature exceeds the predefined threshold (**35 °C**), the master microcontroller sends a command through the **I²C bus** to a second microcontroller operating in slave mode. The slave activates a **DC motor** through an **L298 motor driver**, representing an automatic cooling fan. The fan remains active until the measured temperature falls below the configured threshold.

The system also communicates with:

- DS1307 RTC for date and time
- External EEPROM devices for persistent configuration storage
- PC through UART for monitoring and debugging

---

## Hardware

### Microcontroller

- PIC18F46K20

### Communication

- UART (EUSART)
- I²C (MSSP)

### Sensors

- TC74 Temperature Sensor
- DS1307 Real-Time Clock

### Memory

- 2 × 24C02 EEPROM

### Actuation

- L298 Motor Driver
- DC Motor (Cooling Fan)

---

## Software

### Programming Language

- Embedded C

### Development Environment

- MPLAB X IDE
- MPLAB Code Configurator (MCC)
- Proteus Professional

### Architecture

- MCC-generated drivers (Smart Home application)
- Layered MCAL / ECU architecture (Diploma drivers)

---

## Proteus Simulation

The complete Smart Home application was designed, tested and validated using **Proteus Professional** before deployment on physical hardware.

### System Simulation

<p align="center">
<img src="images/simulation_running.png" width="85%">
</p>

## Demonstration

The **`videos/smart_home_demo.mp4`** video demonstrates how to set up and operate the Smart Home application, including sensor monitoring, inter-microcontroller communication, EEPROM storage, RTC functionality and automatic fan control.

🎥 [Smart Home Demo](videos/smart_home_demo.mp4)

---

## Embedded Driver Library

Besides the Smart Home application, this repository contains the embedded software developed throughout the **Interfacing with 8-Bit Microcontrollers** module.

The **`diploma/`** directory contains the manually developed embedded software created during the diploma. The code follows a layered architecture consisting of:

- **MCAL (Microcontroller Abstraction Layer)** for low-level peripheral drivers
- **ECU Layer** for reusable hardware abstraction drivers
- **Examples** demonstrating the usage of the implemented drivers

Unlike the Smart Home application, which uses the **MPLAB Code Configurator (MCC)**, all drivers inside the **`diploma/`** directory were implemented manually to gain a deeper understanding of low-level embedded software development.

### MCAL Layer

The MCAL layer contains drivers for:

- GPIO
- External Interrupts
- Timer0 – Timer3
- ADC
- CCP (PWM)
- USART
- MSSP (I²C)
- MSSP (SPI)
- Internal EEPROM

### ECU Layer

The ECU layer contains reusable drivers for:

- LED
- Push Button
- Relay
- DC Motor
- 7-Segment
- Character LCD
- Keypad

---

## Technologies

### Programming

- Embedded C

### IDE & Development

- MPLAB X IDE
- MPLAB Code Configurator (MCC)

### Simulation

- Proteus Professional

### Microcontrollers

- PIC18F46K20
- PIC18F4620

### Communication

- UART (EUSART)
- I²C (MSSP)
- SPI (MSSP)

### Software Architecture

- MCAL
- ECU Layer
- Layered Software Architecture

### Peripherals

- EEPROM
- RTC
- ADC
- CCP (PWM)

---

## Project Status

🚧 This repository is under active development.

Additional Smart Home features, embedded software modules and hardware peripherals will be integrated over time while maintaining a modular and reusable software architecture.

---

## Roadmap

Planned future developments include:

- Password-protected access using a keypad
- LCD-based user interface for real-time system monitoring
- Automatic lighting control using an LDR through the ADC module
- PWM-based fan speed control using the CCP module
- Timer-based task scheduling
- Integration of additional Smart Home sensors and actuators

---

## Repository Structure

```text
Smart-Home-Embedded-System/
│
├── README.md
│
├── SmartHome_Project/
│   ├── SmartHome.X/              # Master MCU firmware
│   ├── SmartHome_SlaveMCU.X/     # Slave MCU firmware
│   ├── Design/                   # Proteus project files 
│   └── Data Sheets/              # Component datasheets
│
├── diploma/
│   ├── MCAL_Layer/               # Self-written peripheral drivers
│   ├── ECU_Layer/                # Self-written hardware abstraction drivers
│   ├── Examples/                 # Driver usage examples
│   ├── application.c
│   ├── application.h
│   └── Makefile
│
├── images/
│   ├── proteus_overview.png
│   └── simulation_running.png
│
└── videos/
    └── smart_home_demo.mp4
```

---

## Documentation

This repository includes the complete source code, Proteus simulation files, datasheets and supporting materials required to understand and reproduce the project.

---

## Author

**Ali Elbaradie**

M.Sc. Mechanical Engineering (Mechatronics)

University of Duisburg-Essen
