/*
	Bruce Zheng
	9/5/2012
	Solution for Chapter 5 Exercise 7
	Computes quadratic formula and reports an error for nonreal roots
*/

#include "std_lib_facilities.h"

int main(){
/* 
	Returns roots of quadratic
	If roots are identical, only returns one
	If determinant is less than 0, returns error message
*/
	double a, b, c;

	cout << "Enter values a, b, and c of the polynomial ax^2 + bx + c = 0\n";
	cin >> a >> b >> c;

	double discriminant = (b * b - 4 * a * c);
	if (discriminant < 0){
		cerr << "Your values do not return real roots!\n";
		keep_window_open();
		return -1;
	}

	double x1 = (-b + sqrt(discriminant)) / (2 * a);
	double x2 = (-b - sqrt(discriminant)) / (2 * a);

	if(x1 == x2)
		cout << "The root is " << x1 << '\n';
	else
		cout << "The two roots are " << x1 << " and " << x2 << '\n';
	keep_window_open();

	return 0;
}