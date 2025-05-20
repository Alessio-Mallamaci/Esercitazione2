#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printFunc(vector<Function *> &vec);
vector<Function *> insertFunc(vector<Function *> &vec);
vector<Function *> deleteFunc(vector<Function *> &vec);
vector<Function *> eraseAllFunc(vector<Function *> &vec);
void selectFunc(vector<Function *> &vec);

#endif