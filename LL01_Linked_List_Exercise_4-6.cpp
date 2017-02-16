// exercie 4-6 in TLaP: Linked Lists
#include <iostream>
#include <cstdlib>

// define charNode struct
struct charNode {
	char letter;
	charNode * next;
};


// http://www.cprogramming.com/tutorial/lesson15.html 
// function to print all of the nodes in charNode * lettersHeadPointer
void printNode(charNode * lhpVar) {
	//if (lhpVar != 0) {
		while (lhpVar -> next != 0) {
			std::cout << lhpVar -> letter << " ";
			lhpVar = lhpVar -> next;
		}
		std::cout << lhpVar -> letter << "\n";
	//}
}

// http://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
// return Nth node from linked list: where's my character at?!
char characterAt(charNode * lhpVar, int index) {
	int count = 0;
	while (lhpVar -> next != 0) {
		if (count == index) {
			return lhpVar -> letter;
		}
		count++;
		lhpVar = lhpVar -> next;
	}
	return 'z';
}

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
	
	printNode(lettersHeadPointer);
	std::cout << characterAt(lettersHeadPointer, 6) << "\n";

//	std::cout << lettersHeadPointer -> letter << "\n";
	return 0;
}

