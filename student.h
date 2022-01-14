#ifndef STUDENT_H 
#define STUDENT_
#include <iostream> 

class Student {
	public:
	//destructor, constructor 
	Student(); 
	float* getgpa(); 
	char* getFname();
	char* getLname();
	int* getid(); 

	private:
	float gpa; 
	int id; 
	char fname[80]; 
	char lname[80]; 

};
#endif
