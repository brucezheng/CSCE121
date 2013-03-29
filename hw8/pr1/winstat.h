#ifndef WINSTAT_H_INCLUDED
#define WINSTAT_H_INCLUDED

#include "std_lib_facilities.h"

class Winstat { //Provides basic functionality to collect data on character frequencies and can also give a random char using those frequencies
public:
	Winstat();

	void add_ch(char ch);
	char guess_ch();
private:
	vector<int> stats;
};

#endif