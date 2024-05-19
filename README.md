# Switch-Box

## Table of Contents

1. [Overview](#Overview) 
2. [Hardware Requirements](#Hardware-Requirements)
3. [Connections](#Connections)
4. [Purpose and Functionality](#Purpose-and-Functionality)
    - Libraries
    - Pin Definitions
    - Motor Interface Type
    - Stepper Motor Instance
    - Setup Function
    - Loop Function
5. [Example Code](#Example-Code)
6. [Usage Instructions](#Usage-Instructions)
7. [Output Example](#Output-Example )

## Overview

This project controls a stepper motor using an Arduino. The stepper motor is configured to move to a specified position and then change direction once it reaches that position. The API is implemented using the AccelStepper library.
 
## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Stepper motor
- Motor driver (e.g., A4988)
- Power supply for the stepper motor
- Connecting wires
 
## Connections

| Arduino Pin | Motor Driver Pin |
| --- | --- |
| 2(dirPin) | DIR |
|  3(stepPin) | STEP |

Ensure to connect the motor driver's GND and VCC pins to the appropriate power supply and the motor's coils to the motor driver's output pins.

## Purpose and Functionality

### Libraries
```
#include <AccelStepper.h>
```
The **AccelStepper** library is used for controlling the stepper motor.

### Pin Definitions
```
const int dirPin = 2;
const int stepPin = 3;
```
**dirPin** and **stepPin** are defined to control the direction and steps of the motor.

### Motor Interface Type
```
#define motorInterfaceType 1
```
Defines the type of motor interface. Here, **1** represents a driver with Step and Direction pins.

### Stepper Motore Instance
```
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);
```
Creates an instance of the **AccelStepper** class.

### Setup Function
```
void setup() {
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(100);
  myStepper.setSpeed(400);
}
```
- **setMaxSpeed(1000):** Sets the maximum speed of the motor to 1000 steps per second.
- **setAcceleration(100):** Sets the acceleration to 100 steps per second squared.
- **setSpeed(400):** Sets the initial speed to 400 steps per second.

### Loop Function
```
void loop() {
  myStepper.moveTo(1000);
  while(1){
    myStepper.run();
    if(myStepper.distanceToGo() == 0)
      break;
  }
  myStepper.moveTo(-100);
  while(1){
    myStepper.run();
    if(myStepper.distanceToGo() == 0)
      break;
  }
}
```
- Moves the motor to position **1000**.
- Runs the motor until it reaches the target position.
- Changes the target position to **-100**.
- Runs the motor until it reaches the new target position.

## Example Code
```
#include <AccelStepper.h>

// define pin connections
const int dirPin = 2;
const int stepPin = 3;

// define motor face type
#define motorInterfaceType 1

// creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

// set the max speed, acceleration factor, // initial speed and the target position
void setup() {
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(100);
  myStepper.setSpeed(400);
}

void loop() {
  // change direction once the motor reaches the target position
  myStepper.moveTo(1000);
  while(1){
    myStepper.run();
    if(myStepper.distanceToGo() == 0)
      break;
  }
  myStepper.moveTo(-100);
  while(1){
    myStepper.run();
    if(myStepper.distanceToGo() == 0)
      break;
  }
}
```
## Usage Instructions

1. Connect the stepper motor and motor driver to the Arduino as specified in the **Connections** section.
2. Upload the example code to the Arduino using the Arduino IDE.
3. Open the Serial Monitor to observe the motor's behavior.

## Output Example

- The stepper motor will move to the position **1000** steps.
- Once it reaches the target position, it will reverse direction and move to **-100** steps.
- The motor will continue this back-and-forth movement indefinitely.

This setup allows for controlled and precise movements of a stepper motor using the **AccelStepper** library. The motor's speed, acceleration, and target positions can be easily adjusted in the code to fit specific requirements.
