// defines

// set up

// lcd connection

String GLOBAL_STATE = "";

void setup()
{
  // declaing some stuff
  //Serial.begin(9600);

}

void loop()
{
  
}

bool task1(double speed, int distance_l, int distance_r, String start_from = "baNaN")
{
  String local_state = "";

  // checking global state
  if (GLOBAL_STATE == "")
  {
    // change global state
    GLOBAL_STATE = "task2";

    // user calls

    // asks speed


  }
  else 
  {
    // change global state
    GLOBAL_STATE = "task2";

    // func calls
    local_state = GLOBAL_STATE;
  }
  
}
