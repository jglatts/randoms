#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

int main(int argc, char* argv[]) {
	test_linked_list();
	/*
	srand(time(0));
	int size = get_input();
	print_nodes(set_nodes(size));
	*/
	return 0;
}

int get_input() {
	int size = 15;	
	printf("Default Size: %d\nHow many nodes?", size);
	scanf("%d", &size);
	printf("Current Size: %d", size);
	return size;
}

Node* set_nodes(int size) {
	Node* root = (Node*)malloc(sizeof(Node));
	Node* current = root;
	root->data = (rand() % size) + 1;
	root->next = NULL;
	for (int i = 0; i < size-1; ++i) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = (rand() % size) + 1;
		current->next = node;
		current = node;
	}
	current->next = NULL;
	return root;
}

void print_nodes(Node* current) {
	int count = 0;
	printf("\n----------------------Printing Linked List----------------------\n");
	while (current != NULL) {
		printf("Node #%d: %d\n", count++, current->data);
		current = current->next;
	}
}

int check_list(Node* node, int i) {
	Node* current = node;
	while (current != NULL) {
		if (current->data == i) return i;
		current = current->next;
	}
	return -1;
}

void test_linked_list() {
	Node* root = (Node*)malloc(sizeof(Node));
	Node* current = root;
	root->data = 0;
	for (int i = 1; i < 10; ++i) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = i;
		current->next = node;
		current = node;
	}
	current->next = NULL;
	print_nodes(root);
	printf("\nIs #5 in the list? : %d", check_list(root, 69));
}