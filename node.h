#ifndef NODE_H
#define NODE_H
#include <iostream> 
#include "student.h" 
class Node {
//destructor, constructor 
Node(Student* newStudent); 
~Node(); 

void setNext(Node* newNext); 
Node* getNext(); 
Student* getStudent();

private: 
Student* s; 
Node* next; 

};

#endif
