#include <string> 

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
		// exercise 5-2 -- another supporting method: 
		int age_of_vehicle();
	private: 
		std::string _mfgr;
		std::string _model;
		int _year;
		// exercise 5-2 -- private method for supporting method: 
		int current_year();
};

