#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

class Vehicle {
	public: 
		vehicle_record();
		vehicle_record(string new_mfgr, string new_model, int new_year);
		string get_mfgr();
		void set_mfgr(string new_mfgr);
		string get_model();
		void set_model(string new_model);
		int get_year();
		void set_year(int new_year);
	private: 
		string _mfgr;
		string _model;
		int _year;
};

void Vehicle::set_mfgr(string mfgr_name) {
	_mfgr = mfgr_name;
}

int main() {
	Vehicle car;
	car.set_mfgr("Ford");
	cout << car.get_mfgr(); << "\n";
	return 0;
}



//[ [mfgr => "Ford", model => "Taurus", year => 1999], [mfgr => "Ford", model => "Crown Victoria", year => 2008], [mfgr => "Jeep", model => "Liberty Sport", year => 2008] ]
