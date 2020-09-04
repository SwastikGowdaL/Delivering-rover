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
char auth[] = "SkpVn6P1cAD2aEho9ElHcGYB1aAp59Ng";

// Your WiFi credentials
char ssid[] = "latest";
char pass[] = "123456789";        // Set to "" for open networks
int x=0, y=0,s=10;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(28,OUTPUT);
 pinMode(29,OUTPUT);
 pinMode(39,OUTPUT);
 pinMode(40,OUTPUT);
 pinMode(RED_LED, OUTPUT);
 while(WiFi.status()!=WL_CONNECTED) {
   digitalWrite(RED_LED, HIGH);
   delay(100);
   digitalWrite(RED_LED, LOW);
   delay(100);
   Serial.print(".");
 }
 
  // Or specify server using one of those commands:
  //Blynk.begin(auth, ssid, pass, "server.org", 8442);
  //Blynk.begin(auth, ssid, pass, server_ip, port);
}
/*BLYNK_WRITE(V2)
{
 x=param.asInt()-128;
 
 
 if(x>0) {
   digitalWrite(28,1);
   digitalWrite(29,0);
   analogWrite(39,x/5);
   analogWrite(40,x/5);
 }
 else if(x<0) {
   digitalWrite(28,0);
   digitalWrite(29,1);
   analogWrite(39,(x/5)*-1);
   analogWrite(40,(x/5)*-1);
 }
 if(x==0) {
   analogWrite(39,0);
   analogWrite(40,0);
 }
 
}
BLYNK_WRITE(V3)
{
 y=param.asInt()-128;
 if(y<0) {
   digitalWrite(28,1);
   digitalWrite(29,1);
   analogWrite(39,(y/2)*-1);
   analogWrite(40,(y/2)*-1);
 }
 else if(y>0){
   digitalWrite(28,0);
   digitalWrite(29,0);
   analogWrite(39,y/2);
   analogWrite(40,y/2);
 }
 if(y==0) {
   analogWrite(39,0);
   analogWrite(40,0);
 }
 
}*/
BLYNK_WRITE(V0)
{
 x=param[0].asInt();
 
 y=param[1].asInt();
 if(x<0) {
   digitalWrite(28,1);
   digitalWrite(29,0);
   analogWrite(39,x*-10);
   analogWrite(40,x*-10);
 }
 else if(x>0) {
   digitalWrite(28,0);
   digitalWrite(29,1);
   analogWrite(39,x*10);
   analogWrite(40,x*10);
 }
 if(y>0) {
   digitalWrite(28,1);
   digitalWrite(29,1);
   analogWrite(39,-1*s);
   analogWrite(40,-1*s);
 }
 else if(y<0){
   digitalWrite(28,0);
   digitalWrite(29,0);
   analogWrite(39,s);
   analogWrite(40,s);
 }
 if(x==0&&y==0) {
   analogWrite(39,0);
   analogWrite(40,0);
 }
}
BLYNK_WRITE(V1)
{
 s=param.asInt();
}
void loop()
{
  Blynk.run();
  
}

