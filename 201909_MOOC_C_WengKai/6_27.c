#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
	
    return 0;
}

struct ListNode *createlist() {
	struct ListNode *head, *r;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	r = head;
	int data;
	while(scanf("%d", &data) != EOF && data != -1) {
		struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
		t->next = NULL, t->data = data;
		r->next = t;
		r = t;
	}
	r = head;
	head = head->next;
	free(r);
	return head;
}

/* method 1: */
struct ListNode *reverse(struct ListNode *head) {
	if(head == NULL) return NULL;
	struct ListNode *pre = head, *p = head->next, *t;
	pre->next = NULL;
	while(p) {
		t = p;
		p = p->next;
		t->next = pre;
		pre = t;
	}
	return pre;
}


/* method 2:

struct ListNode *reverse( struct ListNode *head ) {
	struct ListNode *L, *p, *ph = head, *t;
	L = (struct ListNode*)malloc(sizeof(struct ListNode));
	L->next = NULL;
	p = L;
	while(ph) {
		t = ph;
		ph = ph->next;
		t->next = p->next;
		p->next = t;
	}
	t = L;
	L = L->next;
	free(t);
	return L;
}
*/
