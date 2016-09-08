#include <iostream>
using std::cin;
using std::cout;
/*
int compareFunc(const void * voidA, const void * voidB) {
  int * intA = (int *)(voidA);
  int * intB = (int *)(voidB);
  return *intA - *intB;
}
*/
int main () {
  cout << "Hello Terminal\n"; //playing around
  cout << "Unsorted array: \n"; //print elements of unsorted array
  const int ARRAY_SIZE = 10; //create constant for more generic code
  int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68}; //create unsorted array: what a mess!
  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << intArray[i] << "\n"; //print iterated elements of unsorted array
  }

/*
  qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
  for (int i = 0; i <= ARRAY_SIZE; i++) {
    cout << "Sorted array: " << intArray[i] << "\n";
    return 0;
  }
*/
return 0;
}
