#ifndef STUDENT_H 
#define STUDENT_
#include <iostream> 

class Student {
//destructor, constructor 
Student(); 
~Student(); 

float setgpa(float gpa);
float getgpa(); 
char setFname(char fname[80]);
char getFname();
char setLname(char Lname[80]);
char getLname();
int setid(int id); 
int getid(); 

private:
float gpa; 
int id; 
char fname[80]; 
char lname[80]; 

};
#endif
