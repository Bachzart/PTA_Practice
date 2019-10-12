#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* �洢������� */
    PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

int FactorialSum( List L ) {
	int sum = 0;
	while(L) {
		int i, fac = 1;
		for(i = 1; i <= L->Data; i++) {
			fac *= i; 
		}
		sum += fac;
		L = L->Next;
	}
	return sum;
} 