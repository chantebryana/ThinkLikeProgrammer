//#include <string>
#include <ctime>
#include "./vehicle.h"

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

// next two functions: exercise 5-2 -- another supporting method: 
int Vehicle::current_year() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	return year;
}

int Vehicle::age_of_vehicle() {
	//int age_of_vehicle = current_year() - _year;
	//return age_of_vehicle;
	return current_year() - _year;
}


