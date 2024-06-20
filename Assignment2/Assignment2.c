#include <stdio.h>
#include <stdlib.h>
#define VERTEX_COUNT 6

typedef struct nodePointer {
	int vertex;
	struct nodePointer* link;
} nodePointer;

typedef struct hdnodes {
	int count;
	struct nodePointer* link;
} hdnodes;

void topSort(hdnodes* graph[], int n) {
	int i, j, k, top;
	nodePointer* ptr;

	top = -1;
	// �����ڰ� ���� �������� �������� �����Ͽ� ó����

	for (i = 0; i < n; i++) {				// ��� ������ ����
		if (!graph[i]->count) {				// i�� count ���� 0; ������ ��
			graph[i]->count = top;			// count field�� stack ����!
			top = i;						// ������ ���� ���� i
		}
	}

	for (i = 0; i < n; i++) {				// i=0, ���� 0 ó��
		if (top == -1) {
			printf("\n Network has a cycle. Sort terminated. \n");
			exit(1);
		}
		else {								// ���� top���� ������ ������ ó����
			j = top;						// j: ������ ���� ������ ���� (���� ó�� ���� ����)
			top = graph[top]->count;		// ���ÿ��� ���� (pop)
			printf("V%d ", j);				// �����ڰ� ���� ���� j ���

			for (ptr = graph[j]->link; ptr != NULL; ptr = ptr->link) {	// ���� j�� ����� ������ ó��
				k = ptr->vertex;			// k: ���� i�� ����� ����
				graph[k]->count--;			// ���� k�� ������(����) ����
				if (!graph[k]->count) {		// k�� �����ڰ� ������
					graph[k]->count = top;	// ���ÿ� ���� (push)
					top = k;
				}
			}
		}
	}
}

void linkNode(hdnodes* graph[], int source, int target) {
	nodePointer* newNode;
	nodePointer* temp;

	newNode = (nodePointer*)malloc(sizeof(nodePointer));
	newNode->vertex = target;
	newNode->link = NULL;

	graph[target]->count++;

	temp = graph[source]->link;
	if (temp == NULL) {
		graph[source]->link = newNode;
	}
	else {
		for (; temp->link != NULL; temp = temp->link);
		temp->link = newNode;
	}
}

void printNodes(hdnodes* graph[]) {
	int i;
	nodePointer* temp;

	for (i = 0; i < VERTEX_COUNT; i++) {
		printf("%d: ", i);
		temp = graph[i]->link;
		if (temp != NULL) {
			for (; temp != NULL; temp = temp->link) {
				printf("%d ", temp->vertex);
			}
		}
		printf("\n");
	}
}

int main(void) {
	hdnodes graph[VERTEX_COUNT];
	hdnodes* graphPtr[VERTEX_COUNT];
	int i;

	for (i = 0; i < VERTEX_COUNT; i++) {
		graphPtr[i] = &graph[i];
		graph[i].count = 0;
		graph[i].link = NULL;
	}

	linkNode(graphPtr, 0, 1);
	linkNode(graphPtr, 0, 2);
	linkNode(graphPtr, 0, 3);
	linkNode(graphPtr, 1, 4);
	linkNode(graphPtr, 2, 4);
	linkNode(graphPtr, 2, 5);
	linkNode(graphPtr, 3, 4);
	linkNode(graphPtr, 3, 5);

	// Required Output #1
	printf("������ count �� (incoming edge)\n");
	for (i = 0; i < VERTEX_COUNT; i++) {
		printf("V%d: %d\n", i, graph[i].count);
	}

	printf("\n");

	// Custom Output
	printf("��� ���\n");
	printNodes(graphPtr);

	printf("\n");

	// Required Output #2
	printf("���� ���� ���� (Topological Order)\n");
	topSort(graphPtr, VERTEX_COUNT);

	printf("\n");

	return 0;
}