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

int main() {
	return 0;
}