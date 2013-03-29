#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

//book.h

#include "std_lib_facilities.h"

#include "date.h"

namespace Book {

class Book {
public:
	class Invalid { };
	enum Genre {
		fiction=1, nonfiction, periodical, biography, children
	};

	Book(string ISBN, string title, string author, Genre g, Date::Date copyright);
	Book();

	//get functions
	string	   get_ISBN()		const { return ISBN;		}
	string	   get_title()		const { return title;		}
	string	   get_author()		const { return author;		}
	Genre	   get_genre()		const { return g;			}
	Date::Date get_copyright()  const { return copyright;	}
	bool	   get_checkedout() const { return checked_out; }

	void check_out();
	void check_in();
private:
	bool checked_out;
	Genre g;
	string ISBN;
	string title;
	string author;
	Date::Date copyright;
};

bool valid_book(string ISBN, int genre);

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

ostream& operator<<(ostream& os, const Book& b);
}
#endif