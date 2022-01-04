#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
 public:
  Student();
  char* getName();
  void setName(char newName[30]);
  int getid();
  void setid(int newid);
  float getgpa();
  void setgpa(float newgpa);
 private:
  char name[30];
  int id;
  float gpa;
};

#endif
