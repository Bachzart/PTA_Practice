#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode *readlist() {
	struct ListNode *head, *r;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	r = head;
	int data;
	while(scanf("%d", &data) != EOF && data != -1) {
		struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->data = data;
		tmp->next = NULL;
		r->next = tmp;
		r = tmp;
	}
	return head;
}

/* method 1: */
struct ListNode *deletem( struct ListNode *L, int m ) {
	struct ListNode *t, *p = L;
	while(p->next != NULL) {
		if(p->next->data == m) {
			t = p->next;
			p->next = t->next;
			free(t);
		} else p = p->next;
	}
	t = L;
	L = L->next;
	free(t);
	return L;
}

/* method 2:  
struct ListNode *deletem(struct ListNode *L, int m) {
	struct ListNode *pre = L, *p = L->next, *t;
	while(p) {
		if(p->data == m) {
			t = p;
			pre->next = t->next;
			p = p->next;
			free(t);
		} else {
			pre = p;
			p = p->next;
		}
	}
	p = L;
	L = L->next;
	free(p);
	return L;
}

*/

/* method 3:

struct ListNode *deletem( struct ListNode *L, int m ) {
	struct ListNode *p = L->next, *r = L, *t;
	while(p) {
		if(p->data != m) {
			r->next = p;
			r = p;
			p = p->next;
		} else {
			t = p;
			p = p->next;
			free(t);
		}
	}
	r->next = NULL;
	p = L;
	L = L->next;
	free(p);
	return L;
}

*/
