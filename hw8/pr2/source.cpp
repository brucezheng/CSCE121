/*
	Bruce Zheng
	11/19/12
	Solution for HW 8 problem 2
	Writes and reads Orders from files and can put into lists or vectors and sort by address or name
	Creates a list and a vector from user input, writes to a file, reads from each file, formats and writes again,
	then combines both formatted files into a third file
*/

#include <limits>

#include "order.h"
#include "std_lib_facilities.h"

bool cmp_name (Order a, Order b) { //Compares a and b's names alphabetically
	int cmp = a.get_name().compare(b.get_name());
	if (cmp < 0) return true; //Seemingly obtuse way of checking the value of the compare value, but avoids possible errors
	if (cmp >= 0) return false;
	return true;
}

bool cmp_add (Order a, Order b) {  //Compares a and b's addresses alphabetically
	int cmp = a.get_address().compare(b.get_address());
	if (cmp < 0) return true; //Seemingly obtuse way of checking the value of the compare value, but avoids possible errors
	if (cmp >= 0) return false;
	return true;
}

void input_purchases(Order& or) { //Creates a purchase using user input
	for(int i = 0; i < or.get_data(); ++i){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Purchase Name: ";		string name;	   getline(cin, name);
		cout << "Unit Price: "; double unit_price; cin >> unit_price;
		cout << "Count: ";		int count;		   cin >> count;
		or.purchases.push_back(Purchase(name, unit_price, count));
		if(i == (or.get_data() - 1))
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

Order input_order() { //Creates an order using user input
	cout << "Order Name: ";	   string name;	   getline(cin, name);
	cout << "Address: ";	   string address; getline(cin, address);
	cout << "Num Purchases: "; int data;	   cin >> data; 
	cout << endl;
	Order or(name, address, data);
	input_purchases(or);
	cout << endl;
	return or;
}

vector<Order> make_vector(int num) { //Makes a vector of orders using user input
	vector<Order> v;
	for(int i = 0; i < num; ++i)
		v.push_back(input_order());
	return v;
}

list<Order> make_list(int num) { //Makes a list of orders using user input
	list<Order> l;
	for(int i = 0; i < num; ++i)
		l.push_back(input_order());
	return l;
}

string print_order(Order& or){ //Returns a string of an order's data
	ostringstream os;
	os << or.get_name() << ", " << or.get_address() << ", " << or.get_data();
	for(vector<Purchase>::iterator iter = or.purchases.begin(); iter < or.purchases.end(); ++iter)
		os << ' ' << (*iter).get_name() << ", " << (*iter).get_unit_price() << ", " << (*iter).get_count();
	return os.str();
}

Order read_order(string line){ //Returns an order from a string using same format as print_order()
	istringstream is(line);
	string name, address;
	int data;
	char c;

	//is.get calls that don't get used are to "eat up" formatting commas

	is.get(c);
	while(c != ','){
		name += c;
		is.get(c);
	}
	is.get(c);
	is.get(c);
	while(c != ','){
		address += c;
		is.get(c);
	}

	is >> data;
	Order or(name, address, data);

	for(int i = 0; i < data; ++i){
		string pur_name;
		double unit_price;
		int count;
		
		is.get(c);
		while(c != ','){
			pur_name += c;
			is.get(c);
		}
		is >> unit_price;
		is.get(c);
		is >> count;

		or.purchases.push_back(Purchase(pur_name, unit_price, count));
		c = ' ';
	}

	return or;
}

list<Order> list_read(string filename){ //Creates a list of orders from a file
	list<Order> l;
	ifstream is(filename.c_str());
	string line;
	while(getline(is, line))
		l.push_back(read_order(line));
	return l;
}

void list_write(list<Order> l, string filename){ //Writes a file from a list of orders
	ofstream os(filename.c_str());
	list<Order>::iterator check = l.end();
	--check; //Check points to the second to last list element; this way there will not be a trailing empty line, which would create issues
	for(list<Order>::iterator iter = l.begin(); iter != l.end(); ++iter){
		os << print_order(*iter);
		if(iter != check)
			os << endl;
	}
}

vector<Order> vect_read(string filename){ //Creates a vector of orders from a file
	vector<Order> v;
	ifstream is(filename.c_str());
	string line;
	while(getline(is, line))
		v.push_back(read_order(line));
	return v;
}

void vect_write (vector<Order>& v, string filename){ //Writes a file from a vector
	ofstream os(filename.c_str());
	vector<Order>::iterator check = v.end();
	--check; //See list_write comment on check
	for(vector<Order>::iterator iter = v.begin(); iter < v.end(); ++iter){
		os << print_order(*iter);
		if(iter != check)
			os << endl;
	}
}

int main() {
	/*
		Creates a vector<Order> from user input, writes to a file, creates another vector from that file, sorts by name, and writes another file
		Creates a list<Order> from user input, writes to a third file, creates another list from the second file, sorts by address, and writes to fourth file
		Creates another vector<Order> from the fourth file, merges the two vectors, then writes to a fifth file
	*/
	cout << "Making Vector" << endl;
	vect_write(make_vector(10), "file1.txt");
	vector<Order> v1 = vect_read("file1.txt");
	sort(v1.begin(), v1.end(), cmp_name);
	vect_write(v1, "file2.txt");

	cout << "Making List" << endl;
	list_write(make_list(10), "file3.txt");
	list<Order> l = list_read("file3.txt");
	l.sort(cmp_add);
	list_write(l, "file4.txt");

	vector<Order> v2 = vect_read("file4.txt");
	sort(v2.begin(), v2.end(), cmp_name);
	
	vector<Order> v3(20);
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), cmp_name);
	vect_write(v3, "file5.txt");
}