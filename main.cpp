#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

//prototypes, or could put functions before main
void addNew(Node* previous, Student* student);
void print(Node* next);
//float average(Node* next);
//void remove(Node* next, Node* previous, char name[]);

Node* first = NULL;

int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  //dont need this atm
  //Node* first = NULL;
  //Node* next = NULL;
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
      addNew(first, newStudent);
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

void addNew(Node* previous, Student* student) {
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
    addNew(previous -> getNext(), student);
  }
}

void print(Node* next) {
  if (next != NULL) {
    cout << next -> getStudent() -> getLast() << ", ";
    cout << next -> getStudent() -> getFirst() << endl;
    cout << next -> getStudent() -> getID() << endl;
    cout << next -> getStudent() -> getGPA() << endl << endl;
    //recurse to next student
    print(next -> getNext());
  }
}
