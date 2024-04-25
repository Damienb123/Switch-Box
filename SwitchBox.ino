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
