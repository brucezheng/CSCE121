//h file

#include "std_lib_facilities.h"
#include "Graph.h"

namespace Graph_lib {

struct Regular_octagon : Closed_polyline{
	class Invalid {};
	Regular_octagon(Point center, int radius);
	Point center() const;
protected:
	void make(Point center, int radius);
	void add(Point p);
	Point cen;
	int r;
};

}