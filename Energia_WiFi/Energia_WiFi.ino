/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example shows how to use Arduino WiFi shield
 * to connect your project to Blynk.
 *
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi.h>
#include <BlynkSimpleEnergiaWiFi.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "RIaLl6QizWhfRlofXQkW2_8Ou4bCEIJg";

// Your WiFi credentials
char ssid[] = "JioFi_209F51E";
char pass[] = "9tgrxyv4dt";        // Set to "" for open networks
int pin = A11;

int value = 0;
int pirState = LOW;
/*const int trigPin = 2;
const int echoPin = 3;
long duration;
float distanceCm, distanceInch;*/
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(GREEN_LED,OUTPUT);
 pinMode(RED_LED,OUTPUT);
 pinMode(BLUE_LED,OUTPUT);
 pinMode(pin,INPUT);
 /*pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);*/
  // Or specify server using one of those commands:
  //Blynk.begin(auth, ssid, pass, "server.org", 8442);
  //Blynk.begin(auth, ssid, pass, server_ip, port);
  
  while(WiFi.status()!=WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(RED_LED,HIGH);
    delay(50);
    digitalWrite(RED_LED,LOW);
    delay(50);
    
  }
  Serial.println("\n You're now connected:)");
  digitalWrite(GREEN_LED,HIGH);
  delay(1000);
  digitalWrite(GREEN_LED,LOW);
}
/*BLYNK_WRITE(V0)
{
 int a=param.asInt();
 analogWrite(GREEN_LED,a);
}*/
BLYNK_WRITE(V1)                                         
{
 int b=param.asInt();
 analogWrite(RED_LED,b);
 

}

/*BLYNK_WRITE(V2)
{
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println(distanceCm);
Serial.println(distanceInch);

Blynk.virtualWrite(V3,distanceCm);
Blynk.virtualWrite(V4,distanceInch);
delay(1000); 
}
*/
void loop()
{

/* if(k<=250)
 {
  Serial.println(k);
 Blynk.run();
   Blynk.notify("FIRE DETECTED");
 
  delay(1000);
 }
else
{*/
value = analogRead(pin);


  Serial.println(value);
 Blynk.run(); 
 delay(1000);
}

