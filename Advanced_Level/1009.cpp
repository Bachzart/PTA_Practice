#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;	//the way to represent the polynomial
struct PolyNode {
	double coef;	//coefficient
	int expon;	//exponent
	Polynomial link;	//link next node
};


void Attach(double c, int e, Polynomial *pRear);
Polynomial ReadPoly();
Polynomial Mult(Polynomial P1, Polynomial P2);
void PrintPoly(Polynomial P);
int Compare(int a, int b);
int GetNum(Polynomial P);

int main(int argc, char const *argv[]){
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	int numbers = GetNum(PP);
	if(numbers) {
		printf("%d ", numbers);
		PrintPoly(PP);
	} else {
		printf("%d\n");
	}
	return 0;
}

void Attach(double c, int e, Polynomial *pRear) {
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial ReadPoly() {
	Polynomial P, Rear, t;
	int e, K;
	double c;
	scanf("%d", &K);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(K--) {
		scanf("%d %lf", &e, &c);
		Attach(c, e, &Rear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t1, t2, t;
	int e;
	double c;
	if(!P1 || !P2)	return NULL;
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(t2) {
		//use the first node of P1 to multiple the P2's every nodes
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;	//now pass the first node
	while(t1) {
		t2 = P2;
		Rear = P;
		while(t2) {
			e = t1->expon + t2->expon;	//calculate the sum of exponent
			c = t1->coef * t2->coef;	//calculate the  multi of coefficient
			while(Rear->link && Rear->link->expon > e) {
				Rear = Rear->link;
			}
			if(Rear->link && Rear->link->expon == e) {
				if(Rear->link->coef + c) {
					Rear->link->coef += c;
				} else {
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			} else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	free(t2);
	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0;
	if(!P){
		printf("0 0\n");
		return;
	}
	while(P)
	{
		if(!flag) flag = 1;
		else printf(" ");
		printf("%d %.1lf", P->expon, P->coef);
		P = P->link;
	}
	printf("\n");
}

int Compare(int a, int b)
{
	return a > b ? 1 : a == b ? 0 : -1;
}

int GetNum(Polynomial P) {
	Polynomial p = P;
	int ret = 0;
	while(p) {
		ret++;
		p = p->link;
	}
	return ret;
}
