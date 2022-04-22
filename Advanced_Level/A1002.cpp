/*
test point 5, like this:
2 1 2.4 0 3.2
3 2 2.4 1 2.4 0 -3.2
*/

/* method 1: use linked list */

#include <cstdio>
#include <cstdlib>

typedef struct Polynode* Polynomial;
struct Polynode {
	int expo;
	double coef;
	Polynomial link;
};

Polynomial ReadPoly();
Polynomial Add(Polynomial P1, Polynomial P2);
void Print(Polynomial PP);
int GetNum(Polynomial P);
void Attach(double c, int e, Polynomial *pRear);

int main(int argc, char const *argv[]) {
	Polynomial P1 = ReadPoly();
	Polynomial P2 = ReadPoly();
	Polynomial PP = Add(P1, P2);
	int number = GetNum(PP);
	if(number) {
		printf("%d ", number);
		Print(PP);
	} else {
		printf("%d\n", number);
	}
	return 0;
}

Polynomial ReadPoly() {
	int K;
	scanf("%d", &K);
	Polynomial P, rear;
	P = (Polynomial)malloc(sizeof(struct Polynode));
	P->link = NULL;
	rear = P;
	int e;
	double c;
	while(K--) {
		scanf("%d %lf", &e, &c);
		Attach(c, e, &rear);
	}
	return P;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial p1 = P1->link, p2 = P2->link, p, rear;
	p = (Polynomial)malloc(sizeof(struct Polynode));
	p->link = NULL;
	rear = p;
	double sum;
	while(p1 && p2) {
		int temp = p1->expo - p2->expo;
		if(temp > 0) {
			Attach(p1->coef, p1->expo, &rear);
			p1 = p1->link;
		} else if(temp == 0) {
			sum = p1->coef + p2->coef;
			if(sum) {
				Attach(sum, p1->expo, &rear);
			}
			p1 = p1->link;
			p2 = p2->link;
		} else {
			Attach(p2->coef, p2->expo, &rear);
			p2 = p2->link;
		}
	}
	if(p1) {
		rear->link = p1;
	}
	if(p2) {
		rear->link = p2;
	}
	return p;
}

void Print(Polynomial PP) {
	Polynomial P = PP->link;
	while(P) {
		if(P->link == NULL) {
			printf("%d %.1lf\n", P->expo, P->coef);
		} else {
			printf("%d %.1lf ", P->expo, P->coef);
		}
		P = P->link;
	}
}

int GetNum(Polynomial P) {
	Polynomial p = P->link;
	int ret = 0;
	while(p) {
		ret++;
		p = p->link;
	}
	return ret;
}

void Attach(double c, int e, Polynomial *pRear) {
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct Polynode));
	P->coef = c;
	P->expo = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

/* method 2: use array*/
#include <cstdio>
void readp(int nums, double *poly) {
	int exp;
	double coe;
	for(int i = 0; i < nums; i++) {
		scanf("%d %lf", &exp, &coe);
		poly[exp] = coe;
	}
}
int main() {
	double L1[1005] = {0}, L2[1005] = {0}, L[1005] = {0};
	int k1, k2, exp;
	double coe;
	scanf("%d", &k1);
	readp(k1, L1);
	scanf("%d", &k2);
	readp(k2, L2);
	int cnt = 0;
	for(int i = 0; i < 1005; i++) {
		L[i] = L1[i] + L2[i];
		if(L[i] != 0) cnt++;
	}
	printf("%d", cnt);
	if(cnt) {
		for(int i = 1000; i >= 0; i--) {
			if(L[i] != 0) printf(" %d %.1lf", i, L[i]);
		}
	}
	return 0;
}