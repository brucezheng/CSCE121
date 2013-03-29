/*
	Bruce Zheng
	10/12/2012
	Solution for HW6 Problem 4
	Creates a class called Regular_octagon which draws a regular octagon centered at a point
	with verticies a user defined distance away from the center
*/

//cpp file

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include "hw6pr4.h"

namespace Graph_lib{

Regular_octagon::Regular_octagon(Point center, int radius)
			   : cen(center), r(radius)
//Constructor; calls make(), which adds points to Regular_octagon
{
	make(cen, r);
}

void Regular_octagon::add(Point p){
//Copy of Closed_polyline's add function
//Private because a Regular octagon should always have a constant number of sides
	Closed_polyline::add(p);
}

void Regular_octagon::make(Point center, int radius)
//adds points to Regular_octagon, determining x and y coordinates using trig functions
{
	const double pi = 3.14159;
	const int sides = 8;
	double rad_iter = 2 * pi / sides;
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
//Tests various functions of Regular_octagon
	Point tl(100,100);
	Simple_window win(tl,400,400,"hw6pr4");
	Regular_octagon o(Point(200,200),100);
	win.attach(o);
	win.wait_for_button();
	o.set_color(Color::blue);
	o.set_fill_color(Color::red);
	win.wait_for_button();
	o.move(50,-50);
	Regular_octagon o2(Point(100,200),50);
	o2.set_style(Line_style(Line_style::dash,2));
	win.attach(o2);
	win.wait_for_button();
}
catch(...){
	cerr << "Unkown error\n";
	keep_window_open();
	return 2;
}
}