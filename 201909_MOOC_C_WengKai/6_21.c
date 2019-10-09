#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main()
{
    struct stud_node *p;
	
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

void input() {
	head = (struct stud_node*)malloc(sizeof(struct stud_node));
	head->next = NULL;
	tail = head;
	int num, score;
	char name[20];
	while(scanf("%d", &num) != EOF && num) {
		scanf("%s %d", name, &score);
		struct stud_node *t;
		t = (struct stud_node*)malloc(sizeof(struct stud_node));
		strcpy(t->name, name), t->score = score, t->num = num;
		t->next = NULL;
		tail->next = t;
		tail = t;
	} 
	tail = head;
	head = head->next;
	free(tail);
}
