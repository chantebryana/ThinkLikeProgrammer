// TLAP chaper 4 Linked Lists exercise exploration

// p 101 build a list of nodes
struct listNode {		// struct used to create linked list is always referred to as a node.
	int studentNum;
	int grade;
	listNode * next;	// self-referencial pointer: illogical but legal; conventionally called "next" or similar.
};
typedef listNode * studentCollection;  // studentCollection is now the same as the struct listNode

// p 102 build sample linked list
studentCollection sc;
listNode * node1 = new listNode;
node1->studentNum = 1001; node1->grade = 78; // or (*node1).studentNum, etc
listNode * node2 = new listNode;
node2->studentNum = 1012; node2->grade = 93;
listNode * node3 = new listNode;
node3->studentNum = 1076; node3->grade = 85;
sc = node1;	// sc is head pointer!
node1->next = node2;
node2->next = node3;
node3->next = NULL;
node1 = node2 = node3 = NULL;	// deference pointers from heap memory!

