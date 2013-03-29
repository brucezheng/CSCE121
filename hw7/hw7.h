/*
	Bruce Zheng
	10/19/12
	Solution for Homework 7
	Creates a basic window type class that can graph simple sinosoidal functions with
	input parameters and color changing. Uses Stroustrup's ch. 16 code fragments as a template
	sfor inheriting the window class.
*/

//h file

#include "std_lib_facilities.h"

using namespace Graph_lib;

struct Trig_graph_window : Window 
{
    Trig_graph_window(Point xy, int w, int h, const string& title );
	Vector_ref<Function> functions;
	class Invalid { };
private:
	Button cos_button;
	Button sin_button;
    Button graph_button;  
    Button quit_button;
    In_box next_eq;
    Out_box cur_eq;
    Menu color_menu;
    Button menu_button;
	
    void change(Color c);
    void hide_menu() { color_menu.hide(); menu_button.show(); } 
    void black_pressed() { change(Color::black); hide_menu(); } 
    void white_pressed() { change(Color::white); hide_menu(); } 
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); } 
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void graph(); 
    void quit(); 
    void switch_sin(); 
    void switch_cos(); 
	
    static void cb_black(Address, Address); 
    static void cb_white(Address, Address); 
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_sin(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_cos(Address, Address);
    static void cb_graph(Address, Address);
    static void cb_quit(Address, Address);

	int height;
	bool is_sin;
	bool is_cos;
};