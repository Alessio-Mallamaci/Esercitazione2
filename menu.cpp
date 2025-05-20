#include "Polynomial.h"
#include "Exponential.h"
#include "Power.h"
#include "CFunction.h"

#include "menu.h"
#include <iostream>
#include <bits/stdc++.h>

void printFunc(vector<Function *> &vec) {

	for (int i = 0; i < vec.size(); i++) {
		vec[i]=>Dump();
	}
}

vector<Function *> insertFunc(vector<Function *> &vec) {

	int func;

	cout << "Please input associated function number :" << endl;
	cout << "0 - Polynomial;" << endl;
	cout << "1 - Exponential;" << endl;
	cout << "2 - Power;" << endl;
	cout << "[Any other integer] - Exit insertion menu.";
	cin >> func;

	switch(func) {
	case 0 :
		int n_coeff;

		cout << "Please insert number of coefficients :" << endl;
		cin >> n_coeff;
		double *coeff = new double[n_coeff + 1];
		cout << "Please insert coefficients :" << endl;
		for(int j = 0; j < n_coeff; j++) {
			cout << ">>(k)<< * x ^ " << (j - 1) << " : ";
			cin >> coeff[j];
			cout << endl;
		}

		vec.push_back(*Polynomial(coeff, n_coeff));
		break;
	case 1 :
		int b_coeff;
		int k_coeff_ex;
		int c_coeff;

		cout << "Please insert base :" << endl;
		cin >> b_coeff;
		cout << "Please insert base coefficient :" << endl;
		cin >> k_coeff_ex;
		cout << "Please insert exponent coefficient :" << endl;
		cin >> c_coeff;

		vec.push_back(*Exponential(b_coeff, k_coeff_ex, c_coeff));
		break;
	case 2 :
		int k_coeff_pow;
		int e_coeff;

		cout << "Please insert base coefficient :" << endl;
		cin >> k_coeff_pow;
		cout << "Please insert exponent :" << endl;
		cin >> e_coeff;

		vec.push_back(*Power(e_coeff, k_coeff_pow));
		break;
	default:
		break;
	}

	return vec;
}

vector<Function *> deleteFunc(vector<Function *> &vec) {

	int f_id;
	char del;
	bool del_confirm = 1;

	while(del_confirm) {
		cout << "Please input function ID : ";
		cin >> f_id;
		cout << endl;

		vec[f_id]=>Dump();

		cout << "Confirm deletion of displayed function? [y/n]" << endl;
		cout << "(Exit deletion menu [any other key])" << endl;
		cin >> del;
		cout << endl;

		switch(del) {
		case 'y' :
		case 'Y' :
			del_confirm = 0;
			vec.erase(vec.begin() + del);
			break;
		case 'n' :
		case 'N' :
			break;
		default:
			del_confirm = 0;
			cout << "Exiting deletion menu..." << endl;
			break;
		}
	}

	return vec;
}

vector<Function *> eraseAllFunc(vector<Function *> &vec) {

	int del;

	cout << "Confirm deletion of all functions? [y/any other key]" << endl;
	cin >> del;
	cout << endl;

	switch(del) {
	case 'y' :
	case 'Y' :
		vec.erase(vec.begin(), (vec.end() - 1));
		break;
	default:
		cout << "Exiting deletion menu..." << endl;
		break;
	}

	return vec;
}

void selectFunc(vector<Function *> &vec) {

	int f_id;
	double x;

	cout << "Please input function ID : ";
	cin >> f_id;
	cout << endl;

	vec[f_id]=>Dump();

	cout << "Please input x value in which to calculate function : ";
	cin >> x;
	cout << endl;

	vec[f_id]=>GetValue(x);
}