// C++ code
//
#include <Servo.h>
Servo myservo;  
const int pmw_motor_1=11;
const int in_motor_1=10;
const int pmw_motor_2=6;
const int in_motor_2=7;
const int trigPin = A0;
const int echoPin = 5;
long value = 0;
int cm = 0;
int motorSpeed=150;

void setup()
{ myservo.attach(3);
  Serial.begin(9600);
  pinMode(pmw_motor_1, OUTPUT);
  pinMode(in_motor_1, OUTPUT);
  pinMode(pmw_motor_2, OUTPUT);
  pinMode(in_motor_2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
;
}

void loop()
{  getdistance();
    if(cm<20 && cm>0){
    stopMovement();
    moveBackward(motorSpeed);
    delay(1000);
    turnRight(motorSpeed);
     getdistance();
      if(cm<20 && cm>0)
        turnLift(motorSpeed*2);
    delay(400);  }
 else{
      moveForward(motorSpeed); }
}
 void moveForward(int motorSpeed){
  analogWrite(pmw_motor_1, motorSpeed);
  digitalWrite(in_motor_1, 0);
  analogWrite(pmw_motor_2, motorSpeed);
  digitalWrite(in_motor_2, 0);}

void turnRight(int motorSpeed){
  analogWrite(pmw_motor_1, motorSpeed);
  digitalWrite(in_motor_1, 0);
  analogWrite(pmw_motor_2, motorSpeed*-1);
   digitalWrite(in_motor_2, 1);
  delay(1500);}

void turnLift(int motorSpeed){
  analogWrite(pmw_motor_1, motorSpeed*-1);
  digitalWrite(in_motor_1, 1);
  analogWrite(pmw_motor_2, motorSpeed);
   digitalWrite(in_motor_2, 0);
delay(1500);}

 void stopMovement(){
   
  analogWrite(pmw_motor_1, 0);
  digitalWrite(in_motor_1, 0);
  analogWrite(pmw_motor_2, 0);
   digitalWrite(in_motor_2, 0);}

void moveBackward(int motorSpeed){
  analogWrite(pmw_motor_1, motorSpeed);
  digitalWrite(in_motor_1, 1);
  analogWrite(pmw_motor_2, motorSpeed);
   digitalWrite(in_motor_2, 1);
delay(1500);}

void getdistance(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  value = pulseIn(echoPin, HIGH, 50000);
  cm = value / 58;
  Serial.print(value);
  Serial.print(" ; ");
  Serial.println(cm);
}
