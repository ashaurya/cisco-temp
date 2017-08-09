#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
} Node;

Node* head;
Node* tail;

void insertFirst(int x) {
	Node* current = (Node*) malloc( sizeof(Node) );
	current->val = x;
	current->next = head;
	head = current;
}

void insertLast(int x) {
	if (head == NULL) {
		head = (Node*) malloc( sizeof(Node));
		head->val = x;
		tail = head;
		return;
	}
	tail->next = (Node*) malloc( sizeof(Node) );
	tail->next->val = x;
	tail = tail->next;
}

void traverse() {
	if (head == NULL)
		return;
	Node* current = head;
	while(current != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
	return;
}

int main() {
	tail = head;
	int x;
	scanf("%d", &x);
	while(x != -1) {
		insertFirst(x);
		scanf("%d", &x);
	}
	traverse();
	return 0;
}
