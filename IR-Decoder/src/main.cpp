#include <Arduino.h>
#include <wpi-32u4-lib.h>
#include <IRdecoder.h>
#include <ir_codes.h>


Chassis chassis(7.0, 1440, 14.9);

const uint8_t IR_DETECTOR_PIN = 1;
IRDecoder decoder(IR_DETECTOR_PIN);


void handleKeyPress(int16_t keyPress){
  Serial.println("Key: " + String(keyPress));
}

void setup() {
  // This will initialize the Serial at a baud rate of 115200 for prints
  // Be sure to set your Serial Monitor appropriately
  Serial.begin(115200);

  // initialize the chassis (which also initializes the motors)
  chassis.init();

  // these can be undone for the student to adjust
  chassis.setMotorPIDcoeffs(5, 0.5);

  // initialize the IR decoder
  decoder.init();

  Serial.println("/setup()");
}

void loop() {
  // Check for a key press on the remote
  int16_t keyPress = decoder.getKeyCode();

  // If valid keypress, print the key value
  if(keyPress >= 0) handleKeyPress(keyPress);
  
}