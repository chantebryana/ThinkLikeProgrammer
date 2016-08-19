#include <iostream> 
using std::cin;
using std::cout;

int main () {
  int newLine = 5;
  while (newLine > 0) {
    int hashRepeat = 5;
    while (hashRepeat > 0) {
      cout << "#";
      hashRepeat--;
    }
    cout << "\n";
    newLine--;
  }
  return 0;
} 
