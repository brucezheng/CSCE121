/*
	Bruce Zheng
	Solution for Chapter 6 Exercise 10
	9/12/2012
	Computes and returns Permutation and Combination operations
*/
#include "std_lib_facilities.h"

long factorial(int a) //Returns a!
{ 
	long product = 1;
	for (int i = 2; i < a; i++){
		product *= i;
	}
	return product;
}

long factorial(int a, int b) //Returns a!/b!
{
	long product = 1;
	for (int i = a; i > b; i--){
		product *= i;
	}
	return product;
}

int main(){
	char op;
	int arg_a, arg_b;
	cout << "Enter operation (e.g. c 10 3 or p 5 2)\n";
	cin >> op >> arg_a >> arg_b;

	if (arg_a < arg_b){
		cerr << "Please make sure that your numbers are in descending order of size\n";
		keep_window_open();
		return 1;
	}

	long permutation, combination;
	if (op == 'p' || op == 'P'){
		long permutation = factorial(arg_a, (arg_a - arg_b));

		cout << "P(" << arg_a << ',' << arg_b << ") is " << permutation << endl;
	}
	else if (op ==  'c' || op == 'C'){
		long combination;
		if (arg_a - arg_b > arg_b)
			combination = factorial(arg_a, (arg_a - arg_b)) / factorial(arg_b);
		else
			combination = factorial(arg_a, arg_b) / factorial(arg_a - arg_b);

		cout << "C(" << arg_a << ',' << arg_b << ") is " << combination << endl;
	}
	else
		cout << "Bad input\n";
	keep_window_open();
}