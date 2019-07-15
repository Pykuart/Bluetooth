#include <SoftwareSerial.h>

int rxPin = 10;
int txPin = 11;
int vccPin = 9;
int keyPin = 8;

char c = ' ';
SoftwareSerial BT1 = SoftwareSerial (rxPin, txPin); // RX | TX
void setup()
{ pinMode(rxPin, INPUT);        // Al poner en HIGH forzaremos el modo AT
  pinMode(txPin, OUTPUT);        // cuando se alimente de aqui
  pinMode(vccPin, OUTPUT);        // Al poner en HIGH forzaremos el modo AT
  pinMode(keyPin, OUTPUT);        // cuando se alimente de aqui
  digitalWrite(keyPin, HIGH);
  delay (500) ;              // Espera antes de encender el modulo
  Serial.begin(9600);
  Serial.println("Levantando el modulo HC-06");
  digitalWrite (vccPin, HIGH);    //Enciende el modulo
  Serial.println("Esperando comandos AT:");
  BT1.begin(38400);
}

void loop()
{
  if (BT1.available()) {
    c = BT1.read();
    Serial.write(c);
  }
  if (Serial.available()) {
      c = Serial.read();
    Serial.write(c);
    BT1.write(c);
  }
}
