#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L );

List Insert( List L, ElementType X );

int main() {
	List L;
	ElementType X;
	L = Read();
	scanf("%d", &X);
	L = Insert(L, X);
	Print(L);
	return 0;
}

List Read() {
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	PtrToNode r;
	r = L;
	int n;
	scanf("%d", &n);
	while(n--) {
		PtrToNode t = (PtrToNode)malloc(sizeof(struct Node));
		scanf("%d", &t->Data);
		t->Next = NULL;
		r->Next = t;
		r = t;
	}
	return L;
}
void Print( List L ) {
	L = L->Next;
	while(L) {
		printf("%d ", L->Data);
		L = L->Next;
	}
}

List Insert( List L, ElementType X ) {
	PtrToNode p = L, t;
	while(p->Next && p->Next->Data < X) p = p->Next;
	t = (PtrToNode)malloc(sizeof(struct Node));
	t->Data = X, t->Next = p->Next;
	p->Next = t;
	return L;
}
