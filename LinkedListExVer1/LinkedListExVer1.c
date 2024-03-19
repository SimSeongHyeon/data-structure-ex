#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
	int data;
	struct Node* pointer;
};
typedef struct Node_ Node;

Node* head;

//Insert data to linked list
void Insert(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	temp->pointer = head;

	head = temp;
}

//Print numbers of current linked list
void Print() {
	Node* temp = head;

	printf("List : ");

	while (temp != NULL) {
		printf("%d ", temp->data);

		temp = temp->pointer;
	}

	printf("\n");
}

int main() {
	int length, data;

	head = NULL;

	printf("Enter the length of linked list : ");

	scanf("%d", &length);

	for (int i = 0; i < length; i++) {
		printf("Enter the data : ");

		scanf("%d", &data);

		Insert(data);

		Print();
	}
}