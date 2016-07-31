//Jeremy Blum's Arduino Tutorial Series - Episode 13 - LCDs
//Sample Code - LCD Progress Bar
//http://www.jeremyblum.com
//LiquidCrystal library by David A. Mellis, Limor Fried (http://www.ladyada.net), and Tom Igoe
//http://www.arduino.cc/en/Tutorial/LiquidCrystal

/* 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor: potiometer
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>
#define RS 12
#define EN 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Divyaksh");
}

void loop() {

  lcd.setCursor(0,1);
  LCDtimeHHMMSS();
  
}

void LCDtimeHHMMSS()
{
  long int hour = millis()/3600000;
  long int mins = (millis()/60000)-(hour*60);
  long int secs = (millis()/1000)-(mins*60)-(hour*3600);
  if(secs == 0)
  {
    lcd.setCursor(5,1);
    lcd.print("    ");
  }
  lcd.setCursor(0,1);
  lcd.print(hour);
  lcd.print(":");
  lcd.print(mins);
  lcd.print(":");
  lcd.print(secs);
  return;
}

