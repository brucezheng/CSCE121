/*
	Bruce Zheng
	9/3/2012
	Solution for Chapter 4 Exercise 5
	Basic four operation calculator
*/

#include "std_lib_facilities.h"

int main()
//Basic four operation calculator
{
	cout << "Please enter the basic two operand arithmetic problem you wish to solve (in the format of 1 + 1)\n";
	double operand1, operand2;
	char operation;
	cin >> operand1 >> operation >> operand2;

	cout << "= ";

	switch(operation){
	case '+':
		cout << operand1 + operand2;
		break;
	case '-':
		cout << operand1 - operand2;
		break;
	case '/':
		cout << operand1 / operand2;
		break;
	case '*':
		cout << operand1 * operand2;
		break;
	default:
		cout << "Improper format or unknown operator";
		break;
	}

	cout << '\n';
	keep_window_open();
}