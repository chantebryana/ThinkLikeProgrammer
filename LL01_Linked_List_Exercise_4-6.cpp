// exercie 4-6 in TLaP: Linked Lists
#include <iostream>
#include <cstdlib>

// define charNode struct
struct charNode {
	char letter;
	charNode * next;
};

//call some functions, which are fleshed out below main()
void printNode(charNode * lhpVar);
char characterAt(charNode * lhpVar, int index);

//add new node to linked list
charNode * addRecord(charNode * lhpVar, char letterVar) { // pass address of lhpVar because I'm directly editing this variable
	charNode * newNode = new charNode; // declare newNode and point to heap memory
	newNode -> letter = letterVar; // assign the new record
	newNode -> next = lhpVar; // link newNode to existing linked list head pointer
	lhpVar = newNode; // point head pointer to new beginning of linked list
	newNode = NULL; // deallocate heap memory
	return lhpVar;
}

charNode * appendRecord(charNode * lhpVar, char letterVar) { // append char at END of linked list
	charNode * newNode = new charNode; // declare newNode and point to heap memory
	newNode -> letter = letterVar; // assign char to new heap record
	while(lhpVar -> next == NULL) { // at the end of the linked list, which is null
		lhpVar -> next = newNode; // end of lhpVar to newNode
		newNode -> next = NULL;	// assign NULL to newNode to make sure new ending knows not to point to anything
		newNode = NULL; // deallocate heap memory
	}
	return lhpVar;
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
	
	int indexChar = 2; // index to pass to characterAt func
	
	std::cout << "Original linked list........";
	printNode(lettersHeadPointer);
	std::cout << "Character found at index " << indexChar << ".." << characterAt(lettersHeadPointer, indexChar) << "\n";
	lettersHeadPointer = addRecord(lettersHeadPointer, 'g');
	std::cout << "Newly added-onto list.......";
	printNode(lettersHeadPointer);
	lettersHeadPointer = appendRecord(lettersHeadPointer, 'q');
	std::cout << "Newly appended list.........";
	printNode(lettersHeadPointer);
	
	return 0;
}


// http://www.cprogramming.com/tutorial/lesson15.html 
// function to print all of the nodes in charNode * lettersHeadPointer
void printNode(charNode * lhpVar) {
	while (lhpVar != 0) {
		std::cout << lhpVar -> letter << " ";
		lhpVar = lhpVar -> next;
	}
	std::cout << "\n";
}

// http://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
// return Nth node from linked list: where's my character at?!
char characterAt(charNode * lhpVar, int index) {
	int count = 0; // manually iterated index
	while (lhpVar != 0) { // if we haven't gotten to the end of the linked list
		if (count == index) { // if manual count equals index passed as arg
			return lhpVar -> letter; // return the node at that manual count
		}
		count++; // if there's no match, keep iterating the manual count
		lhpVar = lhpVar -> next; // iterate the node we're pointing at
	}
	return 'z'; // return 'z' if the manual count never matched the passed index
}



