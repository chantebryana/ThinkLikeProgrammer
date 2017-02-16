// exercie 4-6 in TLaP: Linked Lists
#include <iostream>
#include <cstdlib>

// define charNode struct
struct charNode {
	char letter;
	charNode * next;
};

int main () {
	charNode * lettersHeadPointer; // declare "head pointer" for later linked list

	// declare nodes of characters which will later be turned into linked list
	charNode * nodeA = new charNode;
	nodeA -> letter = 'a';
	charNode * nodeB = new charNode;
	nodeB -> letter = 'b';
	charNode * nodeC = new charNode;
	nodeC -> letter = 'c';

	lettersHeadPointer = nodeA; // head pointer, stack-based pointer
	nodeA -> next = nodeB; // linked list
	nodeB -> next = nodeC; // linked list
	nodeC -> next = NULL; // end of linked list
	nodeA = nodeB = nodeC = NULL; // deallocate heap memory
	
	// http://www.cprogramming.com/tutorial/lesson15.html 
	if (lettersHeadPointer != 0) {
		while (lettersHeadPointer -> next != 0) {
			std::cout << lettersHeadPointer -> letter << " ";
			lettersHeadPointer = lettersHeadPointer -> next;
		}
		std::cout << lettersHeadPointer -> letter << "\n";
	}

//	std::cout << lettersHeadPointer -> letter << "\n";
	return 0;
}

