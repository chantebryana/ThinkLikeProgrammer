#include <iostream> 
using std::cin;
using std::cout;

//commenting
int main () {
  int newLine = 0;
  while (newLine < 5) {
    int hashRepeat = 5;
    while (hashRepeat > 0) {
      cout << "#";
      hashRepeat--;
    }
    cout << "\n";
    newLine++;
  }
  return 0;
} 
