#include<LiquidCrystal.h>
byte happy[8]{
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000};
byte sad[8]{
  B00000,
  B01010,
  B00000,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000};
int seconds = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //RS, E, D4, D5, D6, D7

void setup(){
  lcd.begin(16,2);//number of Columns, number of Rows
  lcd.createChar(0,happy);
  lcd.createChar(1,sad);

}

void loop(){
  lcd.setCursor(0,0);//col, row
  for (int m=0;m<2;m++){ lcd.setCursor(0,0);//col, row
  for (int j=0;j<16;j++){ lcd.setCursor(j,m);//col, row
  for(int i=0;i<2;i++){ 
  lcd.write(i);
    delay(100);}}}
  for (int m=1;m>=0;m--){ lcd.setCursor(0,0);//col, row
  for (int j=15;j>=0;j--){ lcd.setCursor(j,m);//col, row 
  lcd.write(1);
    delay(100);}}
  lcd.clear();
}
