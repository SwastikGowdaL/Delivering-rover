 // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
int trigPin = 2;
int echoPin = 3;
long duration;
int distanceCm, distanceInch;
void setup()
{
  // put your setup code here, to run once:
  pinMode(30,OUTPUT);
 pinMode(29,OUTPUT);
 pinMode(39,OUTPUT);
 pinMode(40,OUTPUT);
 pinMode(31,OUTPUT);
 pinMode(11,OUTPUT);
 digitalWrite(40,HIGH);
 digitalWrite(11, HIGH);
  // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

void loop(){


digitalWrite(29,1);
  digitalWrite(30,1);
 analogWrite(40,100);
 analogWrite(39,100);
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
if(distanceCm<=10)
{
 digitalWrite(29,0);
  digitalWrite(30,0);
 analogWrite(40,0);
 analogWrite(39,0);
 delay(500);
}
 delay(1000);
}
