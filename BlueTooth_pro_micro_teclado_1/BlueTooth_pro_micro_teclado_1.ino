#include <SoftwareSerial.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {7, 10, 16, 14}; //connect to the row pinouts of the keypad (1,2,3,4)
byte colPins[COLS] = {15, 18, 19}; //connect to the column pinouts of the keypad (5,6,7)

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int rxPin = 8;
int txPin = 9;
int vccPin = 3;
int keyPin = 2;

char c = ' ';
SoftwareSerial BT1 = SoftwareSerial (rxPin, txPin); // RX | TX
void setup() {
  pinMode(vccPin, OUTPUT);        // Al poner en HIGH forzaremos el modo AT
  pinMode(keyPin, OUTPUT);        // cuando se alimente de aqui
  digitalWrite(keyPin, HIGH);
  delay (500) ;              // Espera antes de encender el modulo
  Serial.begin(9600);
  Serial.println("BlueTooth_pro_micro_teclado_1");
  Serial.println("Levantando el modulo HC-06");
  digitalWrite (vccPin, HIGH);    //Enciende el modulo
  Serial.println("Esperando comandos AT:");
  BT1.begin(38400);
}

void loop()
{
    char customKey = customKeypad.getKey();
    if (customKey) {
      BT1.write(customKey);
      Serial.println(customKey);
    }
//  if (BT1.available()) {
//    //Serial.println("BT1.avialable");
//    c = BT1.read();
//    Serial.write(c);
//  }
//  if (Serial.available()) {
//    //Serial.println("Serial.avialable");
//    c = Serial.read();
//   
//    BT1.write(c);
//  }

}
