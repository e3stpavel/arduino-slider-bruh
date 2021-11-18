// defines

// set up

String GLOBAL_STATE = "";

void setup()
{
  // declaing some stuff
  Serial.begin(9600);

}

void loop()
{
  
}

/*
 * The task 2 structure. Contains code (from 0 to 65,535) and status (Arduino String type) 
 * 
 * @author not defender
 * @return struct
 */
struct task2_struct
{
  unsigned short code;
  String status;
};

/*
 * The task 2 main function.
 * 
 * @author not defender
 * @param speed initial speed
 * @return task2_struct
 */ 
task2_struct task2(double speed)
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

    
    /*if (GLOBAL_STATE == "task2")
    {
      if (speed <= 0)
      {
        speed = Serial.read();
      }
    }*/

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
    // check if 
  }
  else 
  {
    Serial.print("ERROR! Speed not defined");

    // add to error global variable

    task2_struct executed;
    executed.code = 1;
    executed.status = "speed not defined";
    return executed;
  }
  
  
}
