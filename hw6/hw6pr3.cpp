/*
	Bruce Zheng
	10/12/2012
	Solution for HW6 Problem 3
	Creates a class that can draw a regular polygon with a user defined number of sides 
	centered at a certain point with verticies at a certain distance from those points
*/

//cpp file

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include "hw6pr3.h"

namespace Graph_lib{

Regular_polygon::Regular_polygon(Point center, int sides, int radius)
			   : cen(center), s(sides), r(radius)
//Constructor, checks if enough sides and then calls make(), which adds points to Regular_polygon
{
	if (s < 3) throw Invalid();
	make(cen, s, r);
}

void Regular_polygon::add(Point p){
//Copy of Closed_polyline's add function
//Private because a Regular Polygon should always have the same number of sides
	Closed_polyline::add(p);
}

void Regular_polygon::make(Point center, int sides, int radius)
//adds points to Regular_polygon, determining x and y coordinates using trig functions
{
	const double pi = 3.14159;
	double rad_iter = 2 * pi / s;
	for (int i = 0; i < sides; ++i){
		int x = center.x + radius * cos(i * rad_iter);
		int y = center.y + radius * sin(i * rad_iter);
		add(Point(x,y));
	}
}

}

using namespace Graph_lib;

int main(){
	try{
	//Displays a number of polygons with different sides
		Point tl(100,100);
		Simple_window win(tl,400,400,"hw6pr3");
		for(int i = 3; i < 10; ++i){
			Regular_polygon r(Point(150,150),i,100);
			win.attach(r);
			win.wait_for_button();
			win.detach(r);
		}
	}
	catch(Regular_polygon::Invalid){
		cerr << "Regular_polygon does not have enough sides\n";
		keep_window_open();
		return 1;
	}
	catch(...){
		cerr << "Unkown error\n";
		keep_window_open();
		return 2;
	}
}