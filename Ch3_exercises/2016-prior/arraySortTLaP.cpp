#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

int compareFunc(const void * voidA, const void * voidB) {
  int * intA = (int *)(voidA);
  int * intB = (int *)(voidB);
  return *intA - *intB;
}

int main () {
  cout << "Hello Terminal\n"; //playing around
  cout << "Unsorted array: "; //print label for  unsorted array elements
  const int ARRAY_SIZE = 10; //create constant for more generic code
  int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68}; //create unsorted array: what a mess!
  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << intArray[i] << " "; //print iterated elements of unsorted array
  }
  cout << "\n"; //new line: separate printouts of unsorted array data from sorted array data

  cout << "Sorted array: ";  //print label for sorted array elements
  qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc); //sort that array: call to compareFunc function at top of page
  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << intArray[i] << " ";
  }
  cout << "\n";
  
return 0;
}
