#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void deleteNode(int deleteID, Node* &head, Node* &currentNode, Node* prevNode);
float average(Node* current, float total, int iterate);
void destroy(Node* &current);
void print(Node* current);
void add(Node* newNode, Node* &head, Node* currentNode, Node* prevNode);

int main() {
  bool running = true;
  char input[30];
  int intInput;
  float floatInput;
  float averageOutput;
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
      cin.ignore(10000,'\n');
    }
    else if(!strcmp(input, "print")) {
      print(head);
    }
    else if(!strcmp(input, "average")) {
      averageOutput = average(head, 0, 0);
      cout << "Average GPA: " << averageOutput << endl;
    }
    else if(!strcmp(input, "delete")) {
      cout << "ID of student to delete: ";
      cin >> intInput;
      deleteNode(intInput, head, head, head);
      cin.ignore(10000,'\n');
    }
    else if(!strcmp(input, "quit")) {
      destroy(head);
      print(head);
      running = false;
    }
    else {
      cout << "Command not recognized" << endl;
    }
  }
  return 0;
}

void deleteNode(int deleteID, Node* &head, Node* &currentNode, Node* prevNode) {
  char currentName[30];
  strcpy(currentName, currentNode->getStudent()->getName());
  Node* next = currentNode->getNext();
  if(head == NULL) {
    cout << "List is empty." << endl;
    return;
  }
  if(currentNode == NULL) {
    cout << "There is no student with the ID: " << deleteID << endl;
    return;
  }
  if(currentNode->getStudent()->getid() == deleteID) {
    if(currentNode == head) {
      delete currentNode;
      currentNode = NULL;
      head = next;
    }
    else {
      prevNode->setNext(next);
      delete currentNode;
      currentNode = NULL;
    }
    cout << "Student: " << currentName << " deleted." << endl;
  }
  else {
    deleteNode(deleteID, head, next, currentNode);
  }
}

float average(Node* current, float total, int iterate) {
  float gpaAverage = 0;
  if(current == NULL) {
    return gpaAverage;
  }
  total += current->getStudent()->getgpa();
  iterate++;
  if(current->getNext() != NULL) {
    gpaAverage = average(current->getNext(), total, iterate);
  }
  else {
    gpaAverage = (total / iterate);
  }
  return gpaAverage;
}

void destroy(Node* &current) {
  if(current == NULL) { //if list is empty
    return;
  }
  if(current->getNext() != NULL) {
    Node* next = current->getNext();
    destroy(next);
  }
  delete current;
  current = NULL;
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
    cout << "Student added." << endl;
    return;
  }
  if(currentNode == NULL) { //if at the end of list
    prevNode->setNext(newNode);
    cout << "Student added." << endl;
    return;
  }

  if(newNode->getStudent()->getid() < head->getStudent()->getid()) { //if newID is smaller than head's
    newNode->setNext(head);
    head = newNode;
    cout << "Student added." << endl;
  }
  else if(newNode->getStudent()->getid() < currentNode->getStudent()->getid()){ //if newID is smaller than current's
    prevNode->setNext(newNode);
    newNode->setNext(currentNode);
    cout << "Student added." << endl;
  }
  else {
    add(newNode, head, currentNode->getNext(), currentNode);
  }
}
