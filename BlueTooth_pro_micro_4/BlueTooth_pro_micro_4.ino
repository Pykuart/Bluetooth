// Basic Bluetooth sketch HC-05_03_9600
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on.
// Needs to be placed in to AT mode
// After a factory reset the default baud rate for communication mode is 38400
//
//
//  Pins
//  BT VCC to Arduino 5V out.
//  BT GND to GND
//  BT RX to Arduino pin 3 (through a voltage divider)
//  BT TX to Arduino pin 2 (no need voltage divider)


#include <SoftwareSerial.h>
SoftwareSerial BTserial(8, 9); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.

char c = ' ';

String texto = "";

void setup()
{
  // start the serial communication with the host computer
  Serial.begin(9600);
  Serial.println("Arduino with HC-05 is ready");

  // start communication with the HC-05 using 9600
  BTserial.begin(9600);
  Serial.println("BTserial started at 9600");

}

void loop() {
  BTserial.println("<DOS>");
  delay(1500);
}
