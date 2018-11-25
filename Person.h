#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

class Person
{
  public:
    Person();
    Person(int ID, string name, string level);
    ~Person();

    int ID;
    string name;
    string level;

    bool operator<(Person& other);
    bool operator>(Person& other);
    bool operator==(Person& other);
    bool operator!=(Person& other);
} ;


Person::Person()
{
  ID = 0;
  name = "";
  level = "";
}

Person::Person(int ID, string name, string level)
{
  this->ID = ID;
  this->name = name;
  this->level = level;
}

Person::~Person() {}

bool Person::operator<(Person& other)
{
  return ID < other.ID;
}

bool Person::operator>(Person& other)
{
  return ID > other.ID;
}

bool Person::operator==(Person& other)
{
  return ID == other.ID;
}

bool Person::operator!=(Person& other)
{
  return ID != other.ID;
}
class Student : public Person
{
  public:
    friend ostream& operator<<(ostream& os, Student& output)
    {
      os << output.ID << " " << output.name << " " << output.level << " " << output.major << " " << output.GPA << " " << output.advisor;
      return os;
    }

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
    ~Student() {}

    string major;
    double GPA;
    int advisor;
} ;

class Faculty : public Person
{
  public:
    friend ostream& operator<<(ostream& os, Faculty& output)
    {
      os << output.ID << " " << output.name << " " << output.level << " " << output.dept << " " << *(output.advisees);
      return os;
    }

    Faculty():Person()
    {
      dept = "";
      advisees = new BST<int>();
    }

    Faculty(int ID, string name, string level, string dept, BST<int>* advisees):Person(ID, name, level)
    {
      this->dept = dept;
      this->advisees = advisees;
    }

    ~Faculty() {}

    string dept;
    BST<int>* advisees;
} ;
