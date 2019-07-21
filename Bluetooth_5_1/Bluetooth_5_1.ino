/*
 * investigar por que no funciona con la clase 
*/

#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan

class CommandValues {

  public:
    void setCommandValues(String);
  protected:
    int _throttle;
    int _yaw;
    int _pitch;
    int _roll;
  private:
    int normalizeValue(int);

};

CommandValues commanValues;

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

    commanValues.setCommandValues(commandFromBT);

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




void CommandValues::setCommandValues(String commandFromBt) {
  static char _regex[2] = ",";
  char p[commandFromBt.length()];

  commandFromBt.toCharArray(p, commandFromBt.length() + 1);

  _throttle = normalizeValue(atoi(strtok(p, _regex)));
  _yaw = normalizeValue(atoi(strtok(NULL, _regex)));
  _pitch = normalizeValue(atoi(strtok(NULL, _regex)));
  _roll = normalizeValue(atoi(strtok(NULL, _regex)));

  return;
}

int CommandValues::normalizeValue(int adcValue) {
  return map(adcValue, 0, 1023, -400, 400);
}

