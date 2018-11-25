#include <iostream>
#include "Person.h"
//include faculty class
using namespace std;

class Database
{
  public:
    Database();
    Database(BST<Student*>* students, BST<Faculty*>* faculty);
    ~Database();

    void printStudents(); //cmd 1
      //call students print tree
    void printFaculty(); //cmd 2
    void displayStudent(int ID);//cmd 3
    void displayFaculty(int ID);//cmd 4
    void addStudent(Student* student); //cmd 7
    void addFaculty(Faculty* faculty); //cmd 9

    BST<Student*>* students;
    BST<Faculty*>* faculty;
};

Database::Database()
{
  students = new BST<Student*>();
  faculty = new BST<Faculty*>();
}

Database::Database(BST<Student*>* students, BST<Faculty*>* faculty)
{
  this->students = students;
  this->faculty = faculty;
}

Database::~Database() {}

void Database::printStudents()
{
  students->printPtrTree();
}

void Database::printFaculty()
{
  faculty->printPtrTree();
}

void Database::displayStudent(int ID)
{
  if (students->containsPtr(new Student(ID, "_", "_", "_", 0.0, 0)))
  {
    cout << "Hello world" << endl;
    Student* student = students->searchPtr(new Student(ID, "_", "_", "_", 0.0, 0));
    cout << *student;
  }
}

void Database::displayFaculty(int ID)
{

}

void Database::addStudent(Student* student)
{
  students->insert(student);
}

void Database::addFaculty(Faculty* faculty)
{
  this->faculty->insert(faculty);
}
