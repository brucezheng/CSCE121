#include "std_lib_facilities.h"

#include "book.h"
#include "date.h"
#include "patron.h"

//library.h

namespace Library{

//Basic struct; simply contains references to three other classes
struct Transaction{
	Date::Date dd;
	Book::Book bb;
	Patron::Patron pp;
	Transaction(const Patron::Patron& pp_init, const Book::Book& bb_init, const Date::Date& dd_init){
		pp = pp_init; bb = bb_init; dd = dd_init;
	}
};

class Library{
public:
    class Invalid_Book { };
    class Invalid_Patron { };   
    class Cant_Transact { };  

	void add_book(const Book::Book& bb);
	void add_patron(const Patron::Patron& pp);
	void check_out(string cardnumber, string ISBN, const Date::Date& dd);

	//Referenced functions so that get_book.check_out() and get_patron.set_fees(double) work
	Book::Book& get_book(string ISBN);
	Patron::Patron& get_patron(string cardnumber);

	vector<string> patrons_w_fees();
	vector<Transaction> get_transactions();
private:
	vector<Book::Book> books;
	vector<Patron::Patron> patrons;
	vector<Transaction> transactions;
};

}