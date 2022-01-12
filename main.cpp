#include <bits/stdc++.h>
#include "node.h"

using namespace std;

int main() {
    bool run = true;
    char cmd[10];

    while (run == true) {
        cout << "\nWould you like to ADD, DELETE, PRINT, or QUIT" << endl;
        cin >> cmd;

        //add student
        if (strcmp(cmd,"ADD") == 0) {
           // add(list); 
        }
        //print everyone
        else if (strcmp(cmd,"PRINT") == 0) {
        
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

//void add()
