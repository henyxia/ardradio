#include <LiquidCrystal.h>

LiquidCrystal lcd(31, 30, 26, 27, 28, 29);
int volume;

void updateScreen()
{
}

void setup()
{
  analogWrite(2, 120);
  analogWrite(3, 120);
  analogWrite(4, 20);
  analogWrite(5, 50);
  analogWrite(9, 50);
  analogWrite(10, 50);
  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("123456789ABCDEFG");
  lcd.setCursor(0, 1);
  lcd.print("INPUT 1  VOL 000");
}

void loop()
{
  // Volume printing
  lcd.setCursor(13, 1);
  if((volume/100) >= 1)
    lcd.print(volume);
  else if((volume/10) >= 1)
  {
    lcd.print(" ");
    lcd.print(volume);
  }
  else
  {
    lcd.print("  ");
    lcd.print(volume);
  }
  delay(200);
  volume++;
  if(volume == 150)
  {
    volume = 0;
  }
  //digitalWrite(2, HIGH);
  //delayMicroseconds(200); // Approximately 10% duty cycle @ 1KH
  //digitalWrite(2, LOW);
  //delayMicroseconds(100);
  
  
}




