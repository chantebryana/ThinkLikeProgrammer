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
  iSecret = rand() % 990 + 10;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;
  iSecret = rand() % 990 + 10;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;
  iSecret = rand() % 990 + 10;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;
  iSecret = rand() % 990 + 10;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;
  iSecret = rand() % 990 + 10;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;
  iSecret = rand() % 990 + 10;
	dec = (float)(iSecret) / 100;
	std::cout << dec << std::endl;

/*
  do {
    printf ("Guess the number (1 to 10): ");
    scanf ("%d",&iGuess);
    if (iSecret<iGuess) puts ("The secret number is lower");
    else if (iSecret>iGuess) puts ("The secret number is higher");
  } while (iSecret!=iGuess);
*/
  puts ("Congratulations, you guessed it!");
  return 0;
}
