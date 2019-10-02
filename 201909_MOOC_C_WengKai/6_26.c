#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char code[8];
    struct ListNode *next;
};

struct ListNode *createlist(); 
int countcs( struct ListNode *head );

int main()
{
    struct ListNode  *head;

    head = createlist();
    printf("%d\n", countcs(head));
	
    return 0;
}

struct ListNode *createlist() {
	struct ListNode *head, *r;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	r = head;
	char str[8];
	while(scanf("%s", str) != EOF && str[0] != '#') {
		struct ListNode *t;
		t = (struct ListNode*)malloc(sizeof(struct ListNode));
		strcpy(t->code, str);
		t->next = NULL;
		r->next = t;
		r = t;
	}
	r = head;
	head = head->next;
	free(r);
	return head;
}

int countcs( struct ListNode *head ) {
	int count = 0;
	while(head) {
		if(head->code[1] == '0' && head->code[2] == '2') count++;
		head = head->next;
	}
	return count;
}
