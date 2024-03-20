#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
Insert data to tail of linked list
*/

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

void Insert(Node** phead, int num) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = num;

	temp->pointer = NULL;

	if (*phead == NULL) {
		*phead = temp;

		return;
	}

	Node* current = *phead;

	while (current->pointer != NULL) {
		current = current->pointer;
	}

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

int main() {
	Node* head = NULL;

	printf("Enter the length of linked list : ");

	int length, data;

	scanf("%d", &length);

	for (int i = 0; i < length; i++) {
		printf("Enter the data : ");

		scanf("%d", &data);

		Insert(&head, data);

		Print(head);
	}
}

/*

* When there is a circular part in the linked list,
* code that outputs the data of the node that is a few steps away from the head.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

void Insert(Node** phead, int num, int i, int N, int V) {
	Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = num;

	temp->pointer = NULL;

	if (*phead == NULL) {
		*phead = temp;

		return;
	}

	Node* current = *phead;

	while (current->pointer != NULL) {
		current = current->pointer;
	}

	current->pointer = temp;

	if (i == N) {
		Node* vNode = *phead;

		for (int n = 1; n < V; n++) {
			vNode = vNode->pointer;
		}

		temp->pointer = vNode;
	}
}

void Print(Node* head, int question) {
	for (int i = 0; i < question; i++) {
		head = head->pointer;
	}

	printf("Data of node : %d\n", head->data);
}

int main() {
	Node* head = NULL;

	//N : length of the linked list.
	//M : numbers of question.
	//V : node number linked with last node.

	int N, M, V;

	int num;

	printf("Enter the N M V : ");

	scanf("%d %d %d", &N, &M, &V);


	printf("Enter the data to be input into each node\n");

	for (int i = 1; i <= N; i++) {

		scanf("%d", &num);

		Insert(&head, num, i, N, V);
	}

	for (int i = 0; i < M; i++) {
		printf("Enter the number : ");

		int question;

		scanf("%d", &question);

		Print(head, question);
	}
}
*/