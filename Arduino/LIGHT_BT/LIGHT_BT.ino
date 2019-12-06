#include "sav_button.h"
SButton  lbut1(2,100,0,0,0);
SButton  lbut2(3,100,0,0,0);
int light1=4;
int light2=5;
int light3=6;

void setup() {
  // put your setup code here, to run once:
   lbut1.begin();
   lbut2.begin();
   pinMode(light1, OUTPUT);
   pinMode(light2, OUTPUT);
   pinMode(light3, OUTPUT);

   
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
  // put your main code here, to run repeatedly:
switch( lbut1.Loop() ){
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         digitalWrite(light1,LOW);
         digitalWrite(light2,LOW);
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         digitalWrite(light1,HIGH);
         digitalWrite(light2,HIGH);
         break;  
   }
switch( lbut2.Loop() ){
      case SB_RELEASE: 
         Serial.println("BUTTON 2 RELEASE");
         digitalWrite(light3,LOW);
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 2 CLICK");
         digitalWrite(light3,HIGH);
         break;     
       
   }


  

}
