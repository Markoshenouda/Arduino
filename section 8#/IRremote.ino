// C++ code
//
#include <IRremote.h>
const int IRr=2;
int i;
 unsigned long BUTTON[25]={
4077698816,
4010852096,
3994140416,
3977428736,
3944005376,
3927293696,
3910582016,
3877158656,
3860446976,
3843735296,
4278238976,
4261527296,
4244815616,
4211392256,
4194680576,
4177968896,
4144545536,//down4144545536
4127833856,//vol-4177968896
4111122176,//up
4060987136,//EQ
4044275456,//rept
};
String BUTTONN[25]={"0","1","2","3","4",
                    "5","6","7","8","9",
                  "pow","vol+","stop",
                   "prev", ">||","next","down","vol-",
                  "up","EQ","ST/rept"};
void setup()
{
  IrReceiver.begin(IRr,ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
}

void loop()
{
  if (IrReceiver.decode()){
//Serial.println(IrReceiver.decodedIRData.decodedRawData);
 int button_id=findButton(IrReceiver.decodedIRData.decodedRawData);
    if(button_id < 0){
      Serial.println("Unknown button is pressed!");
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
    }else{
      Serial.print("Button ");
      Serial.print(BUTTONN[button_id]);
      Serial.println(" is pressed");
    }
    delay(200);
    IrReceiver.resume(); //watch out for another message
  }
}
int findButton( unsigned long val){
  for( i=0;i<21;i++){
    if (val==BUTTON[i])
      return i;}
  return -1;
}
