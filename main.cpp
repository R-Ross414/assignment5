#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
  BST<int>* bst = new BST<int>();
  bst->insert(3);
  Database* database = new Database();
  //database->loadStudents();
  database->loadFaculty();
  DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
  list->insertFront(10);
  list->insertFront(8);
  list->insertFront(6);

  /*database->addFaculty(new Faculty(44, "name", "level1", "dept", list));
  database->addFaculty(new Faculty(22, "name", "level", "dept", list));
  database->addFaculty(new Faculty(66, "name", "level", "dept", list));*/
  database->printFaculty();
  //database->saveFaculty();
  //atabase->removeAdvisee(66, 10);
}
