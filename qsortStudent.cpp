#include <cstdlib>
#include <iostream>
using namespace std;



int main() {
	// declare and define student struct
	struct student {
		int grade; 
		int studentID;
		string name;
	};
	// declare and define array size, plus multi-dimensional student array
	// use struct student for student array data type
	const int ARRAY_SIZE = 10;
	student studentArray[ARRAY_SIZE] = {
		 {87, 10001, "Fred"},
		 {28, 10002, "Tom"},
		 {100, 10003, "Alistair"},
		 {78, 10004, "Sasha"},
		 {84, 10005, "Erin"},
		 {98, 10006, "Belinda"},
		 {75, 10007, "Leslie"},
		 {70, 10008, "Candy"},
		 {81, 10009, "Aretha"},
		 {68, 10010, "Veronica"}
	};

	return 0;
}
