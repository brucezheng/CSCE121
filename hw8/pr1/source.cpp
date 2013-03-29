/*
	Bruce Zheng
	11/19/12
	Solution for HW 8 problem 1
	Using a map, attempts to predict english text by compiling statistics of characters following a window of user defined size
	Uses an input file, an intermediate formatted file, and an output file
*/

#include "std_lib_facilities.h"
#include "winstat.h"

#include <map>
#include <ctime>

//Error checking classes
class No_file{};
class No_windows{};
class Bad_numbers{};
class Win_missing{};

map<string, Winstat> win_map;

void clean(string in, string out){ //Formats original text document to disinclude nonalpha characters and upper case letters, as well as repeat whitespaces
	ifstream is(in.c_str());
	ofstream os(out.c_str());
	if (!is) throw(No_file());
	char ch;
	char lastvalid = ' ';
	while (is.get(ch)){
		if (islower(ch)){
			os << ch;
			lastvalid = ch;
		}
		else if (isupper(ch)){
			ch = ch-'A'+'a';
			os << ch;
			lastvalid = ch;
		}
		else if (isspace(ch)){
			if (lastvalid != ' ') os << ' ';
			lastvalid = ' ';
		}
	}
}

string wrap(string file, int window_size){ //Appends the first window_size chars to the end, returns the first window of the document for use in write
	ifstream is(file.c_str());
	ofstream os(file.c_str(), ios::app);
	if (!is) throw (No_file());
	string first_window;
	getline(is, first_window);
	first_window = first_window.substr(0,window_size);
	os << first_window;
	return first_window;
}

void add_window(string window, char ch){ //Adds a window/next ch combination to win_map
	if(win_map.count(window) == 0){
		Winstat w;
		w.add_ch(ch);
		win_map[window] = w;
	}
	else
		win_map[window].add_ch(ch);
}

void make_win_map(string file, int window_size){ //Fills win_map with data from formatted text
	ifstream is(file.c_str());
	string current_win;
	char ch;
	for(int i = 0; i < window_size; ++i){
		is.get(ch);
		current_win += ch;
	}
	while(is.get(ch)){
		add_window(current_win, ch);
		current_win = current_win.substr(1) + ch;
	}
}

void write(string file, int out_length, string first_window){ //Writes to a document using statistics from win_map. Uses a parameter for first window b/c maps do not remember the first value entered
	string current_win = first_window;

	ofstream os(file.c_str());
	if (win_map.size() < 1) throw (No_windows());
	
	os << current_win;
	out_length -= current_win.size();

	while(out_length > 0){
		if (win_map.count(current_win) == 0){
			cerr << current_win;
			throw (Win_missing());
		}

		char ch = win_map[current_win].guess_ch();
		os << ch;
		current_win = current_win.substr(1) + ch;

		--out_length;
	}
}

int main(){ //Gathers data for file names, window size and print size, then creates win_map and prints out predicted text, also contains error checking
	try {
		string in_file, for_file, out_file;
		cout << "Name of input file: ";
		cin >> in_file;
		cout << "Name of intermediate file: ";
		cin >> for_file;
		cout << "Name of output file: ";
		cin >> out_file;

		int out_length, window_size;
		cout << "Number of characters to print: ";
		cin >> out_length;
		cout << "Window Size: ";
		cin >> window_size;
		if(window_size < 0 || window_size > out_length) throw (Bad_numbers());

		clean(in_file, for_file);
		string first_window = wrap(for_file, window_size);
		time_t start = time(NULL);
		make_win_map(for_file, window_size);
		write(out_file, out_length, first_window);
		time_t end = time(NULL);
		time_t elapsed = end - start;
		cout << "Time Taken: " << elapsed << " seconds" << endl;
		keep_window_open();
	}
	catch (No_file) {
		cerr << "Bad file name!\n";
		keep_window_open();
		return 1;
	}
	catch (No_windows) {
		cerr << "Window vector is empty!\n";
		keep_window_open();
		return 1;
	}
	catch (Bad_numbers) {
		cerr << "Bad window size or output length!\n";
		keep_window_open();
		return 1;
	}
	catch (Win_missing) {
		cerr << "Window not found!\n";
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Unknown exception!\n";
		keep_window_open();
		return 2;
	}
}