#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput() {
	List L = (List)malloc(sizeof(struct LNode));
	int n, t, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &L->Data[i]);
	}
	L->Last = i;
	return L;
}

Position BinarySearch( List L, ElementType X ) {
	int left = 1, right = L->Last, mid, flag = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		if(L->Data[mid] == X) {
			flag = 1;
			break;
		} else if(L->Data[mid] < X) left = mid + 1;
		else right = mid - 1;
	}
	if(flag) return mid;
	else return NotFound;
}

/*
some samples:
in:
5
12 31 55 89 101
31
out:
2

in:
3
26 78 233
31
out:
0

in:
4
26 78 88 233
88
out:
3

in:
4
26 78 88 233
78
out:
2
*/
