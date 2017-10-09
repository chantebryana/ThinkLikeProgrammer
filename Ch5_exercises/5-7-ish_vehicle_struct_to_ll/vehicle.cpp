//#include <string>
#include <ctime>
#include "./vehicle.h"

//
//
//
//
// helper functions for Vehicle class: 
// constructor: 
Vehicle::Vehicle() {
	set_mfgr("");
}

// constructor (vehicle make, model, year to struct): 
Vehicle::Vehicle(std::string new_mfgr, std::string new_model, int new_year) {
	set_mfgr(new_mfgr);
	set_model(new_model);
	set_year(new_year);
};

// set_mfgr:
void Vehicle::set_mfgr(std::string new_mfgr) {
	_mfgr = new_mfgr;
}

// get_mfgr:
std::string Vehicle::get_mfgr() {
	return _mfgr;
}

// set_model:
void Vehicle::set_model(std::string new_model) {
	_model = new_model;
}

// get_model: 
std::string Vehicle::get_model() {
	return _model;
}

// set_year: 
void Vehicle::set_year(int new_year) {
	_year = new_year;
}
// get_year: 
int Vehicle::get_year() {
	return _year;
}

// output struct's contents:
std::string Vehicle::output_string() {
	std::string output_var = "";
	output_var = "\"" + std::to_string(_year) + " " + _mfgr + " " + _model + "\"";
	return output_var;
}

// output age of vehicle (today minus vehicle year):
int Vehicle::current_year() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	return year;
}

// private supporting method for age_of_vehicle:
int Vehicle::age_of_vehicle() {
	//int age_of_vehicle = current_year() - _year;
	//return age_of_vehicle;
	return current_year() - _year;
}

//
//
//
//
// helper functions for Vehicle_hoard class:

// constructor: 
Vehicle_hoard::Vehicle_hoard() {
	_head = NULL;
}

// destructor helper function:
// adapted from Ch4_exercises/linked_list/linked_list.h:
void Vehicle_hoard::deallocate(vehicle_node * * _head) {
	while (* _head) {
		vehicle_node * temp;
		temp = * _head;
		* _head = (* _head)->next;
		delete temp;
	}
}

// destructor: 
Vehicle_hoard::~Vehicle_hoard() {
	deallocate(& _head);
}

// add new node to linked list:
//void Vehicle_hoard::add_record(vehicle_node * new_vehicle){
void Vehicle_hoard::add_record(Vehicle new_vehicle){
	vehicle_node * temp = new vehicle_node;
	temp->vehicle_data = new_vehicle;
	temp->next = _head;
	_head = temp;
}





