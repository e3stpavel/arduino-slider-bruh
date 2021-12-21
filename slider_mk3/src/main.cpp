#include <Arduino.h>

/* for serial monitor */
#include <Wire.h> 
/* for liquid crystal i2c module */
#include <LiquidCrystal_I2C.h>
/* for ultrasonic sensors */
#include <NewPing.h>
/* for keyboard */
#include <Keypad.h>
/* for MAX led module */
#include "LedControl.h"
/* for remote controller */
#include "helpers/PinDefinitionsAndMore.h"
#include <IRremote.hpp>

/* multithreading sorta */
#include <Chrono.h>

// # liquid crystal init
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// # ultrasonic sensors init
#define SONAR_NUM 2      // Number of sensors
#define MAX_DISTANCE 250 // Maximum distance (in cm) to ping

// Sensor object array
// Each sensor's trigger pin, echo pin, and max distance to ping
NewPing sonar[SONAR_NUM] = {  
  // esr 
  NewPing(39, 41, MAX_DISTANCE),  
  // esl
  NewPing(43, 45, MAX_DISTANCE)
};

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

// # MAX led init
#define DATA_PIN 10
#define CLK 8
#define CS 9
LedControl lc = LedControl(DATA_PIN, CLK, CS, 1);

// # global state declaration
String GLOBAL_STATE = "";

//// # global functions declaration goes here
#include <funcs/on_remote_click.h>
#include <funcs/on_keypad_tap.h>
#include <funcs/get_ultrasonic_distance.h>

// maxon support
#include <helpers/MaxRows.h>
#include "helpers/MaxSetters.h"

//// # tasks base structure goes here, should fit for everyone
#include <structure.h>

//// # tasks functions should be here
// #include <tasks/task1.h>
#include <tasks/task2.h>
// #include <tasks/task3.h>
// ... etc

void setup()
{
  // put your setup code here, to run once:

  // # initialize the lcd 
  lcd.init();                      
  lcd.backlight();

  // # initialize the max led
  // wakeup
  lc.shutdown(0, false);
  // set the brightness to a medium values
  lc.setIntensity(0,8);
  // clear the display
  lc.clearDisplay(0);

  // # initialize the remote controller
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
  Serial.println(IR_RECEIVE_PIN);

  // # begin serial monitor
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:

  /*on_keypad_tap();

  if (IrReceiver.decode())
  {
    on_remote_click();
  }*/

  delay(500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Choose us");
  delay(1000);

  char key = on_keypad_tap();
  if(key == '2') {
    rows();
    /*tsk br = edge_to_edge(0.0f);
    Serial.println(br.status);*/
  }
  
}
