/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
#define led 2
#define r 3
#define g 4
#define b 5
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 8; 
// defines pins numbers
const int trigPin = 22;
const int echoPin = 24;
Servo Servo1; 
long duration;
int distance;
void setup() {
  Servo1.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(led,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  float bal=map(distance,0,500,0,180);
  //Servo1.write(distance);
  analogWrite(led,bal);
  // if(distance<25)
  // {
  //   setColor(255,255,255);
  //   Servo1.write(distance); 
  // }
  // else
  // {
  //   setColor(0,0,0);
  //   Servo1.write(0); 
 // }
  Serial.print("Distance: ");
  Serial.println(distance);
}
void setColor(int x,int y,int z)
{
  analogWrite(r,x);
  analogWrite(g,y);
  analogWrite(b,z);
}