/*
	Bruce Zheng
	9/7/2012
	Solution for "Doodle" problem on CSCE 121-200 website
	Queries user for free times of members, and then prints a diagram of data 
*/

#include "std_lib_facilities.h"

int main(){
	//Takes input of names/time intervals, uses vectors to store data, and uses several loops to print a data table
	const int timespan = 10; int earliesthour = 8; int maxnamelength = 10;
	int linesize = maxnamelength + timespan * 4;
	vector<int> begintimes, endtimes;
	vector<int> sums(timespan);
	vector<string> names;

	//Input
	while (true){
		cout << "Enter name (enter quit when done): ";
		string name; cin >> name;
			if (name == "quit")
				break;
			else if (name.size() > 10){
				cerr << "Name too long!\n";
				keep_window_open();
				return 1;
			}
			else
				names.push_back(name);

		cout << "Enter the time interval (between 8 to 5): ";
		int begininput; cin >> begininput;
		int endinput; cin >> endinput; 
		
		int modifiedstart, modifiedend; //Changes input values to values that are easier to use; eg 12 => 5, 8 => 0
		if (begininput >= earliesthour)
			modifiedstart = begininput - earliesthour;
		else
			modifiedstart = begininput + (12 - earliesthour);
		begintimes.push_back(modifiedstart);

		if (endinput >= earliesthour)
			modifiedend = endinput - earliesthour;
		else
			modifiedend = endinput + (12 - earliesthour);
		endtimes.push_back(modifiedend);

		if (modifiedend < modifiedstart || modifiedstart < 0 || modifiedend > timespan){
			cerr << "Bad time values!\n";
			keep_window_open();
			return 1;
		}

		cout << '\n';
	}
	cout << '\n';
	
	//Output
	for (int i = 0; i < maxnamelength; ++i){ 
		cout << ' ';
	}

	for (int i = 0; i < timespan; ++i){ //Column headers
		int hour;
		if (earliesthour + i == 12)
			hour = 12;
		else
			hour = (earliesthour + i) % 12;

		if (hour > 9)
			cout << hour << "  ";
		else
			cout << hour << "   ";
	}

	cout << '\n';
	for (int i = 0; i < linesize; ++i){
		cout << '-';
	}

	try{
		int numnames = names.size(); //Main data output
		for (int i = 0; i < numnames; ++i){
			cout << '\n' << names[i] << ':';
			for (int j = names[i].size() + 1; j < maxnamelength; ++j){
				cout << ' ';
			}

			for (int j = 0; j < maxnamelength; ++j){
				if (j >= begintimes[i] && j <= endtimes[i]){
					++sums[j];
					cout << "X   ";
				}
				else{
					cout << "    ";
				}
			}
		}
	
		cout << '\n';
		for (int i = 0; i < linesize; ++i){
			cout << '-';
		}
		
		cout << '\n'; 
		for (int i = 0; i < maxnamelength; ++i){
			cout << ' ';
		}

		for (int i = 0; i < timespan; ++i){ //Sum values
			cout << sums [i];
			if(sums[i] > 9)
				cout << "  ";
			else
				cout << "   ";
		}
	}
	catch (out_of_range&){
		cerr << "Out of Range error!";
	}

	cout << '\n';
	keep_window_open();
}