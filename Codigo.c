#include <LiquidCrystal.h> 
#include <Servo.h>

void UpDown();
void LeftRight();
Servo servo1;
Servo servo2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  
  lcd.begin(16,2); 
  lcd.print("Servo1 "); 
  lcd.setCursor(0,1);
  servo1.attach(9);
  servo1.write(90); 
}

void loop(){
  
 int sensorTop = analogRead(A0);
 int sensorBottom = analogRead(A1);
 int sensorLeft = analogRead(A3);
 int sensorRight = analogRead(A4);

 int avgT=(sensorTop+sensorBottom)/2;
 int avgB=(sensorLeft+sensorRight)/2;
 int avgL=(sensorTop+sensorLeft)/2;
 int avgR=(sensorBottom+sensorRight)/2;


  if (avgT > avgB)
  {
  	 UpDown(sensorTop, sensorBottom);
  }
  if(avgT < avgB)
  {
    UpDown(sensorBottom, sensorTop);
  }
  if(avgL > avgR) 
 	{
 	 LeftRight(sensorLeft, sensorRight);
    }
  if(avgL < avgR) 
 	{
 	 LeftRight(sensorRight, sensorLeft);
    }
 delay(10); 
}
void UpDown(int avgT, int avgB){
  int pos1= servo1.read();
    
  if(avgT < avgB){
     pos1 = --pos1; 
    }
  	 else
     {
      pos1 = ++pos1;
     }
  servo1.write(pos1);
   lcd.setCursor(12,0);
 lcd.print(pos1);
 }
void LeftRight(int avgL, int avgR){
  int pos2= servo2.read();
  if(avgL < avgR)
   { 
    pos2 = --pos2;
   }
  	else
    {
     pos2 = pos2 + 1;
    }
  servo2.write(pos2);
  lcd.setCursor(12,1);
}
