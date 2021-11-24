#include <Arduino.h>

// serial include
#include <Wire.h> 
// monik include
#include <LiquidCrystal_I2C.h>
// maxon include
#include "LedControl.h"
// membrana include
#include <Keypad.h>
// pult include
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

// cristalik
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
// maxon4ik
LedControl lc = LedControl(10,8,9,1);
// membranka
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
{'1','2','3', 'A'},
{'4','5','6', 'B'},
{'7','8','9', 'C'},
{'*','0','#', 'D'}
};
byte rowPins[ROWS] = {23, 25, 27, 29}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {31, 33, 35, 37}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);

  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");

  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  /* keypad get key */
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}