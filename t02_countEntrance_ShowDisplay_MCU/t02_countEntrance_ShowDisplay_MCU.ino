#include "HD44780_LCD_PCF8574.h"
HD44780LCD myLCD( 2, 16, 0x27);

int sensor1 = 2;
int sensor2 = 3;
int inputValue1 = 1;
int inputValue2 = 1;
int checkShowValue1 = 1;
int checkShowValue2 = 1;
int count = 20;

void setup() {
  delay(50);
  myLCD.PCF8574_LCDInit(LCDCursorTypeOn);
  myLCD.PCF8574_LCDClearScreen();
  myLCD.PCF8574_LCDBackLightSet(true);
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  Serial.println(count);
}

void loop() {
  inputValue1 = digitalRead(sensor1);
  inputValue2 = digitalRead(sensor2);
  myLCD.PCF8574_LCDGOTO(LCDLineNumberOne, 0);

  if (inputValue1 != checkShowValue1) {
    checkShowValue1 = inputValue1;
    if (checkShowValue1 == 0) {
      count--;
      Serial.println(count);
      myLCD.print(count);
    }
  }

  if (inputValue2 != checkShowValue2) {
    checkShowValue2 = inputValue2;
    if (checkShowValue2 == 0) {
      count++;
      Serial.println(count);
      myLCD.print(count);
    }
  }

}
