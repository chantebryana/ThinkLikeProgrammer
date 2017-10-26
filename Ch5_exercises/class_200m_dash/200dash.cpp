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
