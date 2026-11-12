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


## Hardware and Tools Used

### Hardware
- ESP32 development board
- BME280 temperature, humidity, and pressure sensor
- Breadboard
- 220 Ω resistor
- LED
- Jumper wires
- USB-C cable

### Software
- Visual Studio Code
- PlatformIO
- Arduino framework
- C++
- KiCad
- GitHub

### Interfaces and Techniques
- I2C communication
- GPIO control
- PWM
- Serial debugging
- Non-blocking timing with `millis()`
- Sensor fault detection
- PCB schematic capture and layout
- Design Rules Check (DRC)
- Gerber and drill file generation


## System Operation

1. The ESP32 initializes the BME280 sensor over the I2C bus.
2. The firmware checks for the sensor at address `0x76`.
3. Once communication is established, the ESP32 reads:
   - Temperature
   - Relative humidity
   - Atmospheric pressure
4. Sensor data is printed to the Serial Monitor at regular intervals.
5. The firmware uses `millis()` instead of long blocking delays so the microcontroller can continue performing other tasks.
6. If a sensor reading is invalid or communication fails, the firmware reports an error.
7. An external LED provides a visual status indication for normal sensor operation and fault conditions.
