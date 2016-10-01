#include <iostream>
#include <cstdlib>
using namespace std;

//define comparison function for qsort
int compareFunc(const void *voidA, const void *voidB) {
	int *intA = (int *)(voidA);
	int *intB = (int *)(voidB);
	return *intA - *intB;
}

int main () {
	//define student data structure, array
	struct student {
		int grade;
		int studentID;
		string name;
	};
	const int ARRAY_SIZE = 10;
	student studentArray[ARRAY_SIZE] = {
		{87, 101, "Fred"},
		{28, 102, "Tom"},
		{100, 103, "Alistair"},
		{78, 104, "Sasha"},
		{84, 105, "Erin"},
		{98, 106, "Belinda"},
		{75, 107, "Leslie"},
		{70, 108, "Candy"},
		{81, 109, "Aretha"},
		{68, 110, "Veronica"}
	};
	
	//sort the unsorted responses with qsort; use compareFunc defined above 
	//qsort(studentArray, ARRAY_SIZE, sizeof(int), compareFunc);
	
	//practice printing struct array
		int highest = studentArray[0].grade;
		string best = "";
		for (int i = 1; i < ARRAY_SIZE; i++) {
			if (studentArray[i].grade > highest) 
				highest = studentArray[i].grade;
				best = studentArray[i].name;
		} 
		cout << "Best student: " << best << "; " << highest << " points\n";

	return 0;
}