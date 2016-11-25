#include <cstdlib>
#include <iostream>
using namespace std;

// comparison func to use with qsortz
int compare (const void * a, const void * b) {
	return ( *(int *)a - *(int *)b );
}

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

	qsort(studentArray, ARRAY_SIZE, sizeof(student), compare);

	cout << "Student grades: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << studentArray[i].grade << " ";
	}
	cout << "\n";

	cout << "Student IDs: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << studentArray[i].studentID << " ";
	}
	cout << "\n";
/*
	cout << "Student names: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << studentArray[i].name << " ";
	}
	cout << "\n";
*/
	return 0;
}
