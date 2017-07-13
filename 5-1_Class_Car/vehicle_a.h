#include <string> 
#include <ctime>

int current_year() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	return year;
}

class Vehicle {
	public: 
		Vehicle();
		Vehicle(std::string new_mfgr, std::string new_model, int new_year);
		std::string get_mfgr();
		void set_mfgr(std::string new_mfgr);
		std::string get_model();
		void set_model(std::string new_model);
		int get_year();
		void set_year(int new_year);
		// exercise 5-2 -- supporting method:
		std::string output_string();
		int age_of_car(int current_year);
	private: 
		std::string _mfgr;
		std::string _model;
		int _year;
};
