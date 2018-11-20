#include <iostream>
#include "People.h"
#include <string>

using namespace std;

int main()
{
  Faculty* faculty = new Faculty(4, "name", "level", "dept", new BST<int>());
  //Faculty* faculty = new Faculty();
}
