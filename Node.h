#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  Student* getStudent();
  void setStudent(Student* newStudent);
  Node* getNext();
  void setNext(Node* newNext);
 private:
  Node* nextNode;
  Student* student;
};

#endif
