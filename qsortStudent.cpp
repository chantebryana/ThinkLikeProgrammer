#include <cstdlib>
#include <iostream>
using namespace std;

// comparison func to use with qsort
struct compare (const void * a, const void * b) {
	return ( *(struct *)a - *(struct *)b );
}

int main() {
	// declare and define student struct
	struct student {
		int grade; 
		int studentID;
	};
	// declare and define array size, plus multi-dimensional student array
	// use struct student for student array data type
	const int ARRAY_SIZE = 10;
	student studentArray[ARRAY_SIZE] = {
		 {87, 10001},
		 {28, 10002},
		 {100, 10003},
		 {78, 10004},
		 {84, 10005},
		 {98, 10006},
		 {75, 10007},
		 {70, 10008},
		 {81, 10009},
		 {68, 10010}
	};

	qsort(studentArray, ARRAY_SIZE, sizeof(student), compare);

	cout << "Student grades & IDs: \n";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << studentArray[i].grade << ", " << studentArray[i].studentID << "\n";
	}

	return 0;
}
