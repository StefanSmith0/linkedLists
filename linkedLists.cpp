#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void print(Node* current);
void add(Node* newNode, Node* &head, Node* currentNode, Node* prevNode);

int main() {
  bool running = true;
  char input[30];
  int intInput;
  float floatInput;
  Node* head = NULL;
  while(running) {
    cout << "Enter Command: ";
    cin.getline(input, 30);
    if(!strcmp(input, "add")) {
      cout << "New student name: ";
      cin.getline(input, 30);
      cout << "New student id: ";
      cin >> intInput;
      cout << "New student gpa: ";
      cin >> floatInput;
      Student* newStudent = new Student(input, intInput, floatInput);
      Node* newNode = new Node(newStudent);
      add(newNode, head, head, head);
    }
    else if(!strcmp(input, "print")) {
      print(head);
    }
    else if(!strcmp(input, "quit")) {
      running = false;
    }
    else {
      cout << "Command not recognized" << endl;
    }
  }
  return 0;
}

void print(Node* current) {
  cout << endl;
  cout << "Student: " << current->getStudent()->getName() << endl;
  cout << "ID: " << current->getStudent()->getid() << endl;
  cout << "GPA: " << current->getStudent()->getgpa() << endl;
  cout << endl;
  if(current->getNext() != NULL) {
    print(current->getNext());
  }
}

void add(Node* newNode, Node* &head, Node* currentNode, Node* prevNode) {
  if(head == NULL) { //if list is empty
    head = newNode;
    return;
  }
  else if(currentNode == NULL) { //if at the end of list
    prevNode->setNext(newNode);
    return;
  }
  else if(newNode->getStudent()->getid() < head->getStudent()->getid()) { //if newID is smaller than head's
    newNode->setNext(head);
    head = newNode;
  }
  else if(newNode->getStudent()->getid() < currentNode->getStudent()->getid()){ //if newID is smaller than current's
    prevNode->setNext(newNode);
    newNode->setNext(currentNode);
  }
  else {
    add(newNode, head, currentNode->getNext(), currentNode);
  }
}
