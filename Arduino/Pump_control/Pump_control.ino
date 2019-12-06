#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Pump.h>
#include <sav_button.h>
SButton  HILEV(7,100,0,0,0);
SButton  STPBTN(6,100,0,0,0);
SButton  STRBTN(5,100,0,0,0);
SButton  LOWLEV(4,100,0,0,0);

LiquidCrystal_I2C lcd(0x38,16,2);
int scan_int=300;
unsigned long chtime;
int led=9;
int state=0;
int bstate=0;
//Pump section ################
Pump pump1(8,180000,120000);

//Level section##################
//int HILevel=30;
//int LOWLevel=70.0;
//int Level;
// ########################
void setup () {

  HILEV.begin();
  LOWLEV.begin();
  STPBTN.begin();
  STRBTN.begin();
   pump1.begin();
  pinMode(led, OUTPUT);
  lcd.init(); 
  lcd.clear();                    
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Pump Control");
  lcd.setCursor(0, 1);
  lcd.print("ST:");
  lcd.setCursor(9, 1);
  lcd.print("T:");
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
  digitalWrite(led, LOW);

}

void loop () {
    pump1.Loop();
    if( HILEV.Loop() == SB_CLICK || HILEV.Loop() == SB_PUSH ||  STPBTN.Loop() == SB_CLICK) { Serial.println("Hi level"); pump1.stop();digitalWrite(led, LOW); }
    else if(  (LOWLEV.Loop() == SB_CLICK || STRBTN.Loop() == SB_CLICK) && HILEV.Loop() != SB_PUSH ) {Serial.println("Low level");pump1.start();digitalWrite(led, HIGH);}
    
    if(millis()-chtime>scan_int)
    {     chtime=millis();
      Serial.println(HILEV.Loop());
      
       switch (pump1.status())
        {
         case 0: state=0; if(state!=bstate){bstate=state; lcd.setCursor(4, 1);lcd.print("    ");lcd.setCursor(4, 1);lcd.print("OFF");lcd.setCursor(12, 1);lcd.print("    ");} break;
         case 1: state=1; if(state!=bstate){bstate=state; lcd.setCursor(4, 1);lcd.print("    ");lcd.setCursor(4, 1);lcd.print("ON ");} lcd.setCursor(12, 1);lcd.print(pump1.wtime()); break;
         case 2: state=2; if(state!=bstate){bstate=state; lcd.setCursor(4, 1);lcd.print("    ");lcd.setCursor(4, 1);lcd.print("RST");} lcd.setCursor(12, 1);lcd.print(pump1.wtime()); break;    
        }    
    }    
}
