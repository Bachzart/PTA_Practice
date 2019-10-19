#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct HNode* Heap;
struct HNode{
	int *Data;
	int Size, Capacity;
};
typedef Heap MinHeap;
MinHeap initheap(int Maxsize) {
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (int*)malloc(sizeof(int) * (Maxsize + 1));
	H->Capacity = Maxsize;
	H->Size = 0;
	return H;
}
bool isfull(MinHeap H) {
	return H->Size == H->Capacity;
}
bool insert(MinHeap H, int data) {
	if(isfull(H)) return false;
	else {
		int i = ++H->Size;
		for(; H->Data[i / 2] > data && i > 1; i /= 2) {
			H->Data[i] = H->Data[i / 2];
		}
		H->Data[i] = data;
	}
}
void Printpath(MinHeap H, int index) {
	for(; index >= 1; index /= 2) {
		printf("%d", H->Data[index]);
		if(index != 1) putchar(' ');
	}
	putchar('\n');
} 
int main() {
	int i, n, m, temp;
	scanf("%d %d", &n, &m);
	MinHeap H = initheap(n);
	for(i = 0; i < n; i++) {
		scanf("%d", &temp);
		insert(H, temp);
	}
	for(i = 0; i < m; i++) {
		scanf("%d", &temp);
		Printpath(H, temp);
	}
	return 0;
}
