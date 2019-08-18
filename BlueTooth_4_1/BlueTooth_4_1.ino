/*
   Recepcion del puerto bluetooth.
   igual que el resto de pruebas anteriores, es totalmente pasivo.
   La unica diferencia es que la funci{on que lee el receptor, en vez de cmponer la linea el, la lee al completo utilizando la funcionalidad de la clase Sesial.
*/

#include <SoftwareSerial.h>
SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan

void setup()
{
  Serial.begin(9600);
  Serial.println("Bluetooth_4_1");
  BT1.begin(9600);
}

void loop()
{
  if (BT1.available()) {
    String s = getLineFromBt();
    Serial.println("Received data-> " + s);
  }

}

String getLineFromBt() {
  String S = "" ;
  if (BT1.available())
  {
    S = BT1.readStringUntil('\n');
  }
  return S ;
}

