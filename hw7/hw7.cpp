//cpp file

#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "hw7.h"

using namespace Graph_lib;
using namespace std;

//Constructor
Trig_graph_window::Trig_graph_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
	cos_button(Point(10,0), 70, 20, "Cos", cb_cos),
	sin_button(Point(90,0), 70, 20, "Sin", cb_sin),
    color_menu(Point(x_max()-90,30),70,20,Menu::vertical,"color"),
    menu_button(Point(x_max()-90,30), 70, 20, "Colors", cb_menu),
    graph_button(Point(x_max()-170,0), 70, 20, "Graph", cb_graph),
    quit_button(Point(x_max()-90,0), 70, 20, "Quit", cb_quit),
    next_eq(Point(300,0), 300, 20, "Parameters:"),
    cur_eq(Point(80,30), 500, 20, "current eq:")
{
	attach(cos_button);
	attach(sin_button);
    attach(graph_button);
    attach(quit_button);
    attach(next_eq);
    attach(cur_eq);
    color_menu.attach(new Button(Point(0,0),0,0,"Black",cb_black));
    color_menu.attach(new Button(Point(0,0),0,0,"White",cb_white));
    color_menu.attach(new Button(Point(0,0),0,0,"Red",cb_red));
    color_menu.attach(new Button(Point(0,0),0,0,"Blue",cb_blue));
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    cur_eq.put("Format: (r_min,r_max,(x,y),n_points,x_scale,y_scale)");

	is_sin = false;
	is_cos = false;
}

//Void reference_to functions

void Trig_graph_window::cb_quit(Address, Address pw)
{  
	reference_to<Trig_graph_window>(pw).quit();
} 

void Trig_graph_window::cb_graph(Address, Address pw)
{  
	reference_to<Trig_graph_window>(pw).graph();
} 

void Trig_graph_window::cb_black(Address, Address pw)      
{  
    reference_to<Trig_graph_window>(pw).black_pressed();
} 

void Trig_graph_window::cb_white(Address, Address pw)      
{  
    reference_to<Trig_graph_window>(pw).white_pressed();
} 

void Trig_graph_window::cb_red(Address, Address pw)     
{  
    reference_to<Trig_graph_window>(pw).red_pressed();
} 

void Trig_graph_window::cb_blue(Address, Address pw)    
{  
    reference_to<Trig_graph_window>(pw).blue_pressed();
}

void Trig_graph_window::cb_menu(Address, Address pw)
{  
    reference_to<Trig_graph_window>(pw).menu_pressed();
} 

void Trig_graph_window::cb_cos(Address, Address pw)
{  
	reference_to<Trig_graph_window>(pw).switch_cos();
} 

void Trig_graph_window::cb_sin(Address, Address pw)
{  
	reference_to<Trig_graph_window>(pw).switch_sin();
} 

void Trig_graph_window::quit()
{ //Exit window
    hide();
}

void Trig_graph_window::graph()
{ //Uses data frm input box field to add a function to window
	//Parses input box field
	string input = next_eq.get_string();
	char p1, p2, p3, p4, c1, c2, c3, c4, c5, c6;
	int r_min, r_max, x_orig, y_orig, n_points, x_scale, y_scale;
	stringstream is (input);
	is >> p1 >> r_min >> c1 >> r_max >> c2 >> p2 >> x_orig >> c3 >> y_orig
	   >> p3 >> c4 >> n_points >> c5 >> x_scale >> c6 >> y_scale >> p4;

	//Error checking and create/attach function
	if(is_sin || is_cos){
		//Only does something if either sin or cos button has been pressed
		stringstream os;
		if(p1 != '(' || p2 != '(' || p3 != ')' || p4 != ')' || c1 != ',' || 
		   c2 != ',' || c3 != ',' || c4 != ',' || c5 != ',' || c6 != ',')
			throw Invalid();
		Point orig(x_orig,y_orig);
		if(is_sin) {
			functions.push_back(new Function(sin,r_min,r_max,orig,n_points,x_scale,y_scale));
			os << "(sin,";
		}
		else {
			functions.push_back(new Function(cos,r_min,r_max,orig,n_points,x_scale,y_scale));
			os << "(cos,";
		}
		os << r_min << ',' << r_max << ',' << '(' << x_orig << ',' << y_orig
		   << ")," << n_points << ',' << x_scale << ',' << y_scale << ')';
		cur_eq.put(os.str());
		attach(functions[functions.size()-1]);
	}

    redraw();
	is_sin = false;
	is_cos = false;
}

void Trig_graph_window::change(Color c)
{ //Changes the color of the last graphed function; does nothing if no previous function
	if (functions.size() > 0){
		functions[functions.size()-1].set_color(c);
		redraw();
	}
}

void Trig_graph_window::switch_sin()
{ //Toggles next graphed function to be sine
	is_sin = true;
	is_cos = false;
}

void Trig_graph_window::switch_cos()
{ //Toggles next graphed function to be cosine
	is_sin = false;
	is_cos = true;
}

int main() 
{ //Creates an object of type Trig_graph_window and contains error checking
try {
    Trig_graph_window win(Point(100,100),800,400,"hw7");
    return gui_main();
}
catch(Trig_graph_window::Invalid) {
    cerr << "Invalid Input!\n";
	keep_window_open();
    return 1;
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
	keep_window_open();
    return 2;
}
}