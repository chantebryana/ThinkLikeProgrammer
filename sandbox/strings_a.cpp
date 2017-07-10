#include <iostream>
#include <string>
using namespace std;

int main () {

	studentRecord studentRecord; 
	studentRecord.setId(01);
	studentRecord.setGrade(97);
	studentRecord.setName("Bob");
	cout << studentRecord.getId() << " " << studentRecord.getGrade() << " " << studentRecord.getName() << "\n";
   return 0;
}

