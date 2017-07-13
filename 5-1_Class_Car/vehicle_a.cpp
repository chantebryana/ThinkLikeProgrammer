//#include <string>
#include "./vehicle_a.h"

Vehicle::Vehicle() {
	set_mfgr("");
}

Vehicle::Vehicle(std::string new_mfgr, std::string new_model, int new_year) {
	set_mfgr(new_mfgr);
	set_model(new_model);
	set_year(new_year);
};

void Vehicle::set_mfgr(std::string new_mfgr) {
	_mfgr = new_mfgr;
}

std::string Vehicle::get_mfgr() {
	return _mfgr;
}

void Vehicle::set_model(std::string new_model) {
	_model = new_model;
}

std::string Vehicle::get_model() {
	return _model;
}

void Vehicle::set_year(int new_year) {
	_year = new_year;
}

int Vehicle::get_year() {
	return _year;
}

//exercise 5-2 -- supporting method:
std::string Vehicle::output_string() {
	std::string output_var = "";
	output_var = "\"" + std::to_string(_year) + " " + _mfgr + " " + _model + "\"";
	return output_var;
}

