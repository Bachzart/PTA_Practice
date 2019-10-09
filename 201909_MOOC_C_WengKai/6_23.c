#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

struct ListNode *createlist() {
	struct ListNode *head, *p;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	p = head;
	int data;
	while(scanf("%d", &data) != EOF && data != -1) {
		struct ListNode *t = (struct ListNode*)malloc(sizeof(struct ListNode));
		t->next = p->next, t->data = data;
		p->next = t;
	} 
	p = head;
	head = head->next;
	return head;
}
