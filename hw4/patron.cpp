#include "patron.h"

namespace Patron{

//Basic constructor for Patron
Patron::Patron(string name_init, string cardnumber_init, double fees_init)
	  : name(name_init), cardnumber(cardnumber_init), fees(fees_init)
{
}

//Used for default constructor
const Patron& default_patron(){
	static const Patron dp("Default Name", "0000", 0);
	return dp;
}

//Default constructor
Patron::Patron()
	  :name(default_patron().get_name()),
	  cardnumber(default_patron().get_cardnumber()),
	  fees(default_patron().get_fees())
{
}

//Checks if patron has fees
bool Patron::has_fees(){
	if (fees == 0) return false;
	return true;
}

//Sets patron's fees
void Patron::set_fees(double f){
	fees = f;
}

//(patron)a == (patron)b returns truth value of equivalency of card numbers
bool operator==(const Patron& a, const Patron& b){
	return a.get_cardnumber() == b.get_cardnumber();
}

//Returns inverse value of ==
bool operator!=(const Patron& a, const Patron& b){
	return !(a==b);
}

//Prints patron's name, cardnumber, and fees on separate lines
ostream& operator<<(ostream& os, const Patron& p){
	return os << p.get_name() << endl <<
				 p.get_cardnumber() << endl <<
				 '$' << p.get_fees();
}

}