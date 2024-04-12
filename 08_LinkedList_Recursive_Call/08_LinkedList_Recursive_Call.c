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

	Node* pointing = temp->pointer;

	temp->pointer = pointing->pointer;

	free(pointing);
}

void Reverse() {

}

void ReversePrint() {

}

int main() {
	Node* head = NULL;

	int length, index, data, command, currentLength;

	currentLength = 0;

	printf("Enter the length of linked list : ");

	scanf("%d", &length);

	do {
		printf("Enter the command\n");
		printf("1 : Insert\n");
		printf("2 : Print\n");
		printf("3 : Delete\n");
		printf("4 : Reverse\n");
		printf("5 : ReversePrint\n");		

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
				Print(head);
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