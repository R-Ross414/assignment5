#include "Person.h"
#include <iostream>

using namespace std;

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

Person::~Person()
{

}

bool Person::operator<(Person& other)
{
  return ID < other.ID;
}
