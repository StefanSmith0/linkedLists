#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

float average(Node* current, float total, int iterate, float gpaAverage);
void destroy(Node* &current);
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
    else if(!strcmp(input, "average")) {
      //      average(head, 0, 0);
    }
    else if(!strcmp(input, "quit")) {
      destroy(head);
      print(head);
      running = false;
    }
    else {
      cout << "Command not recognized" << endl;
    }
    cin.clear();
  }
  return 0;
}

float average(Node* current, float total, int iterate, float gpaAverage) {
  if(current == NULL) {
    return 0;
  }
  if(current->getNext() != NULL) {
    total += current->getStudent()->getgpa();
    iterate++;
    average(current->getNext(), total, iterate, gpaAverage);
  }
}

void destroy(Node* &current) {
  cout << "Begginning of destroy" << endl;
  if(current == NULL) { //if list is empty
    return;
  }
  if(current->getNext() != NULL) {
    cout << "Next is not null" << endl;
    destroy(current->getNext());
  }
  cout << "After recursion check" << endl;
  delete current->getStudent();
  current = NULL;
  //delete current;
  cout << "End of destroy" << endl;
}

void print(Node* current) {
  if(current == NULL) { //if list is empty, or run off the end
    return;
  }
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
  if(currentNode == NULL) { //if at the end of list
    prevNode->setNext(newNode);
    return;
  }

  if(newNode->getStudent()->getid() < head->getStudent()->getid()) { //if newID is smaller than head's
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
