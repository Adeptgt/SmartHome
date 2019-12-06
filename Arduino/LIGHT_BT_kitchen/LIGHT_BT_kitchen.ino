#include "sav_button.h"
SButton  lbut1(2,100,0,0,0);
int light1=4;
int light2=5;
int light3=6;
int light4=6;
int light5=11;
int lstatus1=0;
int lstatus2=0;
int lstatus3=0;
int lstatus4=0;
int lstatus5=0;
void setup() {
  // put your setup code here, to run once:
   lbut1.begin();
   pinMode(light1, OUTPUT); // Основной свет
   pinMode(light2, OUTPUT); // Остров светильник 1
   pinMode(light3, OUTPUT); // Остров светильник 2
   pinMode(light4, OUTPUT); // Остров светильник 3
   pinMode(light5, OUTPUT); // Карнизная подсветка ШИМ
   
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
  // put your main code here, to run repeatedly:
switch( lbut1.Loop() ){
  
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         lstatus1=0;
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         lstatus1=1;
         break;
   }

switch (lstatus1)
{
 case 0:
    digitalWrite(light1,LOW);
    break;
 case 1:
    digitalWrite(light1,HIGH);
    break;
                 
}


  

}
