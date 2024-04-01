# Command-Controlled-Curtain-System

This project focuses on creating a Smart Curtain System using Arduino programming language to enhance home comfort and automation. The system allows users to make precise adjustments to their curtains through user-defined commands, enabling a seamless and customizable experience.

Two separate LDR circuits are used here. One senses the darkness and other one is for light sensing. Deploying two separate circuits, one for sensing the light and the other for the darkness, ensures the proper reversal of rotation of the motor in one of the cases.
LDR and Motor are interfaced for the working

When the light level decreases, the resistance of the LDR increases. As this resistance increases in relation to the other Resistor, which has a fixed resistance, it causes the voltage dropped across the LDR to also increase!

