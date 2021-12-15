// some local function to use 
float input_speed(float in_speed)
{
  float out_speed = 0;
  // write to LCD question and q-mark to MAX led
  // lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input the speed");
  lcd.setCursor(0, 1);
  lcd.print("can be float");
  delay(5000);
  // TODO: max
  // poka len`

  // wait input from keypad and remote controller
  // keypad

  bool is_enter = false;
  String keys = "";
  //char keys[16];
  uint8_t i = 0;
  int length = 0;
  while (is_enter == false) {
    char key = on_keypad_tap();

    if (isprint(key)) {
      if(key == 'A') {
        is_enter = true;
      } 

      if(key == '*') {
        key = '.';
      }

      keys = keys + key;
      //keys += key;
      length = keys.length();
      Serial.println(length);

      if (length > 0) {
        //print
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.print("bb");
        lcd.print(keys);
      }
    }

    delay(100);
    i++;
  }

  Serial.println(keys);
  out_speed = keys.toFloat();

  // TODO: remote controller
  // poka len`

  //delay(2000);
  Serial.println(out_speed);
  
  return out_speed;
}

/*
 * Task 2. Edge to edge function. Thing goes brrr from one side to another
 *
 * @authors e3stpavel, NewOkNo, defender
 * 
 * @param speed Is important to pass to another functions, default zero
 * @returns tsk
 */ 

tsk edge_to_edge(float speed = 0)
{
  Serial.println("State " + GLOBAL_STATE);

  // local state declaration
  String local_state = ""; 

  // return declaration
  tsk executed;

  // check if this on the edge
  bool is_side = false;
  char what_side;

  // getting the distance from left and right sensor
  int distance_L = get_ultrasonic_distance(1);
  int distance_R = get_ultrasonic_distance(0);

  Serial.println("Left" + distance_L);
  Serial.println("Rigth" + distance_R);

  // debugging
  delay(2000);

  if (distance_L >= 0 && distance_L < 5)
  {
    // on the left side
    is_side = true;
    what_side = 'L';
  }
  else if (distance_R >= 0 && distance_R < 5)
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
      Serial.println("SIDE DEFINED ASK SPEED");
      speed = input_speed(speed);

      if (speed <= 0)
      {
        // tell user that he's stupid
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed must be");
        lcd.setCursor(0, 1);
        lcd.print("more than 0");

        // TODO: lc support

        // filling the return values
        executed.code = 1;
        executed.status = "Incorrect speed format!";
        return executed;
      }
    }
    else
    {
      // tell user that he's stupid
      bool desicion;

      // write to LCD message and ! mark to MAX led
      // lcd
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not on the edge");
      lcd.setCursor(0, 1);
      lcd.print("go to? A/C");
      // TODO: max
      // poka len`

      // wait input from keypad and remote controller
      // keypad
      
      bool is_enter = false;

      while (is_enter == false)
      {
        char key = on_keypad_tap();

        if (isprint(key))
        {
          if (key == 'A')
          {
            desicion = true;
            is_enter = true;
          }
          else if (key == 'C') {
            desicion = false;
            is_enter = true;
          }
        }
        
      }

      // TODO: remote controller 
      // poka len`

      delay(1000);
      Serial.println(desicion);

      if (desicion == true)
      {
        Serial.println("SIDE WAS NOT DEFINED - ASK SPEED");
        speed = input_speed(speed);

        if (speed <= 0)
        {
          // tell user that he's stupid
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Speed must be");
          lcd.setCursor(0, 1);
          lcd.print("more than 0");

          // TODO: add lc support as well 

          // filling the return values
          executed.code = 1;
          executed.status = "Incorrect speed format!";
          return executed;
        }

        // TODO: task4 call
        //// hero goes the task 4 call ////
        Serial.println("TASK4");
        delay(1000);
        /// goes end of function check ///

        is_side = true;
        
        // returns task4 function
        what_side = 'L';
      }
      else
      {
        // write to LCD message and ! mark to MAX led
        // lcd
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Not on the edge");
        lcd.setCursor(0, 1);
        lcd.print("Error!");
        delay(1000);
        // TODO: max
        // poka len`

        // filling the return values
        executed.code = 3;
        executed.status = "Incorrect position for operating!";
        return executed;
      }
    }
  }
  // func called from other func sorta
  else
  {
    local_state = GLOBAL_STATE;
    GLOBAL_STATE = "task2";

    // if its in the right position, go to the opposite edge
    if (is_side)
    {
      if (speed <= 0)
      {
        // tell user that he's stupid
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Speed must be");
        lcd.setCursor(0, 1);
        lcd.print("more than 0");

        // TODO: lc support

        // filling the return values
        executed.code = 1;
        executed.status = "Incorrect speed format!";
        return executed;
      }
    }
    else 
    {
      // decline the function cuz position not defined

      delay(2000);

      // filling the return values
      executed.code = 3;
      executed.status = "Incorrect position for operating!";
      return executed;
    }
  }
  
  // if speed is appropriate, we are on the edge and we specified the edge 
  char goto_side;

  // debugging
  delay(2000);
  Serial.println(is_side);
  Serial.println(what_side);

  if (speed > 0 && is_side && !isblank(what_side))
  {
    // everything's fine, call task1's function to start moving
    if (what_side == 'R')
    {
      goto_side = 'L';
    }
    else if (what_side == 'L')
    {
      goto_side = 'R';
    }
    

    delay(5000);
    Serial.println(goto_side);
    // TODO: task1 call
    //// hero goes the task 1 call ////
    Serial.println("TASK1");
    delay(1000);
    /// goes end of function check ///


    // we are finished with movements
    // bring the global state back
    GLOBAL_STATE = local_state;
    Serial.println(GLOBAL_STATE);

    // filling the return values
    executed.code = 0;
    executed.status = "Success";
  }

  return executed;
}
