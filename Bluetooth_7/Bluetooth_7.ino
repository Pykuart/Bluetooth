#include <SoftwareSerial.h>
#include <string.h>

SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan
void setup()
{
  Serial.begin(9600);
  Serial.println("Bluetooth_6");
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

    int xVal = normalizeValue(atoi(strtok(p, _regex)));
    int yVal = normalizeValue(atoi(strtok(NULL, _regex)));
    bool kVal = atoi(strtok(NULL, _regex));
    bool aVal = atoi(strtok(NULL, _regex));
    bool bVal = atoi(strtok(NULL, _regex));
    bool cVal = atoi(strtok(NULL, _regex));
    bool dVal = atoi(strtok(NULL, _regex));
    bool eVal = atoi(strtok(NULL, _regex));
    bool fVal = atoi(strtok(NULL, _regex));

    Serial.print("xVal: ");
    Serial.print(xVal);
    Serial.print(", yVal: ");
    Serial.print(yVal);
    Serial.print(", kVal: ");
    Serial.print(kVal);
    Serial.print(", aVal: ");
    Serial.print(aVal);
    Serial.print(", bVal: ");
    Serial.print(bVal);
    Serial.print(", cVal: ");
    Serial.print(cVal);
    Serial.print(", dVal: ");
    Serial.print(dVal);
    Serial.print(", eVal: ");
    Serial.print(eVal);
    Serial.print(", fVal: ");
    Serial.print(fVal);
    Serial.println("");

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

int normalizeValue(int adcValue) {
  return map(adcValue, 0, 1023, -400, 400);
}

