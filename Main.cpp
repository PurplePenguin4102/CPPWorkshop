#include "Cube.h"
using namespace Rubix;
using namespace std;

int main()
{
  Cube cube1;
  
  cube1.RowLeft(0);
  cout << cube1 << endl;
  cube1.RowRight(0);
  cout << cube1 << endl;
  cube1.ColUp(0);
  cout << cube1 << endl;
  cube1.ColDown(0);
  cout << cube1 << endl;
  return 0;
}
