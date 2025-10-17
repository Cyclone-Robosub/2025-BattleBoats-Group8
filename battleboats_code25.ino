#include "motors.h"
#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);
  // initialize motor and ultrasonics
  motorInit();
  ultrasonicInit();
}

void loop() {
  // delay
  driveForward(255);
  // start, drive forward 800 mm
  // have ultrasonic sensor detect if the distance is 200 mm 
  float dist = readDistanceCM();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 20) {
    driveForward(255);
  } else {
    driveStop();
    // turn down the right motor a little bit
    turnRight(150);
    driveForward(150);
  }

  if (dist > 20) {
    driveforward(100);
  } else {
    driveStop();
    turnLeft(255);
    driveForward(150);
  }

  if (dist > 20) {
    driveforward(100);
  } else {
    driveStop();
    turnRight(255);
    driveForward(255);
  }

  delay(100);
}
