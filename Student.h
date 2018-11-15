#include "Person.h"
#include <iostream>

using namespace std;

class Student : public Person
{
  public:
    Student():Person()
    {
      major = "";
      GPA = 0.0;
      advisor = 0;
    }
    Student(int ID, string name, string level, string major, double GPA, int advisor):Person(ID, name, level)
    {
      this->major = major;
      this->GPA = GPA;
      this->advisor = advisor;
    }
    ~Student()
    {

    }

    string major;
    double GPA;
    int advisor;
} ;
