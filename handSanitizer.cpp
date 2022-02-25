//Hand Sanitizer

//GLobal Variables
#include <Servo.h>
#define pinServo 2

Servo s1;
int degree = 0;
long centimeter = 0;

//Checks how far this object is
long readUltraSonicDistance(int triggerPin, int echoPin){
  
  pinMode(triggerPin, OUTPUT);
  
  digitalWrite(triggerPin, LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  
  delayMicroseconds(10);
  
  digitalWrite(triggerPin, LOW);
  
  pinMode(echoPin, INPUT);
  
  //Created a pulse signal
  return (pulseIn(echoPin,HIGH)*0.01723);
  
}

void setup()
{
  //Set up for objects
  s1.attach(pinServo);
  Serial.begin(9600);
  s1.write(0);
  delay(2000);
  pinMode(2,OUTPUT);
  
 
 
}

void loop()
{
  centimeter = readUltraSonicDistance(5,4);
  Serial.print(centimeter);
  Serial.println("Cm");
  
  if (centimeter>180){
    digitalWrite(2,LOW);
    s1.write(0);
    
  }
  if (centimeter<180){
    digitalWrite(2,HIGH);
    s1.write(60);
    delay(500);
    s1.write(0);
    delay(3000);
    
  }
  delay(100);
}
