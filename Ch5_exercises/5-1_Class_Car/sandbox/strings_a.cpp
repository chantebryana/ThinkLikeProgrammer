#include <iostream>
#include <string>
#include "./strings.h"
using namespace std;

int main () {

	studentRecord studentRecord; 
	studentRecord.setId(01);
	studentRecord.setGrade(97);
	studentRecord.setName("Bob");
	cout << studentRecord.getId() << " " << studentRecord.getGrade() << " " << studentRecord.getName() << "\n";
//	string test = "just testing";
	//cout << test << "\n";
   return 0;
}

