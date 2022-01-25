#include "Node.h"

using namespace std;

Node::Node(Student* newStudent) {
  student = newStudent;
  nextNode = NULL;
}

Node::~Node() {
  delete student;
  student = NULL;
}

Student* Node::getStudent() {
  return student;
}

Node* Node::getNext() {
  return nextNode;
}

void Node::setNext(Node* newNext) {
  nextNode = newNext;
}
