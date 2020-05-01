#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 15
struct QNode {
	int data;
	struct QNode *next;
};
typedef struct QNode* PtrToQNode;
struct queue {
	PtrToQNode Front, Rear;
};
typedef struct queue* Queue;
Queue Createqueue() {
	Queue Q = (Queue)malloc(sizeof(struct queue));
	Q->Front = Q->Rear = NULL;
	return Q;
}
bool Isempty(Queue Q) {
	return Q->Front == NULL;
}
void Enqueue(Queue Q, int X) {
	PtrToQNode t = (PtrToQNode)malloc(sizeof(struct QNode));
	t->data = X;
	t->next = NULL;
	if(Isempty(Q)) Q->Front = Q->Rear = t;
	else {
		Q->Rear->next = t;
		Q->Rear = t;
	}
}
int Dequeue(Queue Q) {
	PtrToQNode frontcell;
	int frontelem;
	frontcell = Q->Front;
	if(Q->Front == Q->Rear) Q->Front = Q->Rear = NULL;
	else Q->Front = frontcell->next;
	frontelem = frontcell->data;
	free(frontcell);
	return frontelem;
}
int n;
struct Tree {
	int left, right;
} T[maxn];
void init() {
	int i;
	for(i = 0; i < maxn; i++) {
		T[i].left = T[i].right = -1;
	}
}
int buildtree() {
	scanf("%d%*c", &n);
	bool isRoot[maxn] = {false};
	char lc, rc;
	int i;
	for(i = 0; i < n; i++) {
		scanf("%c %c%*c", &lc, &rc);
		if(lc != '-') {
			T[i].left = lc - '0';
			isRoot[lc - '0'] = true;
		}
		if(rc != '-') {
			T[i].right = rc - '0';
			isRoot[rc - '0'] = true;
		}
	}
	int root = -1;
	for(i = 0; i < n; i++) {
		if(!isRoot[i]) {
			root = i;
			break;
		}
	}
	return root;
}
void leverorder(int root) {
	Queue Q = Createqueue();
	Enqueue(Q, root);
	bool flag = true;
	while(!Isempty(Q)) {
		int front = Dequeue(Q);
		if(T[front].left == -1 && T[front].right == -1) {
			if(flag) {
				printf("%d", front);
				flag = false;
			} else printf(" %d", front);
		}
		if(T[front].left != -1) Enqueue(Q, T[front].left);
		if(T[front].right != -1) Enqueue(Q, T[front].right);
	}
}
int main() {
	init();
	int root = buildtree();
	leverorder(root);
	return 0;
}
