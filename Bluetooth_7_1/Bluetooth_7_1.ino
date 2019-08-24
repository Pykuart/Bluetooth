#include <SoftwareSerial.h>
#include <string.h>

#define VELOCIDAD 300


SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan
void setup()
{
  Serial.begin(9600);
  Serial.println("Bluetooth_7_1");
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

    int throttleVal = normalizeValue(atoi(strtok(p, _regex)));
    int yawVal = normalizeValue(atoi(strtok(NULL, _regex)));
    int pitchVal = normalizeValue(atoi(strtok(NULL, _regex)));
    int rollVal = normalizeValue(atoi(strtok(NULL, _regex)));

    Serial.print("throttleVal: ");
    Serial.print(throttleVal);
    Serial.print(", yawVal: ");
    Serial.print(yawVal);
    Serial.print(", pitchVal: ");
    Serial.print(pitchVal);
    Serial.print(", rollVal: ");
    Serial.print(rollVal);
    Serial.println("");

    int vIzq = throttleVal - (yawVal/3);
    int vDer = throttleVal + (yawVal/3);

    Serial.print("vIzq: ");
    Serial.print(vIzq);
    Serial.print(", vDer: ");
    Serial.print(vDer);
    Serial.println("");

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

int normalizeValue(int adcValue) {
  return map(adcValue, 0, 1023, -VELOCIDAD, VELOCIDAD);
}

