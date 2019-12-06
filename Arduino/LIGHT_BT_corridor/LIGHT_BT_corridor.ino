#include "sav_button.h"
SButton  lbut1(2,100,500,1000,500);
int light1=4;
int light2=5;
int light3=6;
int lstatus=0;
int ldirection=1; 
void setup() {
  // put your setup code here, to run once:
   lbut1.begin();
   pinMode(light1, OUTPUT);
   pinMode(light2, OUTPUT);
   pinMode(light3, OUTPUT);

   
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
  // put your main code here, to run repeatedly:
switch( lbut1.Loop() ){
      case SB_AUTO_CLICK:
      Serial.println("BUTTON 1 SB_AUTO_CLICK");
      if(ldirection==0 && lstatus>0){lstatus--;}
      else if(ldirection==1 && lstatus<3){lstatus++;}
      break;
      case SB_LONG_CLICK:
         Serial.println("BUTTON 1 SB_LONG_CLICK");
         if(ldirection==0 && lstatus>0){lstatus--;}
         else if(ldirection==1 && lstatus<3){lstatus++;}
         break;
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         //digitalWrite(light1,LOW);
         // digitalWrite(light2,LOW);
         // digitalWrite(light3,LOW);
         if(ldirection==0){ldirection=1;}
         else if(ldirection==1){ldirection=0;}
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         if(lstatus==0){lstatus=3; ldirection=0;}
         else {lstatus=0; ldirection=1;}
         //digitalWrite(light1,HIGH);
         // digitalWrite(light2,HIGH);
         //digitalWrite(light3,HIGH);
         break;  
   }

switch (lstatus)
{
 case 0:
    digitalWrite(light1,LOW);
    digitalWrite(light2,LOW);
    digitalWrite(light3,LOW);
    break;
 case 1:
    digitalWrite(light1,HIGH);
    digitalWrite(light2,LOW);
    digitalWrite(light3,LOW);
    break;
 case 2:
    digitalWrite(light1,HIGH);
    digitalWrite(light2,HIGH);
    digitalWrite(light3,LOW);
    break;
 case 3:
    digitalWrite(light1,HIGH);
    digitalWrite(light2,HIGH);
    digitalWrite(light3,HIGH);
    break;                   
}


  

}
