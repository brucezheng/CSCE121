//h file

#include "std_lib_facilities.h"
#include "Graph.h"

namespace Graph_lib {

struct Regular_polygon : Closed_polyline{
	class Invalid {};
	Regular_polygon(Point center, int sides, int radius);
	Point center() const;
	int sides() const {return s;}
private:
	void make(Point center, int sides, int radius);
	void add(Point p);
	Point cen;
	int s, r;
};

}