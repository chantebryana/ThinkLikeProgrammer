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
  cout << "Hello Terminal\n";
  const int ARRAY_SIZE = 10;
  int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 81, 68};
  for (int i = 0; i <= ARRAY_SIZE; i++) {
    cout << "Unsorted array: " << intArray[i] << "\n";
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
