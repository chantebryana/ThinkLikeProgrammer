#include <iostream> // cin, cout
#include <cstdlib>

//int * insertion_sort(int * a, const int a_lgth);
void insertion_sort(int * * a, const int a_lgth);
void print_int_array (int * a, const int a_lgth);

int main () {
	const int ARRAY_SIZE = 9;
	int int_array[ARRAY_SIZE] = {6, 7, 2, 1, 9, 8, 3, 1, 5};
	int * p_int_array = new int[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE-1; i++) {
		p_int_array[i] = int_array[i];
		std::cout << p_int_array[i] << " ";
	}
	std::cout << std::endl;
	//insertion_sort(int_array, ARRAY_SIZE);
	insertion_sort(& p_int_array, ARRAY_SIZE);
	print_int_array(p_int_array, ARRAY_SIZE);

	return 0;
}



// sort recently-dealt hand of cards in a pitch game:
// int * insertion_sort(int * a, const int a_lgth) {
void insertion_sort(int * * a, const int a_lgth) {
	int start = 0;
	int end = a_lgth-1;
	// pass over entire deck of cards, excluding the very first card: 
	// (iterate over entire array, beginning at i = 1) :
	for (int i = start + 1; i <= end; i++) {
		// with j starting at i, loop decrements j so long as we haven't reached the lower end of the array (start), and haven't yet found the right stopping point for this new value: 
	//CE: (what if the values are the same? i suppose a[j-1] >= a[j] could work. or, actually, if the values are the same, then the new value just stays in front, sitting behind the other value that's higher than it: that way, unnecessary extra work isn't done to sort a value behind its equal: it just sits before it):
		for (int j = i; j > start && (* a)[j-1] > (* a)[j]; j--) {
			int * temp = new int[1];
			temp[0] = (* a)[j-1];
			(* a)[j-1] = (* a)[j];
			(* a)[j] = temp[0];
		}
	}
	// deallocate something? --> it doesn't look like it
	// return something? --> the array, probably: 
	//return a; // i think
}

void print_int_array (int * a, const int a_lgth) {
	for (int i = 0; i < a_lgth; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
};
