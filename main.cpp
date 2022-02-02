#include <bits/stdc++.h>
#include "node.h"

using namespace std;

void addStudent(); 
void addNode(Student* newStudent);
void print(Node* next);
void deleteStudent();  



int main() {
    bool run = true;
    char input[10];
    Node* first = NULL; 
    

    while (run == true) {
        cout << "\nWould you like to ADD, DELETE, PRINT, or QUIT" << endl;
        cin >> input;

        //add student
        if (strcmp(input,"ADD") == 0) {
           addStudent(); 
	   cout << "Student Added, bro" << endl;  
        }
        //print
        else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
                if (first == NULL) {
	         cout << endl << "There are no students to print" << endl << endl;
        }
                else {
	        cout << endl;
	        print(first);
        }
    }
    //delete
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      if (first == NULL) {
	cout << endl << "There are no students to delete" << endl << endl;
      }
      else {
	cout << endl << "What is the first name of the student you would like to delete?" << endl << ">> ";
	cin.get(input, 10);
	cin.clear();
	cin.ignore(1000000, '\n');
	remove(first, NULL, input);
      }
    }
    //average
    else if (strcmp(input, "AVERAGE") == 0 || strcmp(input, "average") == 0) {
      if (first == NULL) {
	cout << endl << "There are no students to average" << endl << endl;
      }
      else {
	cout << endl << "The average GPA is: " << average(first) << endl << endl;
      }
    }
    //quit
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      break;
    }
    else {
      cout << "Invalid Input" << endl;
    }
  }
  return 0;
}


 void addNode(Student* newStudent, Node* &head) { 
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


//math
float average(Node* next, Node *& head) {
  float total = 0;
  int counter = 0;
  if (next == head) {
    total += next-> getStudent() -> getgpa();
    counter++;
  }
  while (next -> getNext() != NULL) {
    total += next -> getNext() -> getStudent() -> getgpa();
    counter++;
    next = next -> getNext();
  }
  return (total/counter);
}

