/*
	Bruce Zheng
	9/1/2012
	Solution for Chapter 3 Exercise 11
*/

#include "std_lib_facilities.h"

int main()
// Asks for input for amount of change user has, displays inputted value, then adds and displays total value of change
{
	cout << "How many pennies do you have?\n";
	int pennies = -1;  //I've initialized all int values as -1 to detect errors
	cin >> pennies;

	cout << "How many nickles do you have?\n";
	int nickles = -1;
	cin >> nickles;

	cout << "How many dimes do you have?\n";
	int dimes = -1;
	cin >> dimes;

	cout << "How many quarters do you have?\n";
	int quarters = -1;
	cin >> quarters;

	cout << "How many half dollars do you have?\n";
	int half_dollars = -1;
	cin >> half_dollars;

	cout << "How many dollar coins do you have?\n";
	int dollar_coins = -1;
	cin >> dollar_coins;

	if (pennies == 0)
		cout << "\nYou have no pennies";
	else if (pennies == 1)
		cout << "\nYou have " << pennies << " penny";
	else
		cout << "\nYou have " << pennies << " pennies";

	if (nickles == 0)
		cout << "\nYou have no nickles";
	else if (nickles == 1)
		cout << "\nYou have " << nickles << " nickle";
	else
		cout << "\nYou have " << nickles << " nickles";

	if (dimes == 0)
		cout << "\nYou have no pennies";
	else if (dimes == 1)
		cout << "\nYou have " << dimes << " dime";
	else
		cout << "\nYou have " << dimes << " dimes";

	if (quarters == 0)
		cout << "\nYou have no quarters";
	else if (quarters == 1)
		cout << "\nYou have " << quarters << " quarter";
	else
		cout << "\nYou have " << quarters << " quarters";

	if (half_dollars == 0)
		cout << "\nYou have no half dollars";
	else if (half_dollars == 1)
		cout << "\nYou have " << half_dollars << " half dollar";
	else
		cout << "\nYou have " << half_dollars << " half dollars";

	if (dollar_coins == 0)
		cout << "\nYou have no dollar coins";
	else if (dollar_coins == 1)
		cout << "\nYou have " << dollar_coins << " dollar coin";
	else
		cout << "\nYou have " << dollar_coins << " dollar coins";

	int total_cents = 1 * pennies + 5 * nickles + 10 * dimes + 25 * quarters + 50 * half_dollars + 100 * dollar_coins; //Determines the value of all change inputted
	int total_dollars = total_cents / 100;	
	int remainder_cents = total_cents % 100;
	cout << "\nThe total value of your change is $" << total_dollars << '.' << remainder_cents << '\n';
	keep_window_open();
}