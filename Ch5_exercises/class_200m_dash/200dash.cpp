#include "./200dash.h"

Run::Run() {
	set_name("");
}

Run::Run(std::string new_name, int new_rank, float new_time) {
	set_name(new_name);
	set_rank(new_rank);
	set_time(new_time);
}

void Run::set_name(std::string new_name) {
	_name = new_name;
}

std::string Run::get_name() {
	return _name;
}

int Run::get_rank() {
	return _rank;
}

void Run::set_rank(int new_rank) {
	_rank = new_rank;
}

float Run::get_time() {
	return _time;
}

void Run::set_time(float new_time) {
	_time = new_time;
}

std::string Run::output_string() {
	std::string output_var = "";
	output_var = "\"" + std::to_string(_rank) + " " + _name + " " + std::to_string(_time) + "\"";
	return output_var;
}


//
//
//
//
Runs::Runs() {
	_head = NULL;
}

void Runs::delete_runner(run_node * & list_ptr) { 
	while (_head != NULL) {
		run_node * temp = list_ptr;
		list_ptr = list_ptr->next;
		delete temp;
	}
}

Runs::~Runs() {
	delete_runner(_head);
}

void Runs::add_run_data(Run new_run_data) {
	run_node * temp = new run_node;
	temp->run_data = new_run_data;
	temp->next = _head;
	_head = temp;
}

