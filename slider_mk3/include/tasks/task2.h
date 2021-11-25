/*
 * Task 2. Edge to edge function. Thing goes brrr from one side to another
 *
 * @authors e3stpavel, NewOkNo, defender
 * 
 * @param speed Is important to pass to another functions, default zero
 * @returns tsk
 */ 

tsk edge_to_edge(float speed)
{
  Serial.println(GLOBAL_STATE);

  // local state declaration
  String local_state = ""; 

  // return declaration
  tsk executed;

  // check if this piece of shit on the edge
  bool is_side = false;
  char what_side;

  // getting the distance from left and right sensor
  int distance_L = get_ultrasonic_distance(1);
  int distance_R = get_ultrasonic_distance(0);

  Serial.println(distance_L, distance_R);

  if (distance_L >= 0 && distance_L < 1)
  {
    // on the left side
    is_side = true;
    what_side = 'L';
  }
  else if (distance_R >= 0 && distance_R < 1)
  {
    // on the right side
    is_side = true;
    what_side = 'R';
  }
  
  // state check
  if (GLOBAL_STATE == "")
  {
    // func called from user kinda 
    GLOBAL_STATE = "task2";

    // if its in the right position, ask user speed and go to the opposite edge
    if (is_side)
    {
      // write to LCD question and q-mark to MAX led
      // lcd
      lcd.setCursor(0, 0);
      lcd.print("Imput the speed");
      lcd.setCursor(1, 0);
      lcd.print("can be float");
      // max
      // poka len`

      // wait input from keypad and remote controller
      // keypad
      char key = keypad.getKey();
      String keys;
      if (key)
      {
        keys += key;
        speed = keys.toFloat();
      }
      // remote controller
      // poka len`

      Serial.println(speed);

      if (speed <= 0)
      {
        // tell user that he's stupid
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed must be");
        lcd.setCursor(1, 0);
        lcd.print("more than 0");

        // filling the return values
        executed.code = 1;
        executed.status = "Incorrect speed format!";
        return executed;
      }
      else
      {
        // tell user that he's stupid
        char desicion;
        
      }
    }
  }
  // func called from other func sorta
  else
  {
    
  }
  

  return executed;
}