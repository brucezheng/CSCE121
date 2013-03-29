#include "order.h"
#include "std_lib_facilities.h"


Order::Order(string name_init, string address_init, int data_init) //Constructor
	 :name(name_init), address(address_init), data(data_init)
{
}

const Order& default_order()
{
	static Order or("Name","Address",0);
	return or;
}

Order::Order() //Default constructor
	 :name(default_order().get_name()), address(default_order().get_address()), data(default_order().get_data())
{
}

void Order::add_purchase(string name, double unit_price, int count) { //Adds a purchase to purchases
	Purchase p(name, unit_price, count);
	purchases.push_back(p);
}

Purchase::Purchase() //Default constructor
		:name("Name"), unit_price(0), count(0)
{
}

Purchase::Purchase(string name_init, double unit_price_init, int count_init) //Basic constructor
		:name(name_init), unit_price(unit_price_init), count(count_init)
{
}

