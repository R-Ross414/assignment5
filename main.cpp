#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
  char choice;
  cout << "Choose a command" << endl;
  cout << "Enter '1' to print the list of students and info" << endl;
  cout << "Enter '2' to print faculty and info" << endl;
  cout << "enter '3' to find and display student info" << endl;
  cout << "enter '4' to find and display faculty info" << endl;
  cout << "enter '5' to print name and info of a faculty advisor given ID" << endl;
  cout << "enter '6' to print names and info of faculty advisees" << endl;
  cout << "enter '7' to add new student" << endl;
  cout << "enter '8' to delete student" << endl;
  cout << "enter '9' to add new faculty" << endl;
  cout << "enter '10' to delete faculty" << endl;
  cout << "enter '11' to change a students advisor" << endl;

  cin >> choice;

  if (choice == '1')
  {
    database->printStudents();
  }
  if (choice == '2')
  {
    database->printFaculty();
  }
  if (choice == '3')
  {
    database->displayStudent(ID);
  }
  if (choice == '4')
  {
    database->displayFaculty(ID);
  }
  if (choice == '5')
  {
    database->studentAdvisor(ID);
  }
  if (choice == '6')
  {
    database->facultyAdvisee(ID);
  }
  if (choice == '7')
  {
    database->addStudent(ID);
  }
  if (choice == '8')
  {
    database->deleteStudent(ID);
  }
  if (choice == '9')
  {
    database->addFaculty(ID);
  }
  if (choice == '10')
  {
    database->deleteFaculty(ID);
  }
  if (choice == '11')
  {
    changeAdvisor(studentID, facultyID)
  }
)

  BST<int>* bst = new BST<int>();
  bst->insert(3);
  Database* database = new Database();
  //database->loadStudents();
  database->loadFaculty();
  DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
  database->printFaculty();

}
