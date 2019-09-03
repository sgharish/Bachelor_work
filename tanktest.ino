#define Water_Level_Sensor 2 
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int buttonState = 1; // variable for reading the pushbutton status

void setup() 
{ 
mySerial.begin(9600);
Serial.begin(9600); 
pinMode(Water_Level_Sensor, INPUT);
  Serial.println( );
}

void loop() 
{ 
  buttonState = digitalRead(Water_Level_Sensor); 
  if (buttonState == HIGH) 
  {
    Serial.println( "WATER LEVEL - HIGH");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919092855909\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.print("I am SMS from GSM Module.Water level is high");// The SMS text you want to send
  mySerial.write(0x1a);
  
  delay(5000);
} 
else { 
Serial.println( "WATER LEVEL - LOW" );
mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919092855909\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("I am SMS from GSM Module. Water level is low");// The SMS text you want to send
  delay(100);
  mySerial.write(0x1a);
  delay(5000);
} 


}
//void setup() {
  // put your setup code here, to run once:

//}

//void loop() {
  // put your main code here, to run repeatedly:

//               }
