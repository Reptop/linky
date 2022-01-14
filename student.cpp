#include <iostream> 
#include <cstring> 
#include "student.h" 

Student::Student() {
 //gonna leave this blank for now 
}

float* Student::getgpa() {
	return &gpa;
}

char* Student::getFname(){
	return fname; 
}

char* Student::getLname(){
	return lname; 
}

int* Student::getid() {
	return &id;
}
