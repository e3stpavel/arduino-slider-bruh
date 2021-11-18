// defines

// set up

// lcd connection

String GLOBAL_STATE = "";

void setup()
{
  // declaing some stuff
  Serial.begin(9600);

}

void loop()
{
  
}

bool task1(double speed)
{
  String local_state = "";

  // checking global state
  if (GLOBAL_STATE == "")
  {
    // change global state
    GLOBAL_STATE = "task2";

    // user calls

    // asks speed
    // NOTE: for now reading from serial
    
    // speed was not defined
    if (GLOBAL_STATE == "task2")
    {
      if (speed <= 0)
      {
        speed = Serial.read();
      }
    }

  }
  else 
  {
    // save to local state
    local_state = GLOBAL_STATE;

    // change global state
    GLOBAL_STATE = "task2";

    // func calls
  }

  // check speed
  if (speed > 0)
  {
    
  }
  else 
  {
    Serial.print("ERROR! Speed not defined");

    // add to error global variable

    return false;
  }
  
  
}
