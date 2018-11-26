#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
  BST<int>* bst = new BST<int>();
  bst->insert(3);
  Database* database = new Database();

  DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
  list->insertFront(10);
  list->insertFront(8);
  list->insertFront(6);
  //list->deletePos(2);
  cout << *list << endl;
  database->addStudent(new Student(10, "name", "level", "major", 2.2, 6));
  database->addStudent(new Student(8, "name1", "level1", "major1", 3.4, 22));
  database->addStudent(new Student(6, "name1", "level1", "major1", 3.4, 22));
  //database->printStudents();
  database->displayStudent(6);
  database->displayStudent(8);
  database->displayStudent(10);
  cout << endl;
  database->changeAdvisor(10, 66);
  //database->deleteStudent(10);
  //database->printStudents();

  database->addFaculty(new Faculty(44, "name", "level1", "dept", list));
  database->addFaculty(new Faculty(22, "name", "level", "dept", list));
  database->addFaculty(new Faculty(66, "name", "level", "dept", list));
  //database->removeAdvisee(66, 10);
}
