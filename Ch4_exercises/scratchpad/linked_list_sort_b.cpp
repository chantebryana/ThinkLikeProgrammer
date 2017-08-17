#include <iostream> // cin, cout
#include <cstdlib> // qsort plus much more

struct node {
	int data;
	node * next;
} ;

void process_user_input (node * * head, int new_data);
void insert_new_at_front(node * * head, int user_input);
void print_node(node * head);
void print_address(node * head);
void deallocate(node * * head);

int main () {
	node * root = new node;
	root->data = 7;
	root->next = NULL;

	print_node(root);

	int user_input;
	std::cout << "__ADD DATA TO LINKED LIST \'ROOT\'__" << std::endl;
	std::cout << "enter a series of non-zero integers; enter a char to quit: " << std::endl;
	process_user_input(& root, user_input);
	print_node(root);
	print_address(root);
	//int * address_of = new int;
	//address_of = (& root->data);
	//std::cout << "address_of: " << address_of << std::endl;
	//delete address_of;
/*
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

	std::cout << "address_of_x: " << std::endl;
	std::cout << address_of_0 << " " << std::endl;
	std::cout << address_of_1 << " " << std::endl;
	std::cout << address_of_2 << " " << std::endl;
	std::cout << address_of_3 << " " << std::endl;

	temp = NULL;
	delete address_of_0;
	delete address_of_1;
	delete address_of_2;
	delete address_of_3;
*/

const int SOME_NUM = 4;
int ** address_of = new int*[SOME_NUM];
//int address_of[SOME_NUM];
//int brief;
int * brief = new int;
node * temp = root;

//(*temp).data
//temp->data

for (int i = 0; i < SOME_NUM; i ++) {
	address_of[i] = &temp->data;
	//brief = &temp->data;
	//address_of[i] = brief;
	//address_of[i] = i;
	temp = temp->next;
	//if (temp->next == NULL) {break;}
}

//std::cout << "brief: " << brief << std::endl;

std::cout << "address_of[i]: " << std::endl;
for (int i = 0; i < SOME_NUM; i++) {
	std::cout << address_of[i] << std::endl;
}

temp = NULL;
delete brief;
delete[] address_of;


/*
	node * temp = root;
	const int SOME_NUM = 7;
	int * node_address = new int [SOME_NUM];
	for (int i = 0; i < SOME_NUM; i++) {
		node_address[i] = (temp);
		temp = temp->next;
		if (temp == NULL) {break;}
	}
	temp = NULL;

	for (int i = 0; i < SOME_NUM; i++) {
		std::cout << node_address[i] << " ";
	}
	std::cout << std::endl;
*/
	deallocate(& root);
	return 0;
}







void process_user_input(node * * head, int new_data) {
	int quit = 0;
	while (!quit) {
		std::cin >> new_data;
		if (new_data != 0) {
			insert_new_at_front(head, new_data);
		} else if (new_data == 0) {
			std::cout << "all done!" << std::endl;
			quit = 1;
		} else {
			std::cout << "input error" << std::endl;
			quit = 1;
		}
	}
}

void insert_new_at_front(node * * head, int user_input) {
	node * temp = new node;
	temp->data = user_input;
	temp->next = * head;
	* head = temp;
	temp = NULL;
}

void print_node(node * head) {
	if (head != NULL) {
		std::cout << "data: ";
		while (head->next != 0) {
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << head->data << std::endl;
	}
}

void print_address(node * head) {
	if (head != NULL) {
		std::cout << "data addresses: " << std::endl;
		while (head->next != 0) {
			std::cout << (& head->data) << std::endl;
			head = head->next;
		}
		std::cout << (& head) << std::endl;
	}
}

void deallocate(node * * head) {
	while (* head) {
		node * temp;
		temp = * head;
		* head = (* head)->next;
		delete temp;
	}
}
