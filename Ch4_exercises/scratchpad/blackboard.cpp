void print_array(int * * array, const int a_length) {
	std::cout << std::endl << "address_of[i]: " << std::endl;
	for (int i = 0; i < a_length; i++) {
		std::cout << array[i] << std::endl;
	}
}

//	===	===	===
// raw code: 
	std::cout << "address_of[i]: " << std::endl;
	for (int i = 0; i < SOME_NUM; i++) {
		std::cout << address_of[i] << std::endl;
	}

// ===	===	===
// compare print_array function against node_address_to_array function: what are the layers of memory and pointers?

struct node {
	int data;
	node * next;
} ;
node * root = new node;
int * * address_of = new int * [SOME_NUM];

node_address_to_array(root, address_of, SOME_NUM);
//DON'T WORK: 
print_array(* address_of, SOME_NUM);
//DOES WORK: 
print_array(address_of, SOME_NUM);

void node_address_to_array (node * head, int * * array, const int a_length) {
	node * temp = head;
	for (int i = 0; i < a_length; i++) {
		array[i] = &temp->data;
		// if linked list ends before array loop, break out: 
		if (temp->next == NULL) {break;}
		temp = temp->next; // or (*temp).next
	}
	temp = NULL;
}

//DON'T WORK: 
void print_array(int * array, const int a_length) {
	std::cout << std::endl << "address_of[i]: " << std::endl;
	for (int i = 0; i < a_length; i++) {
		std::cout << array[i] << std::endl;
	}
}
//DOES WORK: 
void print_array(int * * array, const int a_length) {
	std::cout << std::endl << "address_of[i]: " << std::endl;
	for (int i = 0; i < a_length; i++) {
		std::cout << array[i] << std::endl;
	}
}

// ===	===	===
// 'standard' print array funciton (from qsort.cpp)
int int_array[ARRAY_SIZE] = {5, 111, -86, 84};
print_int_array(int_array, ARRAY_SIZE);

void print_int_array (int * a, const int a_lgth) {
	for (int i = 0; i < a_lgth; i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}



//===	===	===

void printStrs(int count, const char** pointer)
{
  for(int i = 0; i < count; ++i)
    cout << pointer[i];
}

int main()
{
  const char* a = "This is one string";
  const char* b = "This is another";

  const char* ptrs[2] = {a,b};

  printStrs( 2 , ptrs );  // we're not giving it a string, we're giving it a pointer to an array of strings
}
