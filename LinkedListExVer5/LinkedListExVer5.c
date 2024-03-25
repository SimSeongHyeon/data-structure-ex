#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
Insert data into specific index of linked list
*/

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

void Insert(Node** phead, int data, int index) {
	Node* toInsertNode = (Node*)malloc(sizeof(Node));

	toInsertNode->data = data;

	toInsertNode->pointer = NULL;

	if (index == 1) {
		toInsertNode->pointer = *phead;

		*phead = toInsertNode;

		return;
	}

	Node* current = *phead;

	for (int i = 0; i < index - 2; i++) {
		current = current->pointer;
	}

	toInsertNode->pointer = current->pointer;

	current->pointer = toInsertNode;
}

void Print(int i, Node* head) {
	printf("%d. List : ", i);

	while (head != NULL) {
		printf("%d ", head->data);

		head = head->pointer;
	}

	printf("\n");
}

int main() {
	Node* head = NULL;

	int length, data, index;

	printf("Enter the length of linked list : ");

	scanf("%d", &length);

	for (int i = 1; i <= length; i++) {
		printf("Enter the data and index : ");

		scanf("%d %d", &data, &index);

		Insert(&head, data, index);

		Print(i, head);
	}
}
