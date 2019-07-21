#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan
void setup()
{
  Serial.begin(9600);
  Serial.println("Bluetooth_5");
  BT1.begin(9600);
}

void loop()
{
  if (BT1.available()) {
    String commandFromBT = getLineFromBt();
    Serial.print("Received data-> ");
    Serial.println(commandFromBT);

    char p[commandFromBT.length()];
    static char _regex[2] = ",";


    commandFromBT.toCharArray(p, commandFromBT.length() + 1);

    int throttleVal = atoi(strtok(p, _regex));
    int yawVal = atoi(strtok(NULL, _regex));
    int pitchVal = atoi(strtok(NULL, _regex));
    int rollVal = atoi(strtok(NULL, _regex));

    Serial.print("throttleVal: ");
    Serial.println(throttleVal);
    Serial.print("yawVal: ");
    Serial.println(yawVal);
    Serial.print("pitchVal: ");
    Serial.println(pitchVal);
    Serial.print("rollVal: ");
    Serial.println(rollVal);

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

