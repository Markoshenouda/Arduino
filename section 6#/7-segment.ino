                             //example 1
/*const int segmentPins[8] = {2,3,4,6,7,8,9,5}; //A,B,C,D,E,F,G,dp

void setup(){
  for(int i = 0; i<8 ; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop(){
  for(int i=0; i<8; i++){
    digitalWrite(segmentPins[i], HIGH);
    delay(1000);
    digitalWrite(segmentPins[i], LOW);
  }
}*/
                                  //example2 
/*
const int segmentPins[8] = {2,3,4,6,7,8,9,5}; //A,B,C,D,E,F,G,dp
const byte numeral[10][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {0,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,0,0,1,1,0}  // 9
};
 //A,B,C,D,E,F,G,dp    

void setup(){
  for(int i = 0; i<8 ; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop(){
  for(int number = 0; number<10; number++){
    for(int segment = 0; segment < 8; segment++){
      int isBitSet = numeral[number][segment]; // for common Cathode
      //int isBitSet = !numeral[number][segment]; // for common Anode
      digitalWrite(segmentPins[segment], isBitSet);
    }
    delay(1000);
  }
}*/
                                  //example3
const int segmentPins[8] = {2,3,4,6,7,8,9,5};
                          //A,B,C,D,E,F,G,dp
                          //0,1,2,3,4,5,6,7
const int loading[8] = {0,1,6,4,3,2,6,5};
                      //A,B,G,E,D,C,G,F
                          
void setup(){
  for(int i = 0; i<8; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop(){
  for(int i=0; i<8; i++){
    for(int segment=0; segment<8; segment++){
      bool isBitSet = loading[i]==segment;
      //isBitSet = !isBitSet; //for common Anode
      digitalWrite(segmentPins[segment], isBitSet);
    }
    delay(200);
  }
}
