#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

void Insert(Node** phead, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	if (*phead == NULL) {
		temp->pointer = NULL;
	}
	else {
		temp->pointer = *phead;
	}

	*phead = temp;
}

void Reverse(Node** phead) {
	Node* prev, * cur, * next;

	prev = NULL;

	cur = *phead;

	while (cur != NULL) {
		next = cur->pointer;

		cur->pointer = prev;

		prev = cur;

		cur = next;
	}

	*phead = prev;
}

void Print(Node* head) {
	printf("List : ");

	while (head != NULL) {
		printf("%d ", head->data);
		head = head->pointer;
	}

	printf("\n");
}

int main() {
	Node* head = NULL;

	int length, data;

	printf("Enter the length of linked list : ");

	scanf("%d", &length);

	for (int i = 0; i < length; i++) {
		printf("Enter the data : ");

		scanf("%d", &data);

		Insert(&head, data);

		Print(head);
	}

	Reverse(&head);

	printf("Resversed ");

	Print(head);
}