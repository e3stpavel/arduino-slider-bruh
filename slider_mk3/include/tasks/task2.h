// some local function to use 
float input_speed(float in_speed)
{
  float out_speed = in_speed;
  // write to LCD question and q-mark to MAX led
  // lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input the speed");
  lcd.setCursor(1, 0);
  lcd.print("can be float");
  // TODO: max
  // poka len`

  // wait input from keypad and remote controller
  // keypad
  char key = keypad.getKey();
  String keys;
  if (key)
  {
    keys += key;
    out_speed = keys.toFloat();
  }
  // TODO: remote controller
  // poka len`

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

  Serial.println(distance_L);
  Serial.println(distance_R);

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
      lcd.print("go to? y/n");
      // TODO: max
      // poka len`

      // wait input from keypad and remote controller
      // keypad
      char key = keypad.getKey();
      String keys;
      if (key)
      {
        Serial.println(key);
        if (key == 'A')
        {
          // accept
          desicion = true;
        }
        else if (key == 'C')
        {
          // cancel
          desicion = false;
        }
      }
      // TODO: remote controller 
      // poka len`

      Serial.println(desicion);

      // if he's insane, call task4's fucntion, if nah - say that he's ORBoIIOP
      if (desicion)
      {
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
      // fuck off the function cuz position not defined

      // filling the return values
      executed.code = 3;
      executed.status = "Incorrect position for operating!";
      return executed;
    }
  }
  
  // if speed is appropriate, we are on the edge and we specified the edge 
  char goto_side;

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
    
    // TODO: task1 call
    //// hero goes the task 1 call ////

    /// goes end of function check ///


    // we are finished with movements
    // bring the global state back
    GLOBAL_STATE = local_state;

    // filling the return values
    executed.code = 0;
    executed.status = "Success";
  }

  return executed;
}
