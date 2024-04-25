#include <stdio.h>
#include <stdlib.h>

typedef struct listNode NODE;
typedef struct listNode {
	int data;
	NODE* link;
};

NODE* create2();
void insert(NODE* ptr, NODE* first);
void printList(NODE* ptr);
void printListBackwards(NODE* ptr);
NODE* inverted(NODE* lead);

int main(void) {
	NODE* ptr = NULL;

	ptr = create2();
	printf("<��� ���� ��>\n");
	printList(ptr);
	printf("\n");

	insert(ptr, ptr);
	printf("<50 ���� ��>\n");
	printList(ptr);
	printf("\n");

	printf("<�������� ���>\n");
	printListBackwards(ptr);
	printf("\n");

	ptr = inverted(ptr);
	printf("<����>\n");
	printList(ptr);
	printf("\n");

	return 0;
}

void printList(NODE* ptr) {
	for (; ptr; ptr = ptr->link) {	// Until there isn't any node left
		printf("%d\n", ptr->data);
	}
}

void printListBackwards(NODE* ptr) {
	if (ptr->link) {	// Not last node
		printListBackwards(ptr->link);
	}
	printf("%d\n", ptr->data);
}

NODE* create2() {  // �� ���� ��带 ���� ���� ����Ʈ ����
	NODE* first, * second;

	first = (NODE*)malloc(sizeof(NODE));
	second = (NODE*)malloc(sizeof(NODE));

	first->data = 10;
	first->link = second;

	second->data = 20;
	second->link = NULL;

	return first;
}

void insert(NODE* ptr, NODE* first) {
	NODE* temp;

	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = 50;

	if (ptr) { // non empty list
		temp->link = first->link;
		first->link = temp;
	}
	else { // empty list
		temp->link = NULL;
		ptr = temp;
	}
}

NODE* inverted(NODE* lead) {
	NODE* middle, * trail;
	middle = NULL;
	while (lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}