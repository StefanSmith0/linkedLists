#include "Node.h"

using namespace std;

Node::Node() {
  student = NULL;
  nextNode = NULL;
}

Student* Node::getStudent() {
  return student;
}

void Node::setStudent(Student* newStudent) {
  student = newStudent;
}

Node* Node::getNext() {
  return nextNode;
}

void Node::setNext(Node* newNext) {
  nextNode = newNext;
}
