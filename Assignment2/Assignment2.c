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
	// 선행자가 없는 정점들을 스택으로 구성하여 처리함

	for (i = 0; i < n; i++) {				// 모든 정점에 대해
		if (!graph[i]->count) {				// i의 count 값이 0; 선행자 無
			graph[i]->count = top;			// count field로 stack 연결!
			top = i;						// 선행자 없는 정점 i
		}
	}

	for (i = 0; i < n; i++) {				// i=0, 정점 0 처리
		if (top == -1) {
			printf("\n Network has a cycle. Sort terminated. \n");
			exit(1);
		}
		else {								// 스택 top에서 정점을 꺼내고 처리함
			j = top;						// j: 선행자 없는 마지막 정점 (현재 처리 중인 정점)
			top = graph[top]->count;		// 스택에서 꺼냄 (pop)
			printf("V%d ", j);				// 선행자가 없는 정점 j 출력

			for (ptr = graph[j]->link; ptr != NULL; ptr = ptr->link) {	// 정점 j와 연결된 정점의 처리
				k = ptr->vertex;			// k: 정점 i에 연결된 정점
				graph[k]->count--;			// 정점 k의 선행자(간선) 제거
				if (!graph[k]->count) {		// k의 선행자가 없으면
					graph[k]->count = top;	// 스택에 삽입 (push)
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
	printf("정점별 count 값 (incoming edge)\n");
	for (i = 0; i < VERTEX_COUNT; i++) {
		printf("V%d: %d\n", i, graph[i].count);
	}

	printf("\n");

	// Custom Output
	printf("노드 출력\n");
	printNodes(graphPtr);

	printf("\n");

	// Required Output #2
	printf("위상 정렬 순서 (Topological Order)\n");
	topSort(graphPtr, VERTEX_COUNT);

	printf("\n");

	return 0;
}