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

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
	int i, n, temp;
	scanf("%d", &n);
	List L, p;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	p = L;
	for(i = 0; i < n; i++) {
		scanf("%d", &temp);
		PtrToNode t = (PtrToNode)malloc(sizeof(struct Node));
		t->Data = temp;
		t->Next = NULL;
		p->Next = t;
		p = t;
	}
	return L;
}

void Print( List L ) {
	PtrToNode p = L->Next;
	if(!p) {
		printf("NULL\n");
		return;
	}
	while(p->Next != NULL) {
		printf("%d ", p->Data);
		p = p->Next;
	}
	printf("%d\n", p->Data);
}

List Merge( List L1, List L2 ) {
	PtrToNode p, p1 = L1->Next, p2 = L2->Next;
	L1->Next = L2->Next = NULL;
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	p = L;
	while(p1 && p2) {
		if(p1->Data < p2->Data) {
			p->Next = p1;
			p = p1;
			p1 = p1->Next;
		} else {
			p->Next = p2;
			p = p2;
			p2 = p2->Next;
		}
	}
	if(p1) p->Next = p1;
	if(p2) p->Next = p2;
	return L;
}
