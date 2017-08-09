#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* next;
} Node;

Node* head;
Node* tail;
Node* _head;
Node* _tail;

void insert(int x) {
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

void _traverse() {
	if (_head == NULL)
		return;
	Node* current = _head;
	while(current != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
	return;
}

void reverse() {
	if (head == NULL)
		return;

	Node* current = head;
	Node* _current;

	while(current != NULL) {
		_current = (Node*) malloc(sizeof(Node));
		_current->val = current->val;
		_current->next = _head;
		_head = _current;
		current = current->next;
	}
}

int main() {
	tail = head;
	int x;
	scanf("%d", &x);
	while(x != -1) {
		insert(x);
		scanf("%d", &x);
	}
	reverse();
	printf("Original List: ");
	traverse();
	printf("Reversed List: ");
	_traverse();
	return 0;
}
