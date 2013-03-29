#include "library.h"

//library.cpp

namespace Library{

//Adds book to library's vector of books
void Library::add_book(const Book::Book& bb){
	books.push_back(bb);
}

//Adds patron to library's vector of library
void Library::add_patron(const Patron::Patron& pp){
	patrons.push_back(pp);
}

//Checks to see if book is checked out/patron has fees, then adds a Transaction to library's transaction vector
void Library::check_out(string cardnumber, string ISBN, const Date::Date& dd){
	const Patron::Patron& pp = get_patron(cardnumber);
	Book::Book& bb = get_book(ISBN);
	if (pp.get_fees() != 0 || bb.get_checkedout())
		throw Cant_Transact();
	else {
		transactions.push_back(Transaction(pp,bb,dd));
		bb.check_out();
	}
}

//Searches library for ISBN; returns book if found, throws error if not found
Book::Book& Library::get_book(string ISBN){
	int numbook = books.size();
	for (int i = 0; i < numbook; ++i){
		if (ISBN == books[i].get_ISBN())
			return books[i];
	}
	throw Invalid_Book();
}

//Searches library for card number; returns patron if found, throws error otherwise
Patron::Patron& Library::get_patron(string cardnumber){
	int numpat = patrons.size();
	for (int i = 0; i < numpat; ++i){
		if (cardnumber == patrons[i].get_cardnumber())
			return patrons[i];
	}
	throw Invalid_Patron();
}

//Creates and returns list of patrons that currently have fees
vector<string> Library::patrons_w_fees(){
	vector<string> patron_list;
	int numpat = patrons.size();
	for (int i = 0; i < numpat; ++i){
		if (patrons[i].has_fees())
			patron_list.push_back(patrons[i].get_name());
	}
	return patron_list;
}

//Get function for library's transaction vector
vector<Transaction> Library::get_transactions(){
	vector<Transaction> transaction_list = transactions;
	return transaction_list;
}

}