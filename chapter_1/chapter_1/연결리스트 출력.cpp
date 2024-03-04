#include <iostream>
using namespace std;

struct node {
	int key;
	node* next;
};

node* head = nullptr;
node* tail = nullptr;

void insert_node(int n) {
	node* new_node = new node;
	new_node->key = n;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
}

int delete_node() {
	node* nd;
	int r;
	if (head == NULL) {
		return -1;
	}
	nd = head;
	head = head->next;
	if (head == NULL) {
		tail = NULL;
	}
	r = nd->key;
	free(nd);
	return r;
}

void print_list(node* from) {
	node* nd;
	nd = from;
	while (nd != NULL) {
		cout << nd->key << " ";
		nd = nd->next;
	}
}

void print_list2(node* from) {
	if (from == NULL) {
		return;
	}
	cout << from->key << " ";
	print_list2(from->next);
}

void reverse_print(node* from) {
	if (from == NULL) {
		return;
	}
	reverse_print(from->next);
	cout << from->key << " ";
}

int main() {
	return 0;
}