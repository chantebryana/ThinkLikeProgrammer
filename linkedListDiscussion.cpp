// TLAP chaper 4 Linked Lists exercise exploration

// p 101 build a list of nodes
struct listNode {	
	int studentNum;
	int grade;
	listNode * next;
};
typedef listNode * studentCollection; 

// p 102 build sample linked list
studentCollection sc;
listNode * node1 = new listNode;
node1->studentNum = 1001; node1->grade = 78; 
listNode * node2 = new listNode;
node2->studentNum = 1012; node2->grade = 93;
listNode * node3 = new listNode;
node3->studentNum = 1076; node3->grade = 85;
sc = node1;	// sc is head pointer!
node1->next = node2;
node2->next = node3;
node3->next = NULL;
node1 = node2 = node3 = NULL;	

// p 104 addRecord function
void addRecord(studentCollection& sc, int stuNum, int gr) {	// sc must be dereferenced b/c we're changing it
	listNode * newNode = new listNode;
	newNode->studentNum = stuNum;
	newNode->grade = gr;
	newNode->next = sc;	// step 1: point "next" field to OLD sc
	sc = newNode;			// step 2: reorient sc to new memory location: beginning of newNode
}
addRecord(sc, 1274, 91);

// p 106 averageRecord function
// wow, it would have taken me a million years to figure out the exact syntax for this function!
double averageRecord(studentCollection sc) {
	int count = 0;
	double sum = 0;
	listNode * loopPtr = sc; // loopPtr helps keep track of where we are as we traverse the linked list; kind of like "i" in for loop; doing so not by tracking the position number of the array indexes, but by storing a pointer to the node we are currently processing.  The pointer is like the array index, sort of.
	while (loopPtr != NULL) {
		sum += loopPtr->grade;
		count ++; 
		loopPtr = loopPtr->next;
	}
	double average = sum / count;
	return average;
}
int avg = averageRecord(sc);

