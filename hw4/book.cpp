#include "book.h"

//Book.cpp

namespace Book{

//Book constructor w/ Inputs, checked_out's default value is always false (new books aren't checked out)
Book::Book(string ISBN_init, string title_init, string author_init, Genre g_init, Date::Date copyright_init)
	: ISBN(ISBN_init), title(title_init), author(author_init), g(g_init), copyright(copyright_init)
{
	checked_out = false;
    if (!valid_book(ISBN_init, g_init)) throw Invalid();
}

//Default values for default constructor
const Book& default_book()
{
	Date::Date dd = Date::Date();
	static const Book db("111-111-111-A", "Default Title", "Default Author", Book::fiction, dd);
	return db;
}

//Default constructor
Book::Book()
	:ISBN(default_book().get_ISBN()),
	 title(default_book().get_title()),
	 author(default_book().get_author()),
	 g(default_book().get_genre()),
     copyright(default_book().get_copyright())
{
}

//Changes checked_out to true
void Book::check_out(){
	checked_out = true;
}

//Changes checked_out to false
void Book::check_in(){
	checked_out = false;
}

//Checks if the ISBN's format is proper and if genre's range is 1-5
bool valid_book(string ISBN_test, int genre){
	int length = ISBN_test.size();
	int numdash = 0;
	istringstream is(ISBN_test);
	char ch;
	for (int i = 0; i < length; ++i) {
		is.get(ch);
		if (!isdigit(ch)) {
			if (ch == '-')
				++numdash;
			else if (i != length - 1) 
				return false;
		}
	}
	if (numdash != 3 || genre < 1 || genre > 5) return false;
	return true;
}

//Allows (Book)a == (Book)b to return truth value of ISBN equivalency 
bool operator==(const Book& a, const Book& b){
	return a.get_ISBN() == b.get_ISBN();
}

//Inverse operator of ==
bool operator!=(const Book& a, const Book& b){
	return !(a==b);
}

//Prints title, author, and ISBN of book on different lines
ostream& operator<<(ostream& os, const Book& b){
	return os << b.get_title() << endl <<
				 b.get_author() << endl <<
				 b.get_ISBN();
}

}