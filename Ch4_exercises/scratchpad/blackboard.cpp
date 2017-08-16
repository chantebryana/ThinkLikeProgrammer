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

