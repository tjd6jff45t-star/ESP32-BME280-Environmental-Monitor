# ESP32 EnvironmentalMonitoring System

An embedded environmental monitoring system built with an ESP32 and BME280 sensor using I2C communication. The project measures temperature, humidity, and atmospheric pressure, includes sensor health monitoring with an LED status indicator, and was developed from a working breadboard prototype into a custom KiCad PCB design with completed DRC and manufacturing files.


Project Overview

The goal of this project was to design and build a complete embedded sensing system from prototype through PCB design. The system uses an ESP32 microcontroller to communicate with a BME280 environmental sensor over the I2C protocol. Firmware was written in C++ using PlatformIO to collect temperature, humidity, and pressure data, display the measurements through the Serial Monitor, and detect sensor communication failures.

After verifying the circuit on a breadboard, the design was recreated in KiCad. A custom PCB layout was developed for the ESP32 development board, BME280 breakout module, and LED status circuit. The PCB was routed, checked using KiCad's Design Rules Checker, and exported as Gerber and drill files for manufacturing.

## Technical Highlights

- Developed embedded firmware in C++ using PlatformIO and the Arduino framework.
- Communicated with a BME280 environmental sensor over I2C using ESP32 GPIO 21 for SDA and GPIO 22 for SCL.
- Verified the sensor address using an I2C scanner and confirmed communication at `0x76`.
- Measured temperature, humidity, and atmospheric pressure and displayed live values through the Serial Monitor.
- Replaced blocking `delay()` timing with `millis()`-based timing for smoother, non-blocking operation.
- Added sensor health checks to detect invalid readings and communication failures.
- Implemented an external LED status indicator for sensor operation and fault conditions.
- Designed the system schematic and PCB layout in KiCad.
- Completed PCB routing, ground copper fill, board outline, and Design Rules Check with no remaining errors.
- Generated Gerber and drill files for PCB manufacturing.
