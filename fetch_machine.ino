const int photoresistor = A0;
int photovalue;
#include <Servo.h>  // servo library
Servo servo1;  // servo control object
int servoPIN = 9;
int servoPWR = 12;
int openVal = 180;
int closeVal  =130;
void setup() {
  Serial.begin(9600);
  pinMode(photoresistor, INPUT); 
  servo1.attach(servoPIN, 900, 2100);  //Connect the servo to pin 9
                //with a minimum pulse width of
                //900 and a maximum pulse width of
                //2100. 
  digitalWrite(servoPWR, HIGH); 
  servo1.write(closeVal);  
  }
  
boolean turned = false;
void loop() {
   photovalue = analogRead(photoresistor);
   Serial.println(photovalue);

  
   if (turned){
    if (photovalue>400){
      turned = false;
        closeTube();
        delay(500);         // Pause to get it time to move

    }
   }

   if (!turned) {
    if (photovalue < 300){
      turned = true;
      delay(2000);         // Pause to get it time to move
      openTube();
      delay(2000);         // Pause to get it time to move
      
    }
   }
}

//180 is open
//130 is closed
int delayInClosing = 5;
void openTube(){
  for (int i=closeVal; i< openVal; i++){
    servo1.write(i);
    delay(delayInClosing);
  }
}

void closeTube(){
  for (int i=openVal; i>closeVal; i--){
    servo1.write(i);
    delay(delayInClosing);
  }
}


  

