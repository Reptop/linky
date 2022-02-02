#include <bits/stdc++.h>
#include "node.h"

using namespace std;

void addStudent(); 
void addNode(Student* newStudent);
void print(Node* next);
void deleteStudent();  

Node* head = NULL; 

int main() {
    bool run = true;
    char cmd[10];
    //Node* head = NULL; 
    

    while (run == true) {
        cout << "\nWould you like to ADD, DELETE, PRINT, or QUIT" << endl;
        cin >> cmd;

        //add student
        if (strcmp(cmd,"ADD") == 0) {
           addStudent(); 
	   cout << "Student Added, bro" << endl;  
        }
        //print everyone
        else if (strcmp(cmd,"PRINT") == 0) {
       		print(head); 
	}
	else if (strcmp(cmd,"DELETE") == 0) { 
          //del(list); 
            cout << "Student Deleted!" << endl;
        }
        else if (strcmp(cmd, "QUIT") == 0) {
             cout << "See you next time..."; 
             break;
        }
        else 
            cout << "Invalid Input, dummy"; 
    }
}

 void addNode(Student* newStudent) { 
  //Node* previous;
  Node* current = head;

    if (current == NULL) {
	head = new Node(newStudent); 
        head->setStudent(newStudent);
    }
    else {
    	while (current -> getNext() != NULL) {
      	current = current -> getNext(); 
    }
    current->setNext(new Node(newStudent)); 
    current -> getNext() -> setStudent(newStudent);
    //cout << "Its working" << endl; 
    //cout << current -> getStudent() -> getLname() << ", ";  
    //cout << head-> getStudent() -> getFname();  
  }
}

void addStudent() {
	Student* s = new Student();   
        cout << "Enter First Name: " << endl; 	
	cin >> s->getFname();
	cin.clear(); 
	cin.ignore(10000, '\n');

        cout << "Enter Last Name: " << endl; 	
	cin >> s->getLname();
	cin.clear(); 
	cin.ignore(10000, '\n');
		
        cout << "Enter GPA: " << endl; 	
	cin >> *s->getgpa();
	cin.clear(); 
	cin.ignore(10000, '\n');
	
        cout << "Enter Student ID: " << endl; 	
	cin >> *s->getid();
	cin.clear(); 
	cin.ignore(10000, '\n');

	//add this student to a node 
	addNode(s);
}

void print(Node* next) {
  if (next != NULL) {
    cout << next -> getStudent() -> getLname() << ", ";
    cout << next -> getStudent() -> getFname() << endl;
    cout << *next -> getStudent() -> getid() << endl;
    cout << *next -> getStudent() -> getgpa() << endl << endl;
    //recurse to next student
    print(next -> getNext());
  }
}

void deleteStudent() {
        
}

