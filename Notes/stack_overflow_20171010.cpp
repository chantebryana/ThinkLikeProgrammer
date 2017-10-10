// https://stackoverflow.com/questions/46673868/c-summing-numbers-from-a-previously-printed-list
// attempting to answer this question, but too many bugs to work with I think

#include <iostream>

using namespace std;

int main()
{
    int smallernumber, largernumber, counter, i, IsPrime;
    int sum = 0;


    cout << "Welcome to the Prime Number calculator!  This program will"
        "\ncalculate prime numbers between two values that you'll enter.\n Please enter the the smaller of two values: ";
    cin >> smallernumber;
    cout << "\nPlease enter the larger value ";
    cin >> largernumber;

    for (counter = smallernumber; counter <= largernumber; counter++) {
        IsPrime = 0;

        for (i = smallernumber; i < counter; i++) {

            if (counter % i == 0) {
                IsPrime = 1;


            }
        }

        if (IsPrime == 0 && counter != 1)
						//sum += counter;
            cout << counter << " ";
						//sum += counter;


    }
    //for (counter = 2; IsPrime == 0 && counter != 1; counter++) {
		//for (counter = 2; counter <= largernumber; counter++) {
			//if (IsPrime == 0 && counter != 1 ) {
        //sum += counter;
			//}
    //}
    cout << "\nthe sum of the prime numbers is: " << sum << endl;

}
