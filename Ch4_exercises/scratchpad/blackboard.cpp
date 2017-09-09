// http://www.cplusplus.com/reference/cstdlib/rand/
/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

int coin_toss();
//float length_of_race();
int length_of_race();
float int_to_float(int i_time);

int main () {
	// flip a coin then print out the results:
	int coin = coin_toss();
	std::cout << coin << std::endl;

	// generate random timeframe in seconds, then print it out: 
	// float time_sec = length_of_race();
	// std::cout << time_sec << std::endl;
	int time_sec = length_of_race();
	std::cout << int_to_float(time_sec) << std::endl;

  return 0;
}



// who won the race? flip a coin:
int coin_toss() {
	// initialize random seed based on the current time in miliseconds: 
  srand (time(NULL));
	// toss a metaphorical coin and return results: 
	return rand() % 2;
}
/*
// how fast did runners run? some semi-random number between 20.00 and 33.00 seconds:
// CE this function could return int and i could wait to convert the number to float until i'm ready to display to screen. i could even make a helper function to do that extra step for me only when i need it...
float length_of_race() {
	// initialize random seed based on the current time in miliseconds: 
  srand (time(NULL));
	// generate random int between 2000 and 3300:
	int i_sec = rand() % 1300 + 2000; 
	// convert random int into float that more closely resembles seconds time format; return result: 
	return (float)(i_sec) / 100;
};
*/

// how fast did runners run? some semi-random number between 20.00 and 33.00 seconds (right now, instead of a float, it's an int of range 2000 and 3300):
int length_of_race() {
	// initialize random seed based on the current time in miliseconds: 
	srand (time(NULL));
	// generate random int between 2000 and 3300 (will later get converted to float range of 20.00 [sec] and 33.00 [sec] before it prints out onto screen -- use helper function int_to_float) and return it:
	return rand() % 1300 + 2000;
}

// convert an int 'timeframe' into sexier-looking float (for output purposes):
float int_to_float(int i_time) {
	return (float)(i_time) / 100;
}
