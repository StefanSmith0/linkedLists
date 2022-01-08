#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char newName[30], int newID, float newGPA) {
  strcpy(name, newName);
  id = newID;
  gpa = newGPA;
}

char* Student::getName() {
  char* nameptr = name;
  return nameptr;
}

void Student::setName(char newName[30]) {
  strcpy(name, newName);
}

int Student::getid() {
  return id;
}

void Student::setid(int newid) {
  id = newid;
}

float Student::getgpa() {
  return gpa;
}

void Student::setgpa(float newgpa) {
  gpa = newgpa;
}
