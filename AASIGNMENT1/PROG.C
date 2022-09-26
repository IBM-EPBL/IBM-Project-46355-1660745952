#include<Servo.h>
const int PPin = 7;
int servo_Pin = 8;

Servo servo1;

void setup() {
  // initialize serial communication by setting corresponding pins as inputs and outputs:
  Serial.begin(9600);
  servo1.attach(servo_Pin);
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  digitalWrite(2,LOW);
  digitalWrite(11,HIGH);
  
}

void loop() {
  
  long duration, inches, cm;

  pinMode(PPin, OUTPUT);
  digitalWrite(PPin, LOW);
  delayMicroseconds(2);
  digitalWrite(PPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(PPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(PPin, INPUT);
  duration = pulseIn(PPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();
  //delay(100);
  
  servo1.write(0);
  
  if(cm < 40)
  {
    servo1.write(90);
    delay(2000);
  }
  else
  {
    servo1.write(0);
  }
  
  // PIR with LED starts
  int pir = digitalRead(2);
  
  if(pir == HIGH)
  {
    digitalWrite(4,HIGH);
    delay(1000);
  }
  else if(pir == LOW)
  {
    digitalWrite(4,LOW);
  }
  
}
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}