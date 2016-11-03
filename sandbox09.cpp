#include <iostream>
#include <cstdio>
using namespace std;

void func(void(* f)(int));

void print(int x) {
	printf("%d\n", x);
}

func(print);

int main () {
	void func (void (*f)(int)) {
		for (int counter = 0; counter < 5; counter++) {
			(*f)(counter);
		}
	}
	return 0;
}
