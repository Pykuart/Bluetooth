/*
   sketch para lanzar un valor analogico por el puerto serie del bluetooth
   El valor analogico se lee de un potenciometro.
*/

#include <SoftwareSerial.h>

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
  String throttleVal = String(analogRead(throttlePin), DEC);
  delay(1);
  Serial.print(throttleVal);
  Serial.print(",");
  String yawVal = String(analogRead(yawPin), DEC);
  delay(1);
  Serial.print(yawVal);
  Serial.print(",");
  String pitchVal = String(analogRead(pitchPin), DEC);
  delay(1);
  Serial.print(pitchVal);
  Serial.print(",");
  String rollVal = String(analogRead(rollPin), DEC);
  delay(1);
  Serial.println(rollVal);
  Serial.print(",");

  String comandoAEnviar = "";
  comandoAEnviar += throttleVal;
  comandoAEnviar += ",";
    comandoAEnviar += yawVal;
  comandoAEnviar += ',';
  //  comandoAEnviar += pitchVal;
  comandoAEnviar += ',';
  //  comandoAEnviar += rollVal;
  comandoAEnviar += ',';

  comandoAEnviar += '\n';



  char caValPot[comandoAEnviar.length()];

  comandoAEnviar.toCharArray(caValPot, comandoAEnviar.length() + 1);
  //  if (caValPot) {
  //  Serial.write(caValPot);
  //    BT1.write(caValPot);
  //  }
  Serial.print("ValorPotenciometro: ");
  Serial.println(comandoAEnviar);

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
