/*
	Bruce Zheng
	9/1/2012
	Solution for Chapter 3 Drills 1-4
*/

#include "std_lib_facilities.h"

int main()
// Outputs several predetermined lines in the terminal, some of which is dynamic to user input
{
	cout << "Please enter the name of the person you want to write to\n";
	string first_name = "first_name";  //Here I've inputted an initial value to help detect errors
	cin >> first_name;
	cout << "\nDear " << first_name << ',';
	
	cout << "\n\tHi. So the other day I was thinking, I haven't written to " << first_name << " in a while, so here I am, writing to you.";
	cout << " Anyway, how are you? Are you doing well? I miss you a lot, and wish to see you soon.";
	
	cout << "\n\nPlease enter the name of another friend\n";
	string friend_name = "friend_name";
	cin >> friend_name;
	cout << "\n Have you seen " << friend_name << " lately?";
	
	cout << "\n\nPlease enter the sex of your second friend (m for male, f for female)\n";
	char friend_sex = '0';
	cin >> friend_sex;
	if (friend_sex == 'm')  //Outputs different text depending of if user inputted m or f. If user inputted nothing, then displays error message
		cout << "\nIf you see " << friend_name << " please ask him to call me.\n";
	else if (friend_sex == 'f')
		cout << "\nIf you see " << friend_name << " please ask her to call me.\n";
	else
		cout << "\nError, friend_sex = " << friend_sex << '\n';
	keep_window_open();
}