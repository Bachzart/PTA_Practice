#include <stdio.h>
#include <stdlib.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist( struct stud_node *head, int min_score );

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

struct stud_node *createlist() {
	struct stud_node *head, *r;
	head = (struct stud_node*)malloc(sizeof(struct stud_node));
	head->next = NULL;
	r = head;
	int num;
	while(scanf("%d", &num) != EOF && num) {
		struct stud_node *t = (struct stud_node*)malloc(sizeof(struct stud_node));
		t->next = NULL;
		scanf("%s %d", t->name, &t->score);
		t->num = num;
		r->next = t;
		r = t;
	} 
	return head;
}
struct stud_node *deletelist( struct stud_node *head, int min_score ) {
	struct stud_node *p = head, *t;
	while(p->next != NULL) {
		if(p->next->score < min_score) {
			t = p->next;
			p->next = t->next;
			free(t);
		} else p = p->next;
	}
	t = head;
	head = head->next;
	free(t);
	return head;
}
