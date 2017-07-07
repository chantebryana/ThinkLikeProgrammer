// from https://www.tutorialspoint.com/cplusplus/cpp_strings.htm
// exploring strings to better understand how they work 
// for use in 5-1_Class_Car_A.cpp exercise

#include <iostream>
#include <string>
using namespace std;

struct student {
	int studentID; 
	string name;
};

int main () {
	const int ARRAY_SIZE = 3;
	student studentArray[ARRAY_SIZE] = {
		{01, "Rachel"}, 
		{02, "Wick"}, 
		{03, "Borne"}
	};
	cout << studentArray[0].name << "\n";

   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total lenghth of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   return 0;
}

