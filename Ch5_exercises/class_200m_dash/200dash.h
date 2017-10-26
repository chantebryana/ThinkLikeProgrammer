#include <iostream> // cin, cout
#include <cstdlib>
#include <string> // string

class Run {
	public: 
		Run();
		Run(std::string new_name, int new_rank, float new_time);
		std::string get_name();
		void set_name(std::string new_name);
		int get_rank();
		void set_rank(int new_rank);
		float get_time();
		void set_time(float new_time);
		std::string output_string();
	private: 
		std::string _name;
		int _rank;
		float _time;
} ;

class Runs {
	private: 
		struct run_node {
			Run run_data;
			run_node * next;
		} ;
	public: 
		Runs();
		~Runs();
		void add_run_data(Run new_run_data);
		Run retreive_runner(std::string name);
	private: 
		run_node * _head;
		void delete_runner(run_node * & list_ptr); 
} ;


