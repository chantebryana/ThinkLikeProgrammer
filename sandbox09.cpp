#include <iostream>
#include <cstdio>
using namespace std;

void func(void(* f)(int));

void print(int x) {
	printf("%d\n", x);
}

int main () {
	char y[] = "printing";
	func(print);	
	return 0;
}
