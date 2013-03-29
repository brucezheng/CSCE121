#ifndef PATRON_H_INCLUDED
#define PATRON_H_INCLUDED

#include "std_lib_facilities.h"
#include "date.h"

namespace Patron {

class Patron {
public:
	Patron(string name, string cardnumber, double fees);
	Patron();

	string	get_name()		 const { return name;	    }
	string	get_cardnumber() const { return cardnumber; }
	double	get_fees()		 const { return fees;		}

	bool has_fees();
	void set_fees(double f);
private:
	string name;
	string cardnumber;
	double fees;
};

bool operator==(const Patron& a, const Patron& b);
bool operator!=(const Patron& a, const Patron& b);

ostream& operator<<(ostream& os, const Patron& p);

}
#endif