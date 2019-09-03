const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 6;
const int echoPin3 = 7;
//const int trigPin4 = 8;
//const int echoPin4 = 9;
const int trigPin5 = 10;
const int echoPin5 = 11;
//const int trigPin6 = 39;
//const int echoPin6 = 41;
const int out1 = 31; // left solenoid
const int out2 = 33; // right solenoid
const int relay1 = 35; // for left motor
const int relay2 = 37;
const int relay3 = 39; // for right motor
const int relay4 = 41;
// defines variables
int tops,topl,topr,bottoml,bottomr,inclined;
int value(int x, int y);

void setup() {  
pinMode(trigPin1, OUTPUT); // Sets the trigPins as Outputs
pinMode(trigPin2, OUTPUT);
pinMode(trigPin3, OUTPUT);
//pinMode(trigPin4, OUTPUT);
pinMode(trigPin5, OUTPUT);
//pinMode(trigPin6, OUTPUT);
pinMode(echoPin1, INPUT); // Sets the echoPins as Inputs
pinMode(echoPin2, INPUT);
pinMode(echoPin3, INPUT);
//pinMode(echoPin4, INPUT);
pinMode(echoPin5, INPUT);
//pinMode(echoPin6, INPUT);
pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT);
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(relay4, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() 
{
  delay(2000);
  tops = value(trigPin1,echoPin1);
  delayMicroseconds(1000);
  topl = value(trigPin2,echoPin2);
  delayMicroseconds(1000);
  topr = value(trigPin3,echoPin3);
  delayMicroseconds(1000);
  //bottoml = value(trigPin4,echoPin4);
  delayMicroseconds(1000);
  bottomr = value(trigPin5,echoPin5);
  delayMicroseconds(1000);
  //inclined = value(trigPin6,echoPin6);
  //delayMicroseconds(1000);
  if(tops>100)
  {
    delay(2000);
    digitalWrite(relay1, HIGH); //normal running condition
    digitalWrite(relay2, LOW); 
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, LOW);
    //digitalWrite(out1, LOW);
    //digitalWrite(out2, LOW);
    
    Serial.println("straight");
    Serial.print(tops);
    Serial.println("tops:");
    Serial.print(topl);
    Serial.println("topl:");
    Serial.print(topr);
    Serial.println("topr:");
    Serial.print(bottoml);
    Serial.println("bottoml:");
    Serial.print(bottomr);
    Serial.println("bottomr");
  }
  else if(tops<=100)
  {
    delay(2000);
    if(topl>100)
    {
      delay(2000);
        //digitalWrite(out1, HIGH); // left solenoid is activated
        digitalWrite(relay1, LOW); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("turning left under normal");
         Serial.print(tops);
        Serial.println("tops:");
        Serial.print(topl);
        Serial.println("topl:");
        Serial.print(topr);
        Serial.println("topr:");
        Serial.print(bottoml);
        Serial.println("bottoml:");
        Serial.print(bottomr);
        Serial.println("bottomr");
        delay(2000);
        //digitalWrite(out1, LOW); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("straight after left");
        delay(2000);
        //digitalWrite(out2, HIGH); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, LOW); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("right turn afterv left");
        delay(2000);
        //digitalWrite(out2, LOW); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("straight after r and l");
    }
    if(topr<=100||topl>100||bottoml>30)
    {
        delay(2000);
        //digitalWrite(out1, HIGH); // left solenoid is activated
        digitalWrite(relay1, LOW); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("turning left under right hinderance");
   
        Serial.print(tops);
        Serial.println("tops:");
        Serial.print(topl);
        Serial.println("topl:");
        Serial.print(topr);
        Serial.println("topr:");
        Serial.print(bottoml);
        Serial.println("bottoml:");
        Serial.print(bottomr);
        Serial.println("bottomr");
        delay(2000);
        //digitalWrite(out1, LOW); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("straight after left");
        delay(2000);
        //digitalWrite(out2, HIGH); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, LOW); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("right turn afterv left");
        delay(2000);
        //digitalWrite(out2, LOW); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("straight after r and l");
       
    }
    else if(topl<=100||topr>100||bottomr==0)
    {
        delay(2000);
        //digitalWrite(out2, HIGH); // right solenoid is activated
        digitalWrite(relay3, LOW);// right motor stops
        digitalWrite(relay4, LOW);// overall action leads to right turn
        digitalWrite(relay1, HIGH); // left motor in forward direction
        digitalWrite(relay2, LOW);
        Serial.println("turning right under left hindrance");
        
        Serial.print(tops);
        Serial.println("tops:");
        Serial.print(topl);
        Serial.println("topl:");
        Serial.print(topr);
        Serial.println("topr:");
        Serial.print(bottoml);
        Serial.println("bottoml:");
        Serial.print(bottomr);
        Serial.println("bottomr");
         delay(2000);
        //digitalWrite(out2, LOW); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("straight after right");
        delay(2000);
        //digitalWrite(out1, HIGH); // left solenoid is activated
        digitalWrite(relay1, LOW); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("left after right");
        delay(2000);
        //digitalWrite(out1, LOW); // left solenoid is activated
        digitalWrite(relay1, HIGH); // left motor stops
        digitalWrite(relay2, LOW); // overall action leads to left turn
        digitalWrite(relay3, HIGH); //right motor in forward direction
        digitalWrite(relay4, LOW);
        Serial.println("straight after l and r");

    }

    else if(topr<100&&topl<100) 
    {
      delay(2000);  
        digitalWrite(relay1, LOW);  // both motors stop 
         digitalWrite(relay2, LOW); // break 
        digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);   
      Serial.print("stop");
      delay(2000);
    }
  }   
}
int value(int x, int y)
{
long duration,d;  
// Clears the trigPin
digitalWrite(x, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(x, HIGH);
delayMicroseconds(10);
digitalWrite(x, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(y, HIGH);
// Calculating the distance
d = (duration*0.034)/2;
return d;
}


