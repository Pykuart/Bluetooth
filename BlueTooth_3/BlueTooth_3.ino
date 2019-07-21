#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // RX, TX recorder que se cruzan

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BT1.begin(9600);
}

void loop()
{
  if (BT1.available()){
    String s = getLineFromBt();
//    Serial.print(s);
    Serial.println("Received data-> " + s);
  }

//  if (Serial.available())
//    BT1.write(Serial.read());

  if (Serial.available())
  { String S = GetLine();
    BT1.print(S);
    Serial.println("---> " + S);
  }
}

String GetLine() {
  String S = "" ;
  if (Serial.available())
  { char c = Serial.read(); ;
    while ( c != '\n')            //Hasta que el caracter sea intro
    { S = S + c ;
      delay(25) ;
      c = Serial.read();
    }
    return ( S + '\n') ;
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
    return ( S + '\n') ;
  }
}

