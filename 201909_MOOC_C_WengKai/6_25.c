#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); 
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
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
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
	
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
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2) {
	struct ListNode *p1 = list1, *p2 = list2, *head, *p;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	p = head;
	while(p1 && p2) {
		if(p1->data < p2->data) {
			p->next = p1;
			p = p1;
			p1 = p1->next;
		} else {
			p->next = p2;
			p = p2;
			p2 = p2->next;
		}
	}
	if(p2) p1 = p2;
	p->next = p1;
	p = head;
	head = head->next;
	free(p);
	return head;
}
