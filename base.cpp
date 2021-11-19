#include <string>
#include <iostream>

using namespace std;

struct base
{
  /* data */
  unsigned short code;
  string status;
};

base initial(float speed)
{
  cout << speed << endl;

  base executed;
  executed.code = 0;
  executed.status = "Success";

  return executed;
}

int main(int argc, char const *argv[])
{
  /* code */
  cout << "Hello world" << endl;

  base what = initial(2.2f);
  cout << what.code << " , " << what.status << endl;

  return 0;
}