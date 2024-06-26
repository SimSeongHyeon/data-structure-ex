#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

//Insert the data to head of linked list
Node* Insert(Node* head, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	if (head == NULL) {
		temp->pointer = NULL;
	}
	else {
		temp->pointer = head;
	}

	head = temp;

	return head;
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

		head = Insert(head, data);

		Print(head);
	}
}