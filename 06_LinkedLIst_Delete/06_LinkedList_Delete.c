#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

void Insert(Node** phead, int data, int index) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	if (index == 1) {
		temp->pointer = *phead;

		*phead = temp;

		return;
	}

	Node* current = *phead;

	for (int i = 0; i < index - 2; i++) {
		current = current->pointer;
	}

	temp->pointer = current->pointer;

	current->pointer = temp;
}

void Print(Node* head) {
	printf("List : ");

	while (head != NULL) {
		printf("%d ", head->data);

		head = head->pointer;
	}

	printf("\n");
}

void Delete(Node** phead, int index) {
	Node* temp = *phead;

	if (index == 1) {
		*phead = temp->pointer;

		free(temp);

		return;
	}

	for (int i = 0; i < index - 2; i++) {
		temp = temp->pointer;
	}

	Node* current = temp->pointer;

	temp->pointer = current->pointer;

	free(current);
}

int main() {
	Node* head = NULL;

	int length;
	int data;
	int index;

	printf("Enter the length of linked list : ");
	scanf("%d", &length);

	for (int i = 0; i < length; i++) {
		printf("Enter the data and index : ");
		scanf("%d %d", &data, &index);

		Insert(&head, data, index);

		Print(head);			
	}

	printf("Enter the index to delete : ");

	scanf("%d", &index);

	Delete(&head, index);

	Print(head);
}