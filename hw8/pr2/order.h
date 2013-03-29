#ifndef order_h
#define order_h

#include "std_lib_facilities.h"

class Purchase { //Contains a name, unit_price, and count
public:
	Purchase();
	Purchase(string name, double unit_price, int count);
	string get_name() const			{ return name; }
	double get_unit_price() const	{ return unit_price; }
	int get_count() const			{ return count; }
private:
	string name;
	double unit_price;
	int count;
};

class Order { //Contains a name, address, data (num purchases), and a vector of purchases
public:
	Order();
	Order(string name, string address, int data);
	string get_name()		const { return name; }
	string get_address()	const { return address; }
	int get_data()			const { return data; }
	void add_purchase(string name, double unit_price, int count); //Adds a purchase of that information to the Order
	vector<Purchase> purchases;
private:
	string name;
	string address;
	int data; //Number of purchases
};

#endif