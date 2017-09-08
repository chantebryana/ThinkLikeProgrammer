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

	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;

  return 0;
}
