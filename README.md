# ILGhelipot
Custom-designed control board built around the PIC16F15224 microcontroller.

## Functionality

The system uses a helical potentiometer (helipot) as the main input. By rotating the helipot, the board generates a PWM signal that can be used to control external devices.

The PWM duty cycle is adjusted based on the helipot position, allowing precise and smooth control.

## Firmware

This repository includes the firmware responsible for:
- Reading the helipot input  
- Generating the PWM signal  
- Controlling system behavior  

## Hardware Overview

The board includes:
- PIC16F15224 microcontroller  
- 7805 voltage regulator  
- SUB-D25 connector for signal interfacing  

## Hardware Design

The repository also includes hardware design files:
- Schematic (circuit design)  
