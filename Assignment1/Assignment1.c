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
	printf("<노드 생성 후>\n");
	printList(ptr);
	printf("\n");

	insert(ptr, ptr);
	printf("<50 삽입 후>\n");
	printList(ptr);
	printf("\n");

	printf("<역순으로 출력>\n");
	printListBackwards(ptr);
	printf("\n");

	ptr = inverted(ptr);
	printf("<역순>\n");
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

NODE* create2() {  // 두 개의 노드를 가진 연결 리스트 생성
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