#include <iostream>
#include "BST.h"
//#include "Person.h"
#include "Student.h"
#include <string>

using namespace std;

int main()
{
  //Person* person = new Person(4, "name", "level");
  Student* student = new Student(2, "name", "level", "major", 4.0, 6);
  Student* student2 = new Student(3, "name", "level", "major", 4.0, 6);
  if (*student < *student2)
  {
    cout << "It worked" << endl;
  }
}
