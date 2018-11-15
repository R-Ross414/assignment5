#include <iostream>
#include <string>
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
} ;
