#include <SoftwareSerial.h>
SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan

void setup()
{
  Serial.begin(9600);
  Serial.println("Bluetooth_4");
  BT1.begin(9600);
}

void loop()
{
  if (BT1.available()){
    String s = getLineFromBt();
    Serial.println("Received data-> " + s);
  }

}

String getLineFromBt() {
  String S = "" ;
  if (BT1.available())
  { char c = BT1.read(); ;
    while ( c != '\n')            //Hasta que el caracter sea intro
    { S = S + c ;
      delay(25) ;
      c = BT1.read();
    }
    return S ;
  }
}

