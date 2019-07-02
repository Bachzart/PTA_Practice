/* method 1: use liked list
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node* List;
typedef struct node{
	int coef, expo;
	List next;
} Node;

List CreateList(void);
void Derivation(List L);
void Print(List L);

int main(int argc, char const *argv[]) {
	List L = CreateList();
	Derivation(L);
	Print(L);
	return 0;
} 

List CreateList(void) {
	List L = (List)malloc(sizeof(Node)), rear;
	L->next = NULL;
	rear = L;
	int c, e;
	while(scanf("%d %d", &c, &e) != EOF) {
		List temp_node = (List)malloc(sizeof(Node));
		temp_node->next = NULL;
		rear->next = temp_node;
		rear = temp_node;
		temp_node->coef = c;
		temp_node->expo = e;
	}
	return L;
}

void Print(List L) {
	List Temp = L->next;
	int flag = 1;
	while(Temp) {
		if(flag) {
			printf("%d %d", Temp->coef, Temp->expo);
			flag = 0;
		} else {
			if(Temp->coef != 0) {
				printf(" %d %d", Temp->coef, Temp->expo);
			}
		}
		Temp = Temp->next;
	}
	putchar('\n');
}

void Derivation(List L) {
	List p = L->next;
	while(p) {
		if(p->expo) {
			p->coef = p->coef * p->expo;
			p->expo--;
		} else {
			p->coef = 0;
		}
		p = p->next;
	}
}

/* method 2: use array, index -> exponent, value -> coefficent
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i, items[1005] = {0}, c, e, count = 0;
	while(scanf("%d %d", &c, &e) != EOF) {
		items[e] = c;
	}
	items[0] = 0;
	for(i = 1; i <= 1000; i++) {
		items[i - 1] = items[i] * i;
		items[i] = 0;
		if(items[i - 1] != 0) {
			count++;
		}
	}
	if(count == 0) printf("0 0\n");
	else {
		for(i = 1000; i >= 0; i--) {
			if(items[i]) {
				printf("%d %d", items[i], i);
				count--;
				if(count != 0) {
					putchar(' ');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}

*/
