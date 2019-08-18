#include <SoftwareSerial.h>
#include <string.h>
#include <ZumoShield.h>

//#define DEBUG

ZumoMotors motors;
SoftwareSerial BT1(A0, A1); // RX, TX recorder que se cruzan

int yCorrection = 0;

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

    char p[commandFromBT.length()];
    static char _regex[2] = ",";


    commandFromBT.toCharArray(p, commandFromBT.length() + 1);

    int xVal = map(atoi(strtok(p, _regex)), 0, 1023, -100, 100);
    int yVal = map(atoi(strtok(NULL, _regex)), 0, 1023, -250, 250);
    bool kVal = atoi(strtok(NULL, _regex));
    bool aVal = atoi(strtok(NULL, _regex));
    bool bVal = atoi(strtok(NULL, _regex));
    bool cVal = atoi(strtok(NULL, _regex));
    bool dVal = atoi(strtok(NULL, _regex));
    bool eVal = atoi(strtok(NULL, _regex));
    bool fVal = atoi(strtok(NULL, _regex));

#ifdef DEBUG
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
    Serial.print(", yCorrection: ");
    Serial.print(yCorrection);
    Serial.println("");
#endif

    motors.setLeftSpeed(yVal + yCorrection + xVal);
    motors.setRightSpeed(yVal - yCorrection - xVal);

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

