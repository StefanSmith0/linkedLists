#include "Student.h"
#include <cstring>

using namespace std;

Student::Student() {
  strcpy(name, "default name");
  id = 0;
  gpa = 0.00;
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
