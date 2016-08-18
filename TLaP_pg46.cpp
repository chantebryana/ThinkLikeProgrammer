#include <iostream> 
using std::cin;
using std::cout;

int main () {
  int newLine = 0;
  while (newLine < 5) {
    int hashRepeat = 5;
    while (hashRepeat > 0) {
      cout << "#\n";
      hashRepeat--;
    }
    newLine++;
  }
  return 0;
} 
