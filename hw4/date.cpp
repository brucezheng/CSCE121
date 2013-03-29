// Chrono

//------------------------------------------------------------------------------

//The definitions go into Chrono.cpp:

// Chrono.cpp
#include "date.h"

namespace Date {

// member function definitions:

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_date(yy,mm,dd)) throw Invalid();
}

//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1); // start of 21st century
    return dd;
}

//------------------------------------------------------------------------------

Date::Date()
    :y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------

// helper functions:

bool is_date(int y, Date::Month  m, int d)
{
    // assume that y is valid

    if (d<=0) return false;            // d must be positive

    int days_in_month = 31;            

    switch (m) {
case Date::feb:                        
    days_in_month = 29;
    break;
case Date::apr: case Date::jun: case Date::sep: case Date::nov:
    days_in_month = 30;                
    break;
    }

    if (days_in_month<d) return false;

    return true;
}

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    dd = Date(y,Date::Month(m),d);     // update dd
    return is;
}

//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------

/*
int main()
try
{
    Chrono::Date holiday(1978, Chrono::Date::jul, 4); // initialization
    Chrono::Date d2 = Chrono::next_Sunday(holiday);
    Chrono::Day  d  = day_of_week(d2);
    cout << "holiday is " << holiday << " d2 is " << d2 << endl;
    return holiday != d2;
}
catch (Chrono::Date::Invalid&) {
    cerr << "error: Invalid date\n"; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}
*/

//------------------------------------------------------------------------------
