#include <iostream> 
using std::cin;
using std::cout;

int hashFunc (int newLine) {
  int hashRepeat = 0;
  int comparison = 5;
  while (comparison > 0) {
    cout << "#";
    hashRepeat++;
    comparison = newLine - hashRepeat;
  }
}

int main () {
  int newLine = 5;
  while (newLine > 0) {
    hashFunc (newLine);
    cout << "\n";
    newLine--;
  }
  return 0;
} 
