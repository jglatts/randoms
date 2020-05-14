#include <stdio.h>
#include "SupMane.h"

DankList::DankList() { 
	head = NULL;
	tail = NULL;
}

void DankList::add(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = NULL;
	if (head == NULL) {
		head = tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

void DankList::print() {
	Node* current = head;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

void DankList::testList() {
	DankList list;
	list.add(5);
	list.add(5);
	list.add(5);
	list.add(69);
	list.add(5);
	list.add(5);
	list.print();
}
