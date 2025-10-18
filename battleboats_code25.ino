#include "motors.h"
#include "ultrasonic.h"


// power pin connected to digital pin 8, direction pin connected to digital pin 9
const int powerPin = 8;
const int directionPin = 9;

void setup() {
  Serial.begin(9600);
  // initialize motor and ultrasonics
  pinMode(directionPin, INPUT);
  pinMode(powerPin, INPUT);
  motorInit();
  ultrasonicInit();
}

void loop() {
  // start when powerPin = HIGH
  int powerReading = digitalRead(powerPin); // read the powerPin
  int directionReading = digitalRead(directionPin); // read the directionPin

  while (powerReading != LOW) {

    driveForward(255);
    // start, drive forward 800 mm

    // have ultrasonic sensor detect if the distance is 200 mm 
    float dist = readDistanceCM();
    Serial.print("Distance: ");
    Serial.print(dist);
    Serial.println(" cm");

    // if the directionPin = LOW -> left, else it's HIGH -> right 

    // check if the direction is right
    if (directionPin == HIGH) {
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
    }
    else { // when directionPin is LOW -> left track
      if (dist > 20) {
        driveForward(255);
      } else {
        driveStop();
        // turn down the right motor a little bit
        turnLeft(150);
        driveForward(150);
      }

      if (dist > 20) {
        driveforward(100);
      } else {
        driveStop();
        turnRight(255);
        driveForward(150);
      }

      if (dist > 20) {
        driveforward(100);
      } else {
        driveStop();
        turnLeft(255);
        driveForward(255);
      }
    }
  } 

  delay(100);
}
