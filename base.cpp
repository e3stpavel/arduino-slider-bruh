#include <string>
#include <iostream>

using namespace std;

// global state declaration
string GLOBAL_STATE;

/*
 * base structure. Was made to return not only executuion code but to return the status as a string.
 *
 * @author GIOP tvojego ORBA
 */
struct base
{
  /* data */
  unsigned short code;
  string status;
};

/*
 * get distance simulation.
 *
 * @author GIOP4IK
 * 
 * @param sensor i dont use it but still, dunno
 * @return int
 */ 
int get_distance_mockup(char sensor)
{
  int distance = rand() % 100;

  cout << "DISTANCE: " << distance << " sensor " << sensor << endl;

  return distance;
}

/* 
 * task4's function simulation. Dunno what they need and what they return but anyways.
 *
 * @author IIOP tvoju ORB
 * 
 * @param speed again who does care what this thing does
 * @return bool
 */ 
bool task4_mockup(float speed)
{
  cout << "TASK 4; speed: " << speed << endl;

  return true;
}

/*
 * task1's function simulation. Dunno what they need and what they return but anyways
 *
 * @author not defender
 * 
 * @param speed again who does care what this thing does
 * @param direction pass to the left or to the right we should move
 * @return bool
 */
bool task1_mockup(float speed, char direction)
{
  cout << "TASK 1; speed: " << speed << endl;
  cout << "TASK 1; direction: " << direction << endl;

  return true;
}

/*
 * inital function. The actual moving from side to side.
 * 
 * @author IIOP po samii ORB
 * 
 * @param speed dunno why do we need speed but let it be, default 0
 * @return base
 */ 
base initial(float speed = 0)
{
  //cout << speed << endl;
  cout << GLOBAL_STATE << endl;

  // local state declaration
  string local_state = "";

  // return declaration
  base executed;

  // functions executing code, for now just true and false
  bool exec;

  // check if piece of shit on the side
  bool is_side = false;
  char what_side;

  // getting the distance from left and right sensor
  int distance_L = get_distance_mockup('L');
  int distance_R = get_distance_mockup('R');

  if (distance_L >= 0 && distance_L < 3)
  {
    // on the left side
    is_side = true;
    what_side = 'L';
  }
  else if (distance_R >= 0 && distance_R < 3)
  {
    // on the right side
    is_side = true;
    what_side = 'R';
  }

  // state check
  if (GLOBAL_STATE == "")
  {
    /* func called from user kinda */
    GLOBAL_STATE = "task2";

    // if its in the right position, ask user speed and go to the opposite edge
    if (is_side)
    {
      cout << "Input the speed (can be float):" << endl;
      cin >> speed;

      if (speed <= 0)
      {
        // tell user that he's stupid
        cout << "Speed must be more than 0 and can't be negative!" << endl;

        // filling the return values
        executed.code = 1;
        executed.status = "Incorrect speed format!";
        //return executed;
      }
    }
    else
    {
      // tell user that he's stupid
      char desicion;
      cout << "Module isn't on the edge. Go to the edge? [y/n]" << endl;
      cin >> desicion;

      // if he's insane, call task4's fucntion, if nah - say that he's ORBoIIOP
      if (desicion == 'y')
      {
        exec = task4_mockup(speed);
        if (!exec)
        {
          // say to user to fuckk off
          cout << "Something went wrong while was moving to the closest edge!" << endl;

          // filling the return values
          executed.code = 2;
          executed.status = "Another (task4) function aborted!";
          //return executed;
        }

        is_side = true;
        // what_side should return task4's function i swear
        what_side = 'L';
      }
      else
      {
        cout << "You're ORBoIIOP! Why do you call me if I'm not on the side?" << endl;

        // filling the return values
        executed.code = 3;
        executed.status = "Incorrect position for operating!";
        //return executed;
      }
    }
  }
  else
  {
    /* func called from other func sorta */
    local_state = GLOBAL_STATE;
    GLOBAL_STATE = "task2";

    // if its in the right position, go to the opposite edge
    if (is_side)
    {
      if (speed <= 0)
      {
        // tell user that he's stupid
        cout << "Speed must be more than 0 and can't be negative!" << endl;

        // filling the return values
        executed.code = 1;
        executed.status = "Incorrect speed format!";
        //return executed;
      }
    }
    else 
    {
      // fuck off the function cuz position not defined

      // filling the return values
      executed.code = 3;
      executed.status = "Incorrect position for operating!";
      //return executed;
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
    
    exec = task1_mockup(speed, goto_side);
    if (!exec)
    {
      // say that someone can't write code
      cout << "Something went wrong while was moving to the another edge!" << endl;

      // filling the return values
      executed.code = 4;
      executed.status = "Another (task1) function aborted!";
      //return executed;
    }

    // we are finished with movements

    // bring the global state back
    GLOBAL_STATE = local_state;

    // filling the return values
    executed.code = 0;
    executed.status = "Success";
    
  }

  return executed;
}

int main(int argc, char const *argv[])
{
  /* code */
  GLOBAL_STATE = "task8";

  base what = initial(2.2f);
  cout << what.code << " , " << what.status << endl;

  return 0;
}