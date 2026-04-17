# SUBD25Helipot
Custom control board based on the PIC16F15244 with RS-485 communication, helipot input, and 7-segment display feedback.

## ⚙️ Functionality

The system uses a helical potentiometer (helipot) as the main input. By rotating the helipot, the board sends control signals to increase or decrease the output voltage of a connected device.

The current position is displayed on 7-segment displays as a value from **0 to 1023**, providing a visual indication of the adjustment level.

The system has been tested and verified to work reliably.

## 💻 Firmware

This repository includes the firmware responsible for:
- Reading the helipot input  
- Handling RS-485 communication  
- Driving the 7-segment displays  

## 🧩 Hardware Design

The repository also includes hardware design files:
- Schematic (circuit design)  
- PCB layout (printed circuit board design)  
