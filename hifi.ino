#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int volume;

void updateScreen()
{
}

void setup()
{
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
}
