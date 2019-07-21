/*
   sketch para lanzar un valor analogico por el puerto serie del bluetooth
   El valor analogico se lee de un potenciometro.
*/

#include <SoftwareSerial.h>
// 
#define BUFF_SIZE 52 

int rxPin = 8;
int txPin = 9;
//acelerador (eje vertical mando izquierdo)
int throttlePin = A0;
//timon (eje horizontal mando izquierdo)
int yawPin = A1;
//elevador (eje vertical mando derecho)
int pitchPin = A2;
//aleron (eje horizontal mando derecho)
int rollPin = A3;

char c = ' ';
SoftwareSerial BT1 = SoftwareSerial (rxPin, txPin); // RX | TX
void setup() {

  Serial.begin(9600);
  Serial.println("BlueTooth_pro_micro_potenciommetro_1");
  Serial.println("Levantando el modulo HC-06");
  BT1.begin(38400);

  pinMode(INPUT, throttlePin);
  pinMode(INPUT, yawPin);
  pinMode(INPUT, pitchPin);
  pinMode(INPUT, rollPin);
}

void loop() {
  //Lectura del valor analogico

  String comandoAEnviar = "";
  comandoAEnviar += analogRead(throttlePin);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += analogRead(yawPin);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += analogRead(pitchPin);
  delay(1);
  comandoAEnviar += ',';
  comandoAEnviar += analogRead(rollPin);
  comandoAEnviar += ',';

  comandoAEnviar += '\n';

  Serial.println(comandoAEnviar.length());


    char caValPot[comandoAEnviar.length()];
  
    comandoAEnviar.toCharArray(caValPot, comandoAEnviar.length() + 1);
    if (caValPot) {
    Serial.write(caValPot);
      BT1.write(caValPot);
    }
//  Serial.print("ValorPotenciometro: ");
//  Serial.println(comandoAEnviar);

  //  if (BT1.available()) {
  //    c = BT1.read();
  //    Serial.write(c);
  //  }
  //  if (Serial.available()) {
  //    c = Serial.read();
  //    Serial.write(c);
  //    BT1.write(c);
  //  }

  delay(1000);
}
