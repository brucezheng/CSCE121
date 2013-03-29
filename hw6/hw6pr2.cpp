/*
	Bruce Zheng
	10/12/2012
	Solution for HW6 Problem 2
	Creates an abstract picture of a house
*/

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main(){
//Creates multiple shapes of different types to create picture of a house
	Point tl(100,100);
	Simple_window win(tl,400,425,"hw6pr2");

	Rectangle base(Point(50,175),300,200);
	base.set_style(Line_style(Line_style::solid,2));

	Polygon roof;
	roof.add(Point(50,175));
	roof.add(Point(200,100));
	roof.add(Point(350,175));
	roof.set_style(Line_style(Line_style::solid,2));
	roof.set_fill_color(Color::black);

	Rectangle door(Point(100,275), 50, 100);
	door.set_fill_color(Color::black);

	Rectangle window1(Point(175,200),75,75);
	Rectangle window2(Point(275,200),50,50);

	Circle smoke1(Point(120,115),24);
	smoke1.set_color(Color::white);
	smoke1.set_fill_color(Color::white);
	Circle smoke2(Point(140,95),15);
	smoke2.set_color(Color::white);
	smoke2.set_fill_color(Color::white);
	Circle smoke3(Point(125,85),10);
	smoke3.set_color(Color::white);
	smoke3.set_fill_color(Color::white);

	Polygon chimney;
	chimney.add(Point(100,125));
	chimney.add(Point(100,150));
	chimney.add(Point(150,125));
	chimney.set_fill_color(Color::black);

	win.attach(base);
	win.attach(smoke1);
	win.attach(smoke2);
	win.attach(smoke3);
	win.attach(chimney);
	win.attach(roof);
	win.attach(door);
	win.attach(window1);
	win.attach(window2);

	win.wait_for_button();
}