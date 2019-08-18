/*
   sketch para lanzar un valor analogico por el puerto serie del bluetooth
   El valor analogico se lee de un potenciometro.
*/

#include <SoftwareSerial.h>
//
#define BUFF_SIZE 52

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

char c = ' ';
SoftwareSerial BT1 = SoftwareSerial (rxPin, txPin); // RX | TX


void setup() {

  Serial.begin(9600);
  Serial.println("BlueTooth_pro_micro_potenciommetro_3");
  Serial.println("Levantando el modulo HC-06");
  BT1.begin(38400);

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
}

void loop() {
  //Lectura del valor analogico

  String comandoAEnviar = "";
  comandoAEnviar += analogRead(pinX);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += analogRead(pinY);
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

  Serial.println(comandoAEnviar.length());

  Serial.write(comandoAEnviar);

  delay(1000);
}
