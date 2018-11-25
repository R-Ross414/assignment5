#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
  BST<int>* bst = new BST<int>();
  bst->insert(3);
  Database* database = new Database();
  database->addStudent(new Student(8, "name", "level", "major", 2.2, 6));
  database->addStudent(new Student(10, "name1", "level1", "major1", 3.4, 22));
  database->printStudents();
  database->displayStudent(8);

  database->addFaculty(new Faculty(44, "name", "level1", "dept", bst));
  database->addFaculty(new Faculty(22, "name", "level", "dept", bst));
  database->printFaculty();
  database->displayFaculty(44);
}
