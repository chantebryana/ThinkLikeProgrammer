#include <iostream> 
using std::cin;
using std::cout;

int main () {
  int newLine = 0;
  while (newLine < 5) {
    int hashRepeat = 4;
    while (hashRepeat > 0) {
      cout << "#";
      hashRepeat--;
    }
    cout << "\n";
    newLine++;
  }
  return 0;
} 
