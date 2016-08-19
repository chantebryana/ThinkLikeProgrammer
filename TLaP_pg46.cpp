#include <iostream> 
using std::cin;
using std::cout;

int main () {
  int newLine = 5;
  while (newLine > 0) {
    int hashRepeat = 0;
    int comparison = 5;
    while (comparison > 0) {
      cout << "#";
      hashRepeat++;
      comparison = newLine - hashRepeat;
    }
    cout << "\n";
    newLine--;
  }
  return 0;
} 
