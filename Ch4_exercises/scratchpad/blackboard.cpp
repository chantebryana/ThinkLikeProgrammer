// http://www.cplusplus.com/reference/cstdlib/rand/
/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

int main ()
{
  int iSecret, iGuess;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
	float dec;
  iSecret = rand() % 1300 + 2000;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;

	double a = 3.1415926534;
	double b = 2006.0;
	double c = 1.0e-10;

	std::cout.precision(2);

	std::cout << "fixed:\n" << std::fixed;
	std::cout << a << std::endl << b << std::endl << c << std::endl << dec << std::endl << iSecret << std::endl;

  return 0;
}
