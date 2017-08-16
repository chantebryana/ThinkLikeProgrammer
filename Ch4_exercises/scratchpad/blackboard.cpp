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

int * address_of_0 = new int;
int * address_of_1 = new int;
int * address_of_2 = new int;
int * address_of_3 = new int;
node * temp = root;

address_of_0 = &temp->data;
temp = temp->next;
address_of_1 = &temp->data;
temp = temp->next;
address_of_2 = &temp->data;
temp = temp->next;
address_of_3 = &temp->data;
temp = temp->next;

std::cout << "address_of_x: " std::endl;
std::cout << address_of_0 << " " << std::endl;
std::cout << address_of_1 << " " << std::endl;
std::cout << address_of_2 << " " << std::endl;
std::cout << address_of_3 << " " << std::endl;

temp = NULL;
delete address_of_0;
delete address_of_1;
delete address_of_2;
delete address_of_3;
