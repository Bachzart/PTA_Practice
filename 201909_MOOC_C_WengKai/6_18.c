#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L ) {
	struct ListNode *p = L;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	struct ListNode *L, *Odd;
	L = readlist();
	Odd = getodd(&L);
	printlist(Odd);
	printlist(L);

	return 0;
}

struct ListNode *readlist() {
	struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode));
	L->next = NULL;
	struct ListNode *p = L;
	int data;
	while(scanf("%d", &data) != EOF) {
		if(data == -1) break;
		struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
		t->next = NULL;
		t->data = data;
		p->next = t;
		p = t;
	}
	return L;
}
struct ListNode *getodd( struct ListNode **L ) {
	struct ListNode *p = *L;
	struct ListNode *odd_head, *t;
	odd_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	odd_head->next = NULL;
	t = odd_head;
	while(p->next != NULL) {
		if(p->next->data % 2 != 0) {
			t->next = p->next;
			t = p->next;
			p->next = t->next;
			t->next = NULL;
		} else {
			p = p->next;
		}
	}
	struct ListNode *ptmp = odd_head;
	odd_head = odd_head->next;
	free(ptmp);
	ptmp = *L;
	*L = (*L)->next;
	free(ptmp);
	return odd_head;
}
