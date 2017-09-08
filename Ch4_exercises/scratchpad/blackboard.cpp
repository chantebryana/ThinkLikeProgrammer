// http://www.cplusplus.com/reference/cstdlib/rand/
/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

int coin_toss();

int main ()
{
/*
  int iSecret, iGuess;

  // initialize random seed: 
  srand (time(NULL));

  // generate secret number between 1 and 10: 
	float dec;
  iSecret = rand() % 1300 + 2000;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;

	iGuess = rand() % 2;
	std::cout << iGuess << std::endl;
*/
	// flip a coin then print out the results:
	int coin = coin_toss();
	std::cout << coin << std::endl;

  return 0;
}



int coin_toss() {
	// initialize random seed based on the current time in miliseconds: 
  srand (time(NULL));
	// toss that coin!
	// int coin = rand() % 2;
	// return results of coin toss:
	// return coin;
	// toss a metaphorical coin and return results: 
	return rand() % 2;
}
/*
float length_of_race() {
	// initialize random seed based on the current time in miliseconds: 
  srand (time(NULL));
	
};
*/
