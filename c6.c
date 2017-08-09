//Assuming list is ordered

#include <stdlib.h>
#include <stdio.h>

void traverse();
void ntraverse(int);
void insert();

typedef struct Node {
	int val;
	struct Node* next;
} Node;

int size = 0;

Node* head;
Node* tail;

void insert(int x) {
	if(head == NULL) {
		head = (Node*) malloc(sizeof(Node));
		head->val = x;
		tail = head;
		size++;
		return;
	}

	tail->next = (Node*) malloc(sizeof(Node));
	tail->next->val = x;
	tail = tail->next;
	size++;
	return;
}

void traverse() {
	if(head == NULL)
		return;
	Node* current = head;
	while(current != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
	return;
}

void trim() {
	if(head == NULL)
		return;
	Node* current = head;
	while(current != NULL) {
		if(current->next == NULL)
			return;
		else if(current->next->val == current->val)
			current->next = current->next->next;
		else
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
	printf("Original List: ");
	traverse();
	trim();
	traverse();
	return 0;
}
