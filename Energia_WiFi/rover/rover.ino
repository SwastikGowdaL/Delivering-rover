int trigPin = 9;
int echoPin = 10;
long duration;
int distanceCm, distanceInch;
void setup()
{
  // put your setup code here, to run once:
 pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(30,OUTPUT);
 pinMode(29,OUTPUT);
 pinMode(39,OUTPUT);
 pinMode(40,OUTPUT);
Serial.begin(9600); 
}

void loop()
{
   digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
  // put your main code here, to run repeatedly:
  while(distanceCm>15)
  {
   digitalWrite(29,1);
  digitalWrite(30,1);
 analogWrite(40,100);
 analogWrite(39,100);
 delay(500); 
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
delay(500);
  }
 digitalWrite(29,0);
  digitalWrite(30,1);
 analogWrite(40,100);
 analogWrite(39,100);
 delay(500);
}
