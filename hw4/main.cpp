/*
    Bruce Zheng
    9//12
    Solution for Chapter 9 Exercises 5-9
    Multiclass program with four classes and one struct
	
	Date: Taken from Stroustrup code fragments, with minor modifications
	
	Book: Contains info for title, author, ISBN, genre, and uses date for copyright date.
	Books can be checked out or not, and default to being not checked out.
	Books are checked for validity based on ISBN and genre.
	Also allows for comparison of two books and << prints out book info.
	
	Patron: Similar to Book, but contains info for name, library card number, and fines owed.
	Patrons are not checked for validity on declaration.
	
	Transaction: Struct which simply refers to a Book, Patron, and Date
	
	Library: Contains vectors of Books, Patrons, and Transactions. Transactions are added
	when a Patron "checks out" a book, which checks if Patrons have fees and if Books are
	checked out.

	main.cpp uses a simple interface to carry out a number of operations
*/

//main.cpp

#include <limits>

#include "std_lib_facilities.h"

#include "book.h"
#include "date.h"
#include "patron.h"
#include "library.h"

//Creates a simple interface that allows for the execution of multiple functions of book, patron, and library
//Uses a loop to allow for consecutive operations until user quits
int main(){
	try{
		//Only uses one library, called lib
		Library::Library lib;
		cout << "Choose Operation" << endl << "1: Create Patron" << endl
			 << "2: Create Book" << endl << "3: Set Patron Fees" << endl 
			 << "4: Print Book Details" << endl << "5: Print Patron Details" << endl 
			 << "6: Print list of Patrons with Fees" << endl
			 << "7: Check out a Book" << endl << "8: Print all Transactions" << endl
		     << "Q: Quit";
		
		//Different chars lead to different operations; loops until user inputs a char that is not 1 through 8
		bool finished = false;
		while (!finished){
			char ch;
			cout << endl << '>';
			cin >> ch;
			//Clears enter from buffer so getline isn't skipped
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			//Queries book info and adds book to library
			if (ch == '1') {
				string name, cardnumber;
				double fees;
				cout << endl << "Enter name: "; getline(cin,name);
				cout << "Enter card number: "; cin >> cardnumber;
				cout << "Enter fees: "; cin >> fees;
				Patron::Patron pp(name, cardnumber, fees);
				lib.add_patron(pp);
			}
			//Queries patron info to add to library
			else if (ch == '2') {
				string ISBN, title, author;
				int g;
				Date::Date dd;
				cout << endl << "Enter title: "; getline(cin,title);
				cout << "Enter author: "; getline(cin,author);
				cout << "Enter ISBN: "; cin >> ISBN;
				cout << "Enter genre (1 = fiction, 2 = nonfiction, 3 = periodical, "
					 << "4 = biography, 5 = children): "; cin >> g;
				cout << "Enter copyright date: "; cin >> dd;
				Book::Book bb(ISBN, title, author, Book::Book::Genre(g), dd);
				lib.add_book(bb);
			}
			//Sets fees of existing patron in library
			else if (ch == '3') {
				string cardnumber;
				double fees;
				cout << endl << "Enter Card Number: "; cin >> cardnumber;
				cout << "Enter New Fees: "; cin >> fees;
				lib.get_patron(cardnumber).set_fees(fees);
			}
			//Finds book based on ISBN and prints book info
			else if (ch == '4') {
				string ISBN;
				cout << endl << "Enter ISBN: "; cin >> ISBN;
				cout << lib.get_book(ISBN) << endl;
			}
			//Finds patron based on card number and prints patron info 
			else if (ch == '5') { 
				string cardnumber;
				cout << endl << "Enter Card Number: "; cin >> cardnumber;
				cout << lib.get_patron(cardnumber) << endl;
			}
			//Formats and prints list of patrons with fees
			else if (ch == '6') {
				cout << endl;
				vector<string> patron_list = lib.patrons_w_fees();
				int numpat = patron_list.size();
				for (int i = 0; i < numpat; ++i){
					cout << patron_list[i];
					if (i != numpat - 1) 
						cout << ", ";
				}
				cout << endl;
			}
			//Checks out a book and adds transaction to library
			else if (ch == '7') {
				string cardnumber, ISBN;
				Date::Date dd;
				cout << endl << "Enter card number: "; cin >> cardnumber;
				cout << "Enter ISBN number: "; cin >> ISBN;
				cout << "Enter today's date: "; cin >> dd;
				lib.check_out(cardnumber, ISBN, dd);
			}
			//Prints out all transactions in the library
			else if (ch == '8') {
				cout << endl;
				vector<Library::Transaction> tran_list = lib.get_transactions();
				int numtran = tran_list.size();
				for (int i = 0; i < numtran; ++i){
					cout << "[" << tran_list[i].pp.get_name() << ", " 
					     << tran_list[i].bb.get_title() << ", "  
						 << tran_list[i].dd << "]";
					if (i != numtran -1)
						cout << " , ";
				}
				cout << endl;
			}
			else finished = true;
		}
		keep_window_open();
	}
	//Error messages based off of specific throw cases
	catch (Date::Date::Invalid&) {
		cerr << "error: Invalid date\n"; 
		keep_window_open(); return 1;
	}
	catch (Book::Book::Invalid&) {
		cerr << "error: Invalid ISBN or Genre\n"; 
		keep_window_open(); return 1;
	}
	catch (Library::Library::Invalid_Book&) {
		cerr << "error: Book does not exist\n";
		keep_window_open(); return 1;
	}
	catch (Library::Library::Invalid_Patron&) {
		cerr << "error: Patron does not exist\n";
		keep_window_open(); return 1;
	}
	catch (Library::Library::Cant_Transact&) {
		cerr << "error: Transaction conditions not met\n";
		keep_window_open(); return 1;
	}
	//General error catch-all
	catch (...) {
		cerr << "Oops: unknown exception!\n"; 
		keep_window_open(); return 2;
	}
}