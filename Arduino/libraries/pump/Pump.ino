/** 
 *Управление насосом
*/
#include "Pump.h"

Pump pump1(7,20000,10000);
int state=0;
unsigned int checkint=1000;
unsigned long checktime;
unsigned long timeout=60000;
unsigned long wtime=0;

void setup()
{
 Serial.begin(9600);
 Serial.println("Test pump ...");
 pump1.begin();
}

void loop()
{  
   

  if(millis()-wtime>timeout)
  { 
    
    if(pump1.status()>0){pump1.stop(); 
    Serial.print(wtime); 
    Serial.println(" send comand Pump stop"); 
    } 
    else {pump1.start(); Serial.print(wtime); Serial.println(" send comand  Pump start");}
    wtime=millis();
  }
  if(millis()-checktime>checkint)
  { pump1.Loop();
    Serial.print("Status: ");
    Serial.println(pump1.status());
    Serial.print("time left: ");
    Serial.println(millis()-wtime);
    Serial.print(" for timeout: ");
    Serial.println(timeout-(millis()-wtime));
    checktime=millis();
  }

}