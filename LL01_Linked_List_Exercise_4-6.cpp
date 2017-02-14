// exercie 4-6 in TLaP: Linked Lists
#include <iostream>
#include <cstdlib>

int main () {
	// define charNode struct
	struct charNode {
		char letter;
		charNode * next;
	};
	typedef charNode * seriesOfLetters; // use typedef to simplify readability: shorthand for charNode struct

	seriesOfLetters sol; // declare "head pointer" for later linked list
	// declare nodes of characters which will later be turned into linked list
	charNode * nodeA = new charNode;
	nodeA -> letter = 'a';
	charNode * nodeB = new charNode;
	nodeB -> letter = 'b';
	charNode * nodeC = new charNode;
	nodeC -> letter = 'c';

	sol = nodeA; // head pointer, stack-based pointer
	nodeA -> next = nodeB; // linked list
	nodeB -> next = nodeC; // linked list
	nodeC -> next = NULL; // end of linked list
	nodeA = nodeB = nodeC = NULL; // deallocate heap memory
	
	std::cout << sol -> letter << "\n";
	return 0;
}

