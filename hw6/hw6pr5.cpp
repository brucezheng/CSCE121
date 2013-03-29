/*
	Bruce Zheng
	10/12/2012
	Solution for HW6 Problem 5
	Graphs out several trig related functions
*/

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

//Function of sin(x)
double sine(double x)				{return sin(x);}	
//Function of cos(x)
double cosine(double x)				{return cos(x);}	
//Function of sin(x) + cos(x)
double sin_cos_sum(double x)		{return (sin(x) + cos(x));}						
//Function of sin^2(x) + cos^2(x)
double sin_cos_sqr_sum(double x)	{return (sin(x) * sin(x) + cos(x) * cos(x));}	

int main(){
//Draws functions of sin(x), cos(x), sin(x) + cos(x), and sin^2(x) + cos^2(x)
	const int xmax = 800;
    const int ymax = 200;
    const int x_orig = xmax/2;
    const int y_orig = ymax/2; 
    const Point orig(x_orig,y_orig);
    const int r_min = -15;
    const int r_max = 16;
    const int n_points = 400;
    const int x_scale = 30;
    const int y_scale = 30;
	
	Point tl(100,100);
	Simple_window win(tl,xmax,ymax,"hw6pr5");
	Function f1(sine,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(f1);
	Function f2(cosine,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(f2);
	Function f3(sin_cos_sum,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(f3);
	Function f4(sin_cos_sqr_sum,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(f4);
	win.wait_for_button();
}