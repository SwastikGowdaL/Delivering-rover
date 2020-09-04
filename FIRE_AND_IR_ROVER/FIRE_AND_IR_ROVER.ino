
// Comment this out to disable prints and save space
#include <SPI.h>

int a=2,b,c=5,d;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

void setup()
{
pinMode(30,OUTPUT);
 pinMode(29,OUTPUT);
 pinMode(39,OUTPUT);
 pinMode(40,OUTPUT);
Serial.begin(9600); 


}
void loop()
{
  // put your main code here, to run repeatedly:
  b=analogRead(a);
  d=analogRead(c); 
 

 while(b<=200||d<=200)
 {
   
   digitalWrite(29,1);
  digitalWrite(30,1);
 analogWrite(40,50);
 analogWrite(39,50);
 delay(500);
 digitalWrite(29,1);
  digitalWrite(30,0);
 analogWrite(40,50);
 analogWrite(39,50);
 delay(750);
 b=analogRead(a);  
  d=analogRead(c);

}

  digitalWrite(29,0);
  digitalWrite(30,0);
 analogWrite(40,50);
 analogWrite(39,50);
delay(500);
}
