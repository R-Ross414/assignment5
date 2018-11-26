#include <iostream>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
  BST<int>* bst = new BST<int>();
  bst->insert(3);
  Database* database = new Database();

  database->addStudent(new Student(10, "name", "level", "major", 2.2, 6));
  database->addStudent(new Student(8, "name1", "level1", "major1", 3.4, 22));
  database->printStudents();
  //cout << endl;
  //database->displayStudent(10);
  //cout << endl;
  database->addFaculty(new Faculty(44, "name", "level1", "dept", new BST<int>(8)));
  database->addFaculty(new Faculty(22, "name", "level", "dept", new BST<int>(10)));

  database->studentAdvisor(8);

  /*cout << "faculty 1" << endl;
  database->printFaculty();
  //database->deleteFaculty(22);
  cout << "faculty 2" << endl;
  database->printFaculty();*/

}
