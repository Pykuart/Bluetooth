// You could use a spare Hardware Serial on boards that have it (like Mega)
 #include <SoftwareSerial.h>
 SoftwareSerial SwSerial(2, 3); // RX, TX

 #define BLYNK_PRINT SwSerial
 #include <BlynkSimpleStream.h>

 // You should get Auth Token in the Blynk App.
 // Go to the Project Settings (nut icon).
 char auth[] = "7a924352f3ee4e27aee6aeb75dedb5c8";

 void setup()
 {
   // Debug console
   SwSerial.begin(9600);

   // Blynk will work through Serial
   Blynk.begin(auth,SwSerial );
 }

 void loop()
 {
   Blynk.run();
 }
