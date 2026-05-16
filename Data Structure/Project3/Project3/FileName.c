#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}List;

List* initList() {
	List* head = (List*)malloc(sizeof(List));
	head->next = NULL;
	return head;
}

void insertHead(List* head, int x) {
	List* temp = (List*)malloc(sizeof(List));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void printList(List* head) {
	List* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	List* head = initList();
	insertHead(head, 10);
	insertHead(head, 20);
	insertHead(head, 30);
	insertHead(head, 40);
	printList(head);
}