#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node_ {
	int data;
	struct Node_* pointer;
};
typedef struct Node_ Node;

Node* GetNewNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->pointer = NULL;

	return newNode;
}

void Insert(Node** phead, int index, int data) {
	Node* temp = GetNewNode(data);

	if (index == 1) {
		temp->pointer = *phead;

		*phead = temp;

		return;
	}

	Node* pointing = *phead;

	for (int i = 0; i < index - 2; i++) {
		pointing = pointing->pointer;
	}

	temp->pointer = pointing->pointer;

	pointing->pointer = temp;
}

void Print(Node* p) {
	/*printf("List : ");

	while (head != NULL) {
		printf("%d ", head->data);

		head = head->pointer;
	}

	printf("\n");*/

	//Recursive call
	if (p== NULL) {
		return;
	}

	printf("%d ", p->data);

	Print(p->pointer);
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

	Node* pointing = temp->pointer;

	temp->pointer = pointing->pointer;

	free(pointing);
}

void Reverse(Node** phead) {
	/*Node* pointing, * prev, * next;

	prev = NULL;

	pointing = *phead;

	while (pointing != NULL) {
		next = pointing->pointer;

		pointing->pointer = prev;

		prev = pointing;

		pointing = next;
	}

	*phead = prev;*/

	//Recursive call
	Node* current = *phead;

	if (current->pointer == NULL) {
		return;
	}

	Reverse(&(current->pointer));

	Node* next = current->pointer;

	next->pointer = current;

	current->pointer = NULL;
}

void ReversePrint(Node* head) {
	if (head == NULL) {
		return;
	}

	ReversePrint(head->pointer);
	
	printf("%d ", head->data);
}

int main() {
	Node* head = NULL;

	int length, index, data, command, currentLength;

	currentLength = 0;

	printf("Enter the length of linked list : ");

	scanf("%d", &length);

	do {
		printf("1 : Insert\n");
		printf("2 : Print\n");
		printf("3 : Delete\n");
		printf("4 : Reverse\n");
		printf("5 : ReversePrint\n");
		printf("0 : Exit\n");

		printf("Enter the command : ");

		scanf("%d", &command);

		switch (command) {
			case 1 :
				if (currentLength < length) {
					printf("Enter the index and data : ");

					scanf("%d %d", &index, &data);

					Insert(&head, index, data);

					currentLength++;
				}
				else {
					printf("Linked list is full.\n");
				}
				break;
			
			case 2:
				printf("List : ");
				Print(head);
				printf("\n");
				break;

			case 3:
				printf("Enter the index : ");

				scanf("%d", &index);

				if (index > 0 && index <= currentLength) {
					Delete(&head, index);
					currentLength--;
				}
				else {
					printf("Invalid index.\n");
				}
				break;

			case 4:
				Reverse(&head);
				printf("Reverse complete.\n");
				break;

			case 5:
				break;

			case 0 :
				printf("Shut down programm.\n");
				break;

			default :
				printf("Invaild command.\n");
				break;
		}
	} while (command != 0);
}