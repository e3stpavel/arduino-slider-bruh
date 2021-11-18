#include <LiquidCrystal.h> // lcd 16 02   I2C neeeds
#include <Keypad.h> // membrannaja klava

// maxon
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// pult
#include <IRremote.h> 

// Hardware SPI maxon:
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN 9
#define DATA_PIN 10
#define CLK_PIN 8

// bruh pul5t
#define RECEIVER_PIN 47 // define the IR receiver pin

// Create a new instance of the MD_Parola class with hardware SPI connection:
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// lcd connection
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Keypad
const byte ROWS = 4;   // Количество рядов 
const byte COLS = 4;   // Количество строк
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {23, 25, 27, 29}; // Выводы, подключение к строкам
byte colPins[COLS] = {31, 33, 35, 37}; // Выводы, подключение к столбцам

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class
unsigned long key_value = 0; // variable to store the pressed key value

// datchiki levii
const int trigPinL = 43;
const int echoPinL = 45;
/*long durationL;
int distanceL;*/

// datchiki pravii
const int trigPinL = 39;
const int echoPinL = 41;
/*long durationR;
int distanceR;*/

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // Открываем последовательную связь на скорости 9600

  // lcd code
  lcd.begin(16, 2);
  lcd.print("First line");
  lcd.setCursor(0,1);
  lcd.print("Second line");

  myDisplay.begin();
  myDisplay.setIntensity(0);
  myDisplay.displayClear();

  receiver.enableIRIn(); // enable the receiver
  receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received

  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
}

int getDistance(int echoPin, int triggerPin)
{
  long duration;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return (int)(duration/2) / 29.1;
}

void loop() {
  // put your main code here, to run repeatedly:

  char key = keypad.getKey();  // Читаем состояние кнопок
   if (key){
    Serial.print("Button : ");
    Serial.println(key);
  }

  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.print("Center");

  if (receiver.decode(&results)) {
    if (results.value == 0XFFFFFFFF) {
      results.value = key_value;
    }
    Serial.println(results.value, HEX);
    key_value = results.value;
    receiver.resume();
  }

  int distanceL = getDistance(echoPinL, trigPinL);
  Serial.println(distanceL);

  int distanceR = getDistance(echoPinR, trigPinR);
  Serial.println(distanceR);
}
