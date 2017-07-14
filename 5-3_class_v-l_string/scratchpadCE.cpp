#include <iostream>
#include <cstdlib>

int age_of_car (int * pnow_yr, int * pcar_yr) {
	return * pnow_yr - * pcar_yr;
}

int main () {
	int car_year = 1999;
	int now_year = 2017;
	int * pcar_year;
	int * pnow_year;
	pcar_year = & car_year;
	pnow_year = & now_year;
	std::cout << pnow_year << " minus " << pcar_year << " equals " << pnow_year - pcar_year << std::endl;

	std::cout << age_of_car(pnow_year, pcar_year) << std::endl;
//	std::cout << "Age of car: " << * pnow_year - * pcar_year << " years old" << std::endl;

	return 0;
}
