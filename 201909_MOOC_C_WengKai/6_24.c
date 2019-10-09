#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
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
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
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
	return head;
}
struct ListNode *deleteeven( struct ListNode *head ) {
	struct ListNode *p = head, *t;
	while(p->next != NULL) {
		if(p->next->data % 2 == 0) {
			t = p->next;
			p->next = t->next;
			free(t); 
		} else p = p->next;
	}
	t = head;
	head = head->next;
	return head;
}
