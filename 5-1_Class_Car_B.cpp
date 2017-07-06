#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

class Vehicle {
	public: 
		Vehicle();
		Vehicle(int new_year);
		//char get_mfgr();
		//void set_mfgr(char new_mfgr);
		//char get_model();
		//void set_model(char new_model);
		int get_year();
		void set_year(int new_year);
	private: 
		//char _mfgr;
		//char _model;
		int _year;
};

Vehicle::Vehicle() {
	set_year(0);
}

Vehicle::Vehicle(int new_year) {
	set_year(new_year);
};

void Vehicle::set_year(char new_year) {
	_year = new_year;
}

char Vehicle::get_year() {
	return _year;
}

int main() {
	Vehicle car;
	car.set_year(1999);
	cout << car.get_year() << "\n";
	return 0;
}


