#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
	int val;
	struct Node* next;
} Node;

Node* head;
Node* tail;

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
		//sleep(1);
		current = current->next;
	}
	printf("\n");
	return;
}

void delete(int x) {
	Node* current = head->next;
	while(current != head) {
		if (current->next->val == x) {
			printf("%d ", current->next->val);
			Node * temp = current->next;
			free(current->next);
			current->next = temp->next;
		}
		current = current->next;
	}
	return;
}

int main() {
	tail = head;
	int x;
	scanf("%d", &x);
	while(x != -1) {
		insert(x);
		scanf("%d", &x);
	}
	tail->next = head;
//	traverse();
	printf("Delete what? ");
	scanf("%d", &x);
	delete(x);
	traverse();
	return 0;
}
