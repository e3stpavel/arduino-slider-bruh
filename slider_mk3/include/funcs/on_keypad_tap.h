/* 
 * Handles keypad keys tap action and printing the key value to Serial Monitor
 *
 * @author default
 * @returns void
 */ 

void on_keypad_tap()
{
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}