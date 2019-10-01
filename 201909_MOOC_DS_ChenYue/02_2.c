#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode* Polynomial;
typedef struct PolyNode* PtrToPolyNode;
struct PolyNode {
	int coef, expon;
	struct PolyNode *link;
};
PtrToPolyNode CreateNode(int c, int e) {
	PtrToPolyNode t = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
	t->coef = c, t->expon = e;
	t->link = NULL;
	return t;
}
Polynomial ReadPoly() {
	int n, c, e;
	scanf("%d", &n);
	Polynomial P, p;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	p = P;
	if(n == 0) {
		PtrToPolyNode t = CreateNode(0, 0);
		p->link = t;
	} else {
		while(n--) {
			scanf("%d %d", &c, &e);
			PtrToPolyNode t = CreateNode(c, e);
			p->link = t;
			p = t;
		}
	}
	return P;
}
void Print(Polynomial P) {
	if(P->link == NULL) {
		printf("0 0\n");
		return;
	} else {
		P = P->link;
		while(P->link != NULL) {
			printf("%d %d ", P->coef, P->expon);
			P = P->link;
		}
		printf("%d %d\n", P->coef, P->expon);
	}
}
Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial P, p, p1 = P1->link, p2 = P2->link;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	p = P;
	while(p1 && p2) {
		if(p1->expon == p2->expon) {
			int e = p1->expon, c = p1->coef + p2->coef;
			if(c != 0) {
				PtrToPolyNode t = CreateNode(c, e);
				p->link = t;
				p = t;
			}
			p1 = p1->link;
			p2 = p2->link;
		} else if(p1->expon > p2->expon) {
			PtrToPolyNode t = CreateNode(p1->coef, p1->expon);
			p->link = t;
			p = t;
			p1 = p1->link;
		} else {
			PtrToPolyNode t = CreateNode(p2->coef, p2->expon);
			p->link = t;
			p = t;
			p2 = p2->link;
		}
	}
	while(p1 && p1->coef != 0) {
		PtrToPolyNode t = CreateNode(p1->coef, p1->expon);
		p->link = t;
		p = t;
		p1 = p1->link;
	}
	while(p2 && p1->coef != 0) {
		PtrToPolyNode t = CreateNode(p2->coef, p2->expon);
		p->link = t;
		p = t;
		p2 = p2->link;
	}
	return P;
}
Polynomial Multi(Polynomial P1, Polynomial P2) {
	Polynomial P, p, p1 = P1->link, p2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	while(p1) {
		p2 = P2->link;
		while(p2) {
			int c = p1->coef * p2->coef;
			int e = p1->expon + p2->expon;
			p = P;
			while(p->link != NULL && p->link->expon > e) p = p->link;
			if(p->link != NULL) {
				if(p->link->expon == e) {
					int ctmp = p->link->coef + c;
					if(ctmp == 0) {
						PtrToPolyNode tmp = p->link;
						p->link = tmp->link;
						free(tmp);
					} else {
						p->link->coef = ctmp;
					}
				} else {
					if(c != 0) {
						PtrToPolyNode t = CreateNode(c, e);
						t->link = p->link;
						p->link = t;
					}
				}
			} else {
				if(c != 0) {
					PtrToPolyNode t = CreateNode(c, e);
					t->link = p->link;
					p->link = t;
				}
			}
			p2 = p2->link;
		}
		p1 = p1->link;
	}
	return P;
}
int main() {
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PS = Add(P1, P2);
	PP = Multi(P1, P2);
	Print(PP);
	Print(PS);
	return 0;
}

/*
some samples:
in:
1 -1 1
1 1 1
out:
-1 2
0 0

in:
2 -1 1 2 0
1 1 1
out:
-1 2 2 1
2 0

in:
2 1 1 1 0
2 1 1 -1 0
out:
1 2 -1 0
2 1

in:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
out:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

in:
1 0 0
3 1 3 1 2 1 1
out:
0 0
1 3 1 2 1 1

in:
2 2 0 0 0
3 3 2 2 1 1 0
out:
6 2 4 1 2 0
3 2 2 1 3 0

in:
0
1 10 0
out:
0 0
10 0
*/
