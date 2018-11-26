#include <iostream>
#include "Person.h"
#include <fstream>
using namespace std;

class Database
{
  public:
    Database();
    Database(BST<Student*>* students, BST<Faculty*>* faculty);
    ~Database();

    void saveStudents();
    void loadStudents();
    void saveFaculty();
    void loadFaculty();

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
    void changeAdvisor(int studentID, int facultyID); //cmd 11
    void removeAdvisee(int facultyID, int studentID); //cmd 12

    int facultyCount;
    BST<Student*>* students;
    BST<Student>* studentStatic;
    BST<Faculty*>* faculty;
    BST<Faculty>* facultyStatic;
};

///////////////////////////////////////////////////////////
////////////////////*IMPLEMENTATION*//////////////////////
Database::Database()
{
  students = new BST<Student*>();
  faculty = new BST<Faculty*>();
  facultyCount = 0;
  studentStatic = new BST<Student>();
  facultyStatic = new BST<Faculty>();
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
void Database::saveStudents()
{
  ofstream output("studentTable.txt");
  output << *studentStatic;
  output.close();
}

/////////////////////////////////////////////////////////
void Database::loadStudents()
{
  ifstream input("studentTable.txt");

  int ID, advisor;
  string name, major, level;
  double GPA;

  while (input)
  {
    input >> ID;
    input >> name;
    input >> level;
    input >> major;
    input >> GPA;
    input >> advisor;
    Student* student = new Student(ID, name, level, major, GPA, advisor);
    addStudent(student);
  }
}
/////////////////////////////////////////////////////////
void Database::saveFaculty()
{
  ofstream output("facultyTable.txt");
  output << facultyCount << endl;
  output << *facultyStatic;
  output.close();
}

/////////////////////////////////////////////////////////
void Database::loadFaculty()
{
  ifstream input("facultyTable.txt");
  ifstream input2("facultyTable.txt");

  int ID, advisee, faculty_count;
  int advisee_count, space_count, line_idx = 0;
  string name, dept, level, line;
  DoublyLinkedList<int>* advisees = new DoublyLinkedList<int>();

  input >> faculty_count;
  int line_count = 0;
  while (input && line_count < faculty_count)
  {
    input >> ID;
    input >> name;
    input >> level;
    input >> dept;
    input >> advisee_count;
    int count = 0;
    while (count < advisee_count)
    {
      input >> advisee;
      advisees->insertFront(advisee);
      count++;
    }
    Faculty* faculty = new Faculty(ID, name, level, dept, advisees);
    advisees = new DoublyLinkedList<int>();
    space_count = 0;
    advisee_count = 0;
    addFaculty(faculty);
    line_count++;
  }
  this->facultyCount = faculty_count;
}

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
  if (students->containsPtr(new Student(ID)))
  {
    Student* student = students->searchPtr(new Student(ID));
    cout << *student;
    cout << endl;
  }
  else
  {
    cout << "Student not found " << endl;
  }
}

/////////////////////////////////////////////////////////
void Database::displayFaculty(int ID) //cmd 4
{
  if (faculty->containsPtr(new Faculty(ID)))
  {
    Faculty* faculty = this->faculty->searchPtr(new Faculty(ID));
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
  if (students->containsPtr(new Student(ID)))
  {
    Student* student = students->searchPtr(new Student(ID));
    int advisor = student->advisor;

    if (faculty->containsPtr(new Faculty(advisor)))
    {
      Faculty* facultyAdvisor = faculty->searchPtr(new Faculty(advisor));
      cout << *facultyAdvisor << endl;
    }
  }
}

/////////////////////////////////////////////////////////
void Database::facultyAdvisee(int ID) //cmd 6
{
  if (faculty->containsPtr(new Faculty(ID)))
  {
    Faculty* faculty = this->faculty->searchPtr(new Faculty(ID));
    for (int i = 0; i < faculty->advisees->getSize(); i++)
    {
      if (students->containsPtr(new Student(faculty->advisees->get(i))))
      {
        cout << *(students->searchPtr(new Student(faculty->advisees->get(i)))) << endl;
      }
    }
  }
  else
  {
    cout << "Faculty not found" << endl;
  }
}

/////////////////////////////////////////////////////////
void Database::addStudent(Student* student) //cmd 7
{
  students->insertPtr(student);
  studentStatic->insert(*student);
}

/////////////////////////////////////////////////////////
void Database::deleteStudent(int ID) //cmd 8
{
  if (students->containsPtr(new Student(ID)))
  {
    Student* student = students->searchPtr(new Student(ID));
    students->deleteRecPtr(student);
    studentStatic->deleteRec(*student);
  }
}

/////////////////////////////////////////////////////////
void Database::addFaculty(Faculty* faculty) //cmd 9
{
  this->faculty->insertPtr(faculty);
  facultyStatic->insert(*faculty);
  facultyCount++;
}

/////////////////////////////////////////////////////////////////
void Database::deleteFaculty(int ID) //cmd 10
{
  if (faculty->containsPtr(new Faculty(ID)))
  {
    Faculty* faculty = this->faculty->searchPtr(new Faculty(ID));
    this->faculty->deleteRecPtr(faculty);
    facultyStatic->deleteRec(*faculty);
    facultyCount--;
  }
}

///////////////////////////////////////////////////////////////////
void Database::changeAdvisor(int studentID, int facultyID) //cmd 11
{
  if (students->containsPtr(new Student(studentID)))
  {
    students->searchPtr(new Student(studentID))->SetAdvisor(facultyID);
  }
  else
  {
    cout << "Student not found " << endl;
  }
}

///////////////////////////////////////////////////////////////////
void Database::removeAdvisee(int facultyID, int studentID) //cmd 12
{
  /*if (faculty->containsPtr(new Faculty(facultyID)))
  {
    this->faculty->searchPtr(new Faculty(facultyID))->RemoveAdvisee(studentID);
  }
  else
  {
    cout << "Faculty not found" << endl;
  }*/
}
