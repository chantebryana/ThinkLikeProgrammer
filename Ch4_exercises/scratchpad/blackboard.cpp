// the code I used for std::cin to array[] 

int n;
std::cout << "How many values? ";
std::cin >> n;
int * user_var = new int[n];

for (int i = 0; i < n; i++) {
	std::cout << "Enter non-zero integer for value number " << i+1 << " of " << n << ": ";
	std::cin >> user_var[i];
	if (user_var[i] == 0) {
		break;
	}
}

for (int i = 0; i < n; i++) {
	std::cout << user_var[i] << " ";
}
std::cout << std::endl;


//	===	===	===
// CE: my own bastardized attempt:
// CE: for now, assuming this would appear in main():

const int SOME_NUM = 7; // CE: further define this later, but for now, make array slightly larger than linked list will be
int * node_address = new int[SOME_NUM];
// CE: I'm not sure about the nesting of for() and while()...:
for (int i = 0; i < SOME_NUM; i++) {
	node_address[i] = (& root->data);
	root = root->next;
	if (root == NULL) {break;}
}


//	===	===	===

const int SOME_NUM = 4;
int * address_of = new int[SOME_NUM];
node * temp = root;

for (int i = 0; i < SOME_NUM; i ++) {
	address_of[i] = &temp->data;
	temp = temp->next;
	//if (temp->next == NULL) {break;}
}

std::cout << "address_of[i]: " << std::endl;
for (int i = 0; i < SOME_NUM; i++) {
	std::cout << address_of[i] << std::endl;
}

temp = NULL;
delete[] address_of;

// 
// Assume these are initialized to 0 outside of this snippet
char a[100];
char b[100];
b[0] = 42;  // Some value for us to use

int* a_ptr = (int*)&a[0];    // Store the address of a[0] in a_ptr
int* b_ptr = (int*)&b[0];    // Store the address of b[0] in b_ptr


