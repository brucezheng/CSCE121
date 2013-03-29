/*
	Bruce Zheng
	10/12/2012
	Solution for HW6 Problem 1
	Creates an image of a 3x3 checkerboard
*/

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main(){
//Draws 9 squares to form a checkerboard pattern with alternating colors
	Point tl(100,100);
	Simple_window win(tl,250,250,"hw6pr1");

	Rectangle r1(Point(50,50),50,50);   r1.set_fill_color(Color::white); win.attach(r1);
	Rectangle r2(Point(99,50),50,50);   r2.set_fill_color(Color::red);   win.attach(r2);
	Rectangle r3(Point(148,50),50,50);  r3.set_fill_color(Color::white); win.attach(r3);
	Rectangle r4(Point(50,99),50,50);   r4.set_fill_color(Color::red);   win.attach(r4);
	Rectangle r5(Point(99,99),50,50);   r5.set_fill_color(Color::white); win.attach(r5);
	Rectangle r6(Point(148,99),50,50);  r6.set_fill_color(Color::red);   win.attach(r6);
	Rectangle r7(Point(50,148),50,50);  r7.set_fill_color(Color::white); win.attach(r7);
	Rectangle r8(Point(99,148),50,50);  r8.set_fill_color(Color::red);   win.attach(r8);
	Rectangle r9(Point(148,148),50,50); r9.set_fill_color(Color::white); win.attach(r9);

	win.wait_for_button();
}