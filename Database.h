#include <iostream>
#include "BST.h"
#include "Student.h"
//include faculty class
using namespace std;

class Database
{
  public:
    Database();
    ~Database();

    void printStudents(); //cmd 1
      //call students print tree
    //void printFaculty(); //cmd 2
    void addStudent(Student* student); //cmd 7
      //call insert 

    BST* students; //will be type student
    //BST* faculty;
}
