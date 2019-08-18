/*
   sketch para lanzar un valor analogico por el puerto serie del bluetooth
   El valor analogico se lee de un potenciometro.
*/

#include <SoftwareSerial.h>
//
#define MARGIN 3

int rxPin = 16;
int txPin = 10;

//joystick
int pinX = A0;
int pinY = A1;
int pinK = 4;

// botones
int pinA = 14;
int pinB = 9;
int pinC = 8;
int pinD = 7;
int pinE = 6;
int pinF = 5;

int errorX = 0;
int errorY = 0;

SoftwareSerial BT1 = SoftwareSerial (rxPin, txPin); // RX | TX

void setup() {

  //JoyStick
  pinMode(INPUT, pinX);
  pinMode(INPUT, pinY);
  pinMode(INPUT, pinK);

  // botones
  pinMode(INPUT, pinA);
  pinMode(INPUT, pinB);
  pinMode(INPUT, pinC);
  pinMode(INPUT, pinD);
  pinMode(INPUT, pinE);
  pinMode(INPUT, pinF);

  Serial.begin(9600);
  Serial.println("BlueTooth_pro_micro_potenciommetro_4");
  Serial.println("Calibrado del mando");

  errorX = abs(getXValue());
  errorY = abs(getYValue());


  BT1.begin(38400);
}

void loop() {
  //Lectura del valor analogico

  String comandoAEnviar = "";
  comandoAEnviar += getXValue();
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += getYValue();
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinK);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinA);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinB);
  delay(1); 
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinC);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinD);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinE);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += digitalRead(pinF);
  delay(1);


  BT1.println(comandoAEnviar);
  delay(100);
}

int getXValue() {
  return getAxis(pinX, errorX - MARGIN, errorX + MARGIN);
}

int getYValue() {
  return getAxis(pinY, errorY - MARGIN, errorY + MARGIN);
}

int getAxis(int axisPin, int leftMargin, int rigthMargin) {
  int val = analogRead(axisPin);
  delay(1);
  if (val <= rigthMargin && val >= leftMargin) {
    val = 512;
  }
  return constrain(val, 0, 1024);
}

