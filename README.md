# Smart Home Embedded System

**Final Project – Interfacing with 8-Bit Microcontrollers**

**280-Hour Embedded Systems Diploma**

**Completed: September 2024**

---

## Description

This repository contains the final project of the **Interfacing with 8-Bit Microcontrollers** module, completed as part of a **280-hour Embedded Systems Diploma**.

The project demonstrates the development of a Smart Home embedded system based on the **PIC18F46K20** microcontroller. It integrates multiple peripherals and communication protocols, including I²C, UART, EEPROM, RTC, temperature sensing and motor control. The complete system was first designed and verified in **Proteus** before being implemented on hardware.

The application uses the **MPLAB Code Configurator (MCC)** to generate the peripheral drivers for the PIC18F46K20.

In addition, this repository includes the **self-written peripheral drivers** developed throughout the Embedded Systems Diploma. These drivers are located in the **`Diploma/application.X/`** directory and demonstrate manual implementation of embedded drivers without using MCC.

---

## Objectives

- Develop a Smart Home embedded application using a PIC18F46K20
- Interface multiple peripherals and external devices
- Implement communication using UART and I²C
- Store persistent data using external EEPROM
- Read date and time from an RTC
- Monitor temperature and automatically control a fan
- Validate the complete system using Proteus simulation

---

## Features

- PIC18F46K20 microcontroller
- MPLAB X IDE
- MPLAB Code Configurator (MCC)
- Proteus simulation
- UART communication
- I²C communication
- External EEPROM (24C02)
- DS1307 Real-Time Clock
- TC74 temperature sensor
- L298 motor driver
- Fan control
- Persistent settings stored in EEPROM
- Serial terminal monitoring

---

## System Overview

The Smart Home system continuously monitors the ambient temperature using a TC74 temperature sensor.

When the measured temperature exceeds the predefined threshold (35 °C), the master microcontroller sends a command via the I²C bus to a second microcontroller operating in slave mode. The slave activates a DC motor through an L298 driver, representing an automatic cooling fan.

The system also communicates with:

- DS1307 RTC for date and time
- External EEPROMs for persistent data storage
- PC via UART for monitoring and debugging

---

## Hardware

### Microcontroller

- PIC18F46K20

### Communication

- UART (EUSART)
- I²C (MSSP)

### Sensors

- TC74 Temperature Sensor
- DS1307 RTC

### Memory

- 2 × 24C02 EEPROM

### Actuator

- DC Motor
- L298 Motor Driver

---

## Software

### Development Environment

- MPLAB X IDE
- MPLAB Code Configurator (MCC)
- Proteus Professional

### Programming Language

- Embedded C

---

## Repository Structure

```text
Smart-Home-Embedded-System/
│
├── README.md
│
├── SmartHome_Project/
│   ├── application.X/
│   └── Proteus/
│
Diploma/
└── application.X/
│   ├── MCAL_Layer/
│   │   ├── GPIO
│   │   ├── Interrupt
│   │   ├── Timer0
│   │   ├── Timer1
│   │   ├── Timer2
│   │   ├── Timer3
│   │   ├── ADC
│   │   ├── CCP
│   │   ├── USART
│   │   ├── MSSP_I2C
│   │   ├── MSSP_SPI
│   │   └── EEPROM
│   │
│   └── ECU_Layer/
│       ├── LED
│       ├── Button
│       ├── Relay
│       ├── DC Motor
│       ├── Character LCD
│       └── Keypad
│
├── images/
│   ├── proteus_overview.png
│   ├── simulation_running.png
│   └── hardware.jpg
│
└── videos/
    └── smart_home_demo.mp4
```

---

## Proteus Simulation

The complete Smart Home application was designed, tested and verified using Proteus before deployment on physical hardware.

<p align="center">
<img src="images/proteus_overview.png" width="80%">
</p>

Simulation while running:

<p align="center">
<img src="images/simulation_running.png" width="80%">
</p>

---

## Embedded Driver Library

In addition to the Smart Home application, this repository contains the embedded software developed throughout the **Interfacing with 8-Bit Microcontrollers** module.

The source code follows a layered architecture consisting of:

- **MCAL (Microcontroller Abstraction Layer)** for low-level peripheral drivers
- **ECU Layer** for reusable hardware components and application devices

The Smart Home application uses the **MPLAB Code Configurator (MCC)** for peripheral initialization on the PIC18F46K20.

The `Diploma/application.X` project, however, contains manually developed embedded drivers and reusable modules created during the diploma to gain a deeper understanding of low-level embedded software development.

### MCAL Layer

The MCAL layer contains peripheral drivers for:

- GPIO
- External Interrupts
- Timer0–Timer3
- ADC
- CCP (Capture/Compare/PWM)
- USART
- MSSP (I²C)
- MSSP (SPI)
- Internal EEPROM

### ECU Layer

The ECU layer contains reusable drivers for external hardware components:

- LED
- Push Button
- Relay
- DC Motor
- Character LCD
- Keypad

---

## Technologies

- Embedded C
- MPLAB X IDE
- MPLAB Code Configurator (MCC)
- PIC18F46K20
- PIC18F4620
- Proteus Professional
- Layered Embedded Architecture
- MCAL
- ECU Layer
- UART
- I²C
- SPI
- EEPROM
- RTC

---

## Author

**Ali Elbaradie**

M.Sc. Mechanical Engineering (Mechatronics)
University of Duisburg-Essen
