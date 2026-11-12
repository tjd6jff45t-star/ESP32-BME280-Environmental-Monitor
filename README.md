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


## Prototype and Test Results

The system was first verified as a breadboard prototype before moving into PCB design.
<img width="2268" height="4032" alt="ESP32" src="https://github.com/user-attachments/assets/1e8e2d45-dcc2-4194-9cac-f5cd5c5d4c74" />
<img width="2268" height="4032" alt="BME280_sensor" src="https://github.com/user-attachments/assets/4749b228-80a3-4d94-b7fa-7a87ccf7bcd5" />
<img width="2268" height="4032" alt="led_circuit" src="https://github.com/user-attachments/assets/c1f100a2-a3ba-4a8c-980b-3fdc03796fca" />
Note: Breadboard prototype showing the ESP32 development board connected to the BME280 environmental sensor over I2C.

## Schematic and PCB Design
<img width="881" height="693" alt="final_shematic" src="https://github.com/user-attachments/assets/b17e636d-56f5-4be8-b01f-33226e522fcd" />
Note: Final KiCad schematic representing the ESP32 development board, BME280 module, and LED status circuit.

<img width="1825" height="2665" alt="2D_PCB_(2)" src="https://github.com/user-attachments/assets/a8198e35-3f49-49d5-9c72-9da34ca3e73b" />
Note: Final PCB layout showing component placement, routed traces, ground copper fill, and completed board outline.

<img width="3213" height="5712" alt="final_PCB_(1)" src="https://github.com/user-attachments/assets/1a7f93c1-e1b7-4b61-8341-0755de914dad" />
<img width="3213" height="5712" alt="final_PCB_(2)" src="https://github.com/user-attachments/assets/243a83b0-d557-41ff-96b8-4dd33b8c9c0f" />
<img width="2268" height="4032" alt="final_PCB_(3)" src="https://github.com/user-attachments/assets/1b3ec443-f03b-40d8-a1e6-3ff68099b5c1" />
Note: KiCad 3D view of the completed PCB design used to verify component placement and board layout before manufacturing export.

## Manufacturing Outputs

The PCB design was checked using KiCad's Design Rules Checker with no remaining errors. Gerber and drill files were then generated for PCB manufacturing.

Generated fabrication files include:

- Front and back copper layers
- Front and back solder mask layers
- Front and back silkscreen layers
- Board outline (`Edge.Cuts`)
- Plated through-hole drill file
- Non-plated through-hole drill file

### I2C Communication Test
An I2C scanner was used to confirm communication between the ESP32 and the BME280. The sensor was successfully detected at address: 0x76
<img width="2268" height="4032" alt="sensor_adress" src="https://github.com/user-attachments/assets/5784e3d8-1cc7-4575-b6c4-4917d2736fb2" />
Note: I2C scanner output confirming successful communication with the BME280 at address 0x76.

### Environmental Sensor Readings
The ESP32 successfully collected and displayed live:

- Temperature
- Relative humidity
- Atmospheric pressure

The readings were displayed through the Serial Monitor and updated at regular intervals.
<img width="2268" height="4032" alt="senor_data_collection" src="https://github.com/user-attachments/assets/f5384f95-2264-48d8-bd92-5f486e80b3f3" />


### Sensor Health Monitoring
The firmware included checks for invalid sensor readings and startup communication failures. A disconnected sensor produced an error message, while normal operation reported:

Sensor Status: OK

### LED Status Indicator
An external LED connected to GPIO 2 was used as a hardware status indicator. The LED remained active during normal sensor operation and was used to indicate fault conditions during testing.

### Challenges & What I Learned
One of the major difficulties faced in this project was moving from the functional breadboard setup to designing a PCB that faithfully represents the development boards and modules used. I started with bare chip symbols in KiCad and then updated the design to include connector-based symbols for the ESP32 development board and the BME280 breakout module. Further, I have learned how to debug serial communication, identify the I2C address of the BME280, handle cases where sensor readings fail, and improve the firmware code to replace delay() calls with calls to millis() for timing. In the PCB part of the project, I got hands-on experience in placing footprints, placing components, routing, using ground plane, defining board outline, performing DRC, and generating manufacturing files.


## Project Videos

### LED Control and PWM Test
Short demonstration of GPIO control, LED blinking, and PWM brightness control.

[Watch Video](https://youtu.be/5xzfCAMmV3Y?si=MW0iVssP8jog2qvU)

### BME280 Sensor Operation
Demonstration of the ESP32 reading temperature, humidity, and pressure from the BME280 over I2C.

[Watch Video](https://youtu.be/nWZxm4SdqU8?si=XMHZjkytFm5WDLaI)

### Sensor Fault Detection
Demonstration of the firmware detecting a disconnected BME280 sensor and reporting the fault condition.

[Watch Video](https://youtu.be/SMHI9AHuyio?si=rTMh6QFZ928x4NxT)
