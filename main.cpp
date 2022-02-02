#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

//prototypes, or could put functions before main
void addNew(Node* previous, Student* student, Node*& first);
void print(Node* next);
float average(Node* next, Node* first);
void remove(Node* next, Node* previous, char name[], Node*& first);


int main() {
  cout << std::fixed;
  cout << std::setprecision(2);
  Node* first = NULL; 

  while (true) {
    char input[10];
    int intInput;
    float floatInput;
    cout << "What would you like to do? ADD/PRINT/DELETE/AVERAGE/QUIT" << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore(1000000, '\n');
    //add
    //i mean, instead of doing this i could just lowercase the input 
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      Student* newStudent = new Student;
      cout << endl << "What is the first name?" << endl << ">> ";
      cin.get(newStudent -> getFirst(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "What is the last name?" << endl << ">> ";
      cin.get(newStudent -> getLast(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');
      cout << "What is the ID?" << endl << ">> ";
      cin >> intInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      newStudent -> setID(intInput);
      cout << "What is the GPA?" << endl << ">> ";
      cin >> floatInput;
      cin.clear();
      cin.ignore(1000000, '\n');
      newStudent -> setGPA(floatInput);
      addNew(first, newStudent, first);
      cout << "Student has been added" << endl << endl;
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
	//first = remove(first, input);
	remove(first, NULL, input, first);
      }
    }
    //average
    else if (strcmp(input, "AVERAGE") == 0 || strcmp(input, "average") == 0) {
      if (first == NULL) {
	cout << endl << "There are no students to average" << endl << endl;
      }
      else {
	cout << endl << "The average GPA is: " << average(first, first) << endl << endl;
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

void addNew(Node* previous, Student* student, Node*& first) {
  if (first == NULL) {
    first = new Node(student);
  }
  else if (student -> getID() < first -> getStudent() -> getID()) {
    Node* temp = new Node(first -> getStudent());
    temp -> setNext(first -> getNext());
    first -> setStudent(student);
    first -> setNext(temp);
  }
  else if (previous -> getNext() == NULL) {
    Node* newNode = new Node(student);
    previous -> setNext(newNode);
  }
  else if (student -> getID() < previous -> getNext() -> getStudent() -> getID()) {
    Node* newNode = new Node(student);
    newNode -> setNext(previous -> getNext());
    previous -> setNext(newNode);
  }
  else {
    addNew(previous -> getNext(), student, first);
  }
}

void print(Node* next) {
  if (next != NULL) {
    cout << "NAME: " << next -> getStudent() -> getLast() << ", ";
    cout <<  next -> getStudent() -> getFirst() << endl;
    cout << "STUDENT ID: " << next -> getStudent() -> getID() << endl;
    cout << "GPA: " << next -> getStudent() -> getGPA() << endl << endl;
    //recurse to next student
    print(next -> getNext());
  }
}

void remove(Node* next, Node* previous, char name[], Node*& first) {
  char yesno;
  if (next == first && strcmp(next -> getStudent() -> getFirst(), name) == 0) {
    cout << endl << next -> getStudent() -> getLast() << ", ";
    cout << next -> getStudent() -> getFirst() << endl;
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGPA() << endl << endl;
    cout << "Would you would like to delete this student? (y/n)" << endl << ">> ";
    cin >> yesno;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (yesno == 'y') {
      cout << "Student has now been deleted" << endl << endl;
      if (next -> getNext() == NULL) {
	next -> ~Node();
	first = NULL;
      }
      else {
	first = next -> getNext();
	next -> ~Node();
	remove(first, NULL, name, first);
      }
    }
    else if (yesno == 'n') {
      cout << "Student will not be deleted" << endl << endl;
      if (next -> getNext() != NULL) {
	remove(next -> getNext(), next, name, first);
      }
    }
    else {
      cout << "Invalid input" << endl << endl;
    }
  }
  else if (strcmp(next -> getStudent() -> getFirst(), name) == 0) {
    cout << endl << next -> getStudent() -> getLast() << ", ";
    cout << next -> getStudent() -> getFirst() << endl;
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGPA() << endl << endl;
    cout << "Would you would like to delete this student? y/n" << endl << ">> ";
    cin >> yesno;
    cin.clear();
    cin.ignore(1000000, '\n');
    if (yesno == 'y') {
      cout << "Student has now been deleted" << endl << endl;
      previous -> setNext(next -> getNext());
      next -> ~Node();
    }
    else if (yesno == 'n') {
      cout << "Student will not be deleted" << endl << endl;
    }
    else {
      cout << "Invalid input" << endl << endl;
    }
  }
  if (next -> getNext() != NULL) {
    remove(next -> getNext(), next, name, first);
  }
}
//math
float average(Node* next, Node* first) {
  float total = 0;
  int counter = 0;
  if (next == first) {
    total += next -> getStudent() -> getGPA();
    counter++;
  }
  while (next -> getNext() != NULL) {
    total += next -> getNext() -> getStudent() -> getGPA();
    counter++;
    next = next -> getNext();
  }
  return (total/counter);
}
