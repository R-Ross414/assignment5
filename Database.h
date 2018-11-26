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
    void printFaculty(); //cmd 2
    void displayStudent(int ID);//cmd 3
    void displayFaculty(int ID);//cmd 4
    void studentAdvisor(int ID);//cmd 5
    void facultyAdvisee(int ID);//cmd 6
    void addStudent(Student* student); //cmd 7
    void deleteStudent(int ID);//cmd 8
    void addFaculty(Faculty* faculty); //cmd 9
    void deleteFaculty(int ID); //cmd 10

    BST<Student*>* students;
    BST<Faculty*>* faculty;
};

///////////////////////////////////////////////////////////
////////////////////*IMPLEMENTATION*//////////////////////
Database::Database()
{
  students = new BST<Student*>();
  faculty = new BST<Faculty*>();
}

/////////////////////////////////////////////////////////
Database::Database(BST<Student*>* students, BST<Faculty*>* faculty)
{
  this->students = students;
  this->faculty = faculty;
}

/////////////////////////////////////////////////////////
Database::~Database() {}

/////////////////////////////////////////////////////////
void Database::printStudents() //cmd 1
{
  students->printPtrTree();
}

/////////////////////////////////////////////////////////
void Database::printFaculty() //cmd 2
{
  faculty->printPtrTree();
}

/////////////////////////////////////////////////////////
void Database::displayStudent(int ID) //cmd 3
{
  if (students->containsPtr(new Student(ID, "_", "_", "_", 0.0, 0)))
  {
    Student* student = students->searchPtr(new Student(ID, "_", "_", "_", 0.0, 0));
    cout << *student;
  }
  else
  {
    cout << "Student not found " << endl;
  }
}

/////////////////////////////////////////////////////////
void Database::displayFaculty(int ID) //cmd 4
{
  if (faculty->containsPtr(new Faculty(ID, "_", "_", "_", new BST<int>(0))))
  {
    Faculty* faculty = this->faculty->searchPtr(new Faculty(ID, "_", "_", "_", new BST<int>(0)));
    cout << *faculty;
    cout << endl;
  }
  else
  {
    cout << "Faculty not found" << endl;
  }
}

/////////////////////////////////////////////////////////
void Database::studentAdvisor(int ID) //cmd 5
{
  if (students->containsPtr(new Student(ID, "_", "_", "_", 0.0, 0)))
  {
    Student* student = students->searchPtr(new Student(ID, "_", "_", "_", 0.0, 0));
    int advisor = student->advisor;

    if (faculty->containsPtr(new Faculty(advisor, "name", "level", "dept", new BST<int>(10))))
    {
      Faculty* facultyAdvisor = faculty->searchPtr(new Faculty(advisor, "_", "_", "_", new BST<int>(ID)));
      cout << *facultyAdvisor << endl;
    }
  }
}

/////////////////////////////////////////////////////////
void Database::facultyAdvisee(int ID) //cmd 6
{
  
}

/////////////////////////////////////////////////////////
void Database::addStudent(Student* student) //cmd 7
{
  students->insertPtr(student);
}

/////////////////////////////////////////////////////////
void Database::deleteStudent(int ID)
{
  /*if (students->containsPtr(new Student(ID, "_", "_", "_", 0.0, 0)))
  {
    Student* student = students->searchPtr(new Student(ID, "_", "_", "_", 0.0, 0));
    students->deleteRec(student);
  }*/
}

/////////////////////////////////////////////////////////
void Database::addFaculty(Faculty* faculty) //cmd 9
{
  this->faculty->insertPtr(faculty);
}

/////////////////////////////////////////////////////////
void Database::deleteFaculty(int ID)
{
  if (faculty->containsPtr(new Faculty(ID, "_", "_", "_", new BST<int>())))
  {
    Faculty* faculty = this->faculty->searchPtr(new Faculty(ID, "_", "_", "_", new BST<int>()));
    this->faculty->deleteRec(faculty);
  }
}
