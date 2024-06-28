// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  //digitalWrite(4, LOW);

}

void loop()
{  float cm=0;
 digitalWrite(4,HIGH);//send sound pulse 
 delayMicroseconds(10);//wait 10 Microseconds
 digitalWrite(4,LOW);//receive sound pulse  
 float value = pulseIn(3, HIGH, 50000);//take the pulse sound 
Serial.print(value);
  cm=value/58;
  digitalWrite(13,HIGH);
  delay(cm*5);
  digitalWrite(13,LOW);
  delay(cm*5);
  Serial.print(" cm is equal = ");
  Serial.println(cm);
  delay(50);
}
