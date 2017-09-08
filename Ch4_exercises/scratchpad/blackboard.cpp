// http://www.cplusplus.com/reference/cstdlib/rand/
/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

int coin_toss();
float length_of_race();

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

	// generate timeframe in seconds: 
	float time_sec = length_of_race();
	std::cout << time_sec << std::endl;

  return 0;
}



// who won the race? flip a coin:
int coin_toss() {
	// initialize random seed based on the current time in miliseconds: 
  srand (time(NULL));
	// toss a metaphorical coin and return results: 
	return rand() % 2;
}

// how fast did runners run? some semi-random number between 20.00 and 33.00 seconds:
float length_of_race() {
	// initialize random seed based on the current time in miliseconds: 
  srand (time(NULL));
	// generate random int between 2000 and 3300:
	int i_sec = rand() % 1300 + 2000; 
	// float f_sec = (float)(i_sec) / 100;
	// return f_sec;
	// convert random int into float that more closely resembles seconds time format; return result: 
	return (float)(i_sec) / 100;
};

