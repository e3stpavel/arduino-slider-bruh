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
  
  // Maxon support
  lc.clearDisplay(0);
  setQuestionMark();

  delay(1000);

  // wait input from keypad and remote controller

  bool is_enter = false;
  String keys = "";

  while (is_enter == false) {
    // attempt to get keypad tap
    char key = on_keypad_tap();

    // attempt to get remote controller click
    char btn;
    if (IrReceiver.decode()) 
    {
      btn = on_remote_click();
    }
    
    // was isprint() changed to isgraph()
    if (isprint(key) || isprint(btn)) {
      if(key == 'A' || btn == '+') {
        is_enter = true;
      } 

      if(key == '*' || btn == '.') {
        key = '.';
      }

      // TODO: could be a bug, need to check
      if (isgraph(key))
      {
        keys = keys + key;
      }
      else if (isgraph(btn))
      {
        keys = keys + btn;
      }
      
      //keys += key;

      int length = keys.length();
      Serial.println(length);

      if (length > 0) {
        //print
        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.print("bb");
        lcd.print(keys);
      }
    }

    key = (char)0;
    btn = (char)0;

    delay(100);
  }

  Serial.println(keys);
  out_speed = keys.toFloat();

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

        // lc support
        lc.clearDisplay(0);
        setExclamatoryMark();
        delay(500);
        lc.clearDisplay(0);
        setError();

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

      // maxon support
      lc.clearDisplay(0);
      setQuestionMark();

      // wait input from keypad and remote controller
      // keypad
      
      bool is_enter = false;

      while (is_enter == false)
      {
        // attempt to get keypad tap
        char key = on_keypad_tap();

        // attempt to get remote controller click
        char btn;
        if (IrReceiver.decode()) 
        {
          btn = on_remote_click();
        }

        // was isprint() changed to isgraph()
        if (isgraph(key) || isgraph(btn))
        {
          if (key == 'A' || btn == '+')
          {
            desicion = true;
            is_enter = true;
            btn = (char)0;
          }
          else if (key == 'C' || btn == '-') {
            desicion = false;
            is_enter = true;
            btn = (char)0;
          }
        }
        
      }

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

          // added lc support as well
          lc.clearDisplay(0);
          setExclamatoryMark();
          delay(500);
          lc.clearDisplay(0);
          setError();

          // filling the return values
          executed.code = 1;
          executed.status = "Incorrect speed format!";
          return executed;
        }

        // TODO: task4 call
        //// hero goes the task 4 call ////
        Serial.println("TASK4");

        lc.clearDisplay(0);
        //setLoading()

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

        // maxon support
        lc.clearDisplay(0);
        setExclamatoryMark();
        delay(500);
        lc.clearDisplay(0);
        setError();

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

        // lc support added
        lc.clearDisplay(0);
        setExclamatoryMark();
        delay(500);
        lc.clearDisplay(0);
        setError();

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

    lc.clearDisplay(0);
    //setLoading();

    delay(1000);
    /// goes end of function check ///

    // filling the return values
    executed.code = 0;
    executed.status = "Success";
  }

  // tell user about success
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Done");
  lcd.setCursor(0, 1);
  lcd.print("Status: OK");

  // lc support added
  lc.clearDisplay(0);
  setOk();
  delay(1000);
  lc.clearDisplay(0);

  // we are finished with movements
  // bring the global state back
  if (local_state.length() > 1)
  {
    GLOBAL_STATE = local_state;
  }
  else 
  {
    GLOBAL_STATE = "";
  }

  Serial.println("task2 state: " + GLOBAL_STATE);

  return executed;
}
