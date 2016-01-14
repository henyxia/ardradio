#include <avr/io.h>
#include <util/delay.h>

typedef struct
{
	uint8_t	pRS;
	uint8_t	pEn;
	uint8_t	pDB7;
	uint8_t	pDB6;
	uint8_t	pDB5;
	uint8_t	pDB4;
	//uint8_t (*begin)(uint8_t a, uint8_t);
} ScreenLCD;

void screenLCD_init(
		ScreenLCD* lcd,
		uint8_t gRegisterSelection,
		uint8_t gEnabled,
		uint8_t gdb7,
		uint8_t gdb6,
		uint8_t gdb5,
		uint8_t gdb4)
{
	// Port selection
	lcd->pRS = gRegisterSelection;
	lcd->pEn = gEnabled;
	lcd->pDB7 = gdb7;
	lcd->pDB6 = gdb6;
	lcd->pDB5 = gdb5;
	lcd->pDB4 = gdb4;

	// LCD Screen connected to PORTC
	// RS	D35		PC2
	// EN	D34		PC3
	// DB7	D33		PC4
	// DB6	D32		PC5
	// DB5	D31		PC6
	// DB4	D30		PC7

	// Setting DL
	PORTC &= 0b11111011;	// RS
	_delay_us(1);			// Tsu1 100ns
	PORTC &= 0b11111101;	// Enable

	return;
}

void screenLCD_clear(
		ScreenLCD* lcd)
{
	//screenLCD_prepare(lcd);
	//lcd->pdb7 = 
	return;
}

//LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int volume;

void updateScreen()
{
}

void setup()
{
	ScreenLCD lcd;
	screenLCD_init(&lcd, 7, 8, 9, 10, 11, 12);
	screenLCD_clear(&lcd);
	//lcd.begin(16, 2);
	//lcd.setCursor(0, 0);
	//lcd.print("123456789ABCDEFG");
	//lcd.setCursor(0, 1);
	//lcd.print("INPUT 1  VOL 000");
}

void loop()
{
	/*
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
  */
}

int main(void)
{
	setup();
	loop();
	return 0;
}
