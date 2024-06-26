
int led[6] = {8,9,10,11,12,13};

void setup() {
  // put your setup code here, to run once:
  /*pinMode(led_13, OUTPUT);
  pinMode(led_12, OUTPUT);
  pinMode(led_11, OUTPUT);
  pinMode(led_10, OUTPUT);
  pinMode(led_9, OUTPUT);
  pinMode(led_8, OUTPUT);*/

  for(int i=0; i<6; i++){
    pinMode(led[i], OUTPUT);
  }
  
}
void loop() {
  for (int i=0;i<64;i++){
    if((i%2)>0)
      digitalWrite(led[0],HIGH);
    else
      digitalWrite(led[0],LOW);
    if((i%4)>1)
      digitalWrite(led[1],HIGH);
    else
      digitalWrite(led[1],LOW);
    if((i%8)>3)
      digitalWrite(led[2],HIGH);
    else
      digitalWrite(led[2],LOW);
    if((i%16)>7)
      digitalWrite(led[3],HIGH);
    else
      digitalWrite(led[3],LOW);
    if((i%32)>15)
      digitalWrite(led[4],HIGH);
    else
      digitalWrite(led[4],LOW);
    if((i%64)>31)
      digitalWrite(led[5],HIGH);
    else
      digitalWrite(led[5],LOW);
  delay(200);
  }
  }
