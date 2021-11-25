#include <Arduino.h>

/* for keyboard */
#include <Keypad.h>

// # keypad init
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
//connect to the row pinouts of the keypad
byte rowPins[ROWS] = {23, 25, 27, 29};
//connect to the column pinouts of the keypad
byte colPins[COLS] = {31, 33, 35, 37};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void on_tap()
{
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}