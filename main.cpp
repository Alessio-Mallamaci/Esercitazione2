
#include <iostream>
#include <bits/stdc++.h>

#include "Polynomial.h"
#include "Power.h"
#include "Exponential.h"
#include "menu.h" 

using namespace std;

int main() {

    vector<Function *> v;
    bool flag;
    int input;

    while(flag == true){

        cout << "Please input associated operation number:" << endl;
        cout << "0 - Exit menu;" << endl;
        cout << "1 - View initialised functions;" << endl;
        cout << "2 - Add a function;" << endl;
        cout << "3 - Delete a function;" << endl;
        cout << "4 - Delete all functions;" << endl;
        cout << "5 - Select a function;" << endl;
        cin >> input;
        cout << endl;

        switch(input) {
        case 0 :
            flag == false;
            break;
        case 1 :
            printFunc(v);
            break;
        case 2 :
            v = insertFunc(v);
            break;
        case 3 :
            v = deleteFunc(v);
            break;
        case 4 :
            v = eraseAllFunc(v);
            break;
        case 5 :
            selectFunc(v);
            break;
        default:
            break;
        }
    }

    cout << "Exited from menu!" << endl;
}

