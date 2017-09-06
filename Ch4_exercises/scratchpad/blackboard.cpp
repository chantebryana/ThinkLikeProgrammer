// qsort integration pseudocode!

qsort(array, SIZE, sizeof(node *), compare_node;

int compare_node(const void * void_a, const void * void_b) // elements are pulled from array, But values of array are pointers in memory to the same data elements contained in linked list!!!  so i can manipulate/compare ll even though i'm passing array elements.
// node * or node * * ??? perhaps if i'm referencing an element of array, i only need one node * (not ** ) ??
node * prev = (node *)void_a;
node * next = (node *)void_b;

if (prev->data < next->data) {
	return -1;
} else if (prev->data > next->data) {
	return 1;
} else { // prev->data == next->data
	return 0;
}


