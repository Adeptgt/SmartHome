/**
 * Работа с кнопками
 * Copyright (C) 2016 Alexey Shikharbeev
 * http://samopal.pro
*/
#include "sav_button.h"
SButton button1(4,50,400,800,400);
SButton button2(3,50,400,800,400);

void setup()
{
   Serial.begin(115200);
   Serial.println("Test smart button ...");
    
// Инициация кнопок 
   button1.begin();
   button2.begin();
}

void loop(){
   switch( button1.Loop() ){
     case SB_PUSH:
         Serial.println("SB_PUSH 1");
         break;
      case SB_CLICK:
         Serial.println("SB_CLICKn 1");
         break;
      case SB_RELEASE: 
         Serial.println("SB_RELEASE 1"); 
         break;
      case SB_LONG_CLICK:
         Serial.println("SB_LONG_CLICK 1");
         break;
      case SB_AUTO_CLICK:
         Serial.println("SB_AUTO_CLICK 1");
         break;       
   }
   switch( button2.Loop() ){
     case SB_PUSH:
         Serial.println("SB_PUSH 2");
         break;
      case SB_CLICK:
         Serial.println("SB_CLICK 2");
         break;
      case SB_RELEASE: 
         Serial.println("SB_RELEASE 2"); 
         break;
      case SB_LONG_CLICK:
         Serial.println("SB_LONG_CLICK 2");
         break;
      case SB_AUTO_CLICK:
         Serial.println("SB_AUTO_CLICK 2");
         break;       
   }


  
}