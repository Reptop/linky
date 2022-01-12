#include <iostream> 
#include "node.h" 

Node::Node(Student* newStudent) {
	next = NULL; 
}

Node::~Node() {
	delete &s; 
	next = NULL;
}

void Node::setNext(Node* newNext) {
	next = newNext;
}

void Node::getNext() {
	return next; 
}

Student* Node::getStudent() {
	return s; 
}	

















