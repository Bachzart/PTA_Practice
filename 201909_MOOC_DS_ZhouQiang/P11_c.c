#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct HNode{
	int *Data;
	int Capacity, Size;
};
typedef struct HNode* Heap;
typedef Heap MinHeap;
MinHeap Createheap(int capacity) {
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (int*)malloc(sizeof(int) * (capacity + 1));
	H->Capacity = capacity, H->Size = 0;
	return H;
} 
bool Isfull(MinHeap H) {
	return H->Size == H->Capacity;
}
bool Isempty(MinHeap H) {
	return H->Size == 0;
}
void Percolatedown(MinHeap H, int k) {
	int tmp = H->Data[k];
	int parent, child;
	for(parent = k; parent * 2 <= H->Size; parent = child) {
		child = parent * 2;
		if(child != H->Size && H->Data[child] > H->Data[child + 1]) child++;
		if(tmp > H->Data[child]) H->Data[parent] = H->Data[child];
		else break;
	}
//	printf("parent = %d\n", parent);
	H->Data[parent] = tmp;
}
void Percolateup(MinHeap H, int k) {
	int tmp = H->Data[k];
	for(; k > 1 && H->Data[k / 2] > tmp; k /= 2) {
		H->Data[k] = H->Data[k / 2];
	} 
	H->Data[k] = tmp;
}
bool Insert(MinHeap H, int data) {
	if(Isfull(H)) return false;
	else {
		H->Data[++H->Size] = data;
		Percolateup(H, H->Size);
		return true;
	}
}
bool Deletemin(MinHeap H) {
	if(Isempty(H)) return false;
	else {
		H->Data[1] = H->Data[H->Size--];
		Percolatedown(H, 1);
		return true;
	}
}
void Printheap(MinHeap H) {
	for(int i = 1; i <= H->Size; i++) {
		printf("%d", H->Data[i]);
		if(i < H->Size) putchar(' ');
	}
	putchar('\n');
}
MinHeap Buildheap(int *array, int size, int maxsize) {
	MinHeap H = Createheap(maxsize);
	H->Size = size;
	int i;
	for(i = 1; i <= size; i++) {
		H->Data[i] = array[i];
	}
	for(i = H->Size / 2; i > 0; i--) {
		Percolatedown(H, i);
	}
	return H;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	MinHeap h = Createheap(n);
	int ope, data;
	for(int i = 1; i <= k; i++) {
		scanf("%d", &ope);
		if(ope == 1) {
			scanf("%d", &data);
			Insert(h, data);
			Printheap(h);
		} else if(ope == -1){
			Deletemin(h);
			Printheap(h);
		}
	} 
	int m, seq[1010];
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &seq[i]);
	}
	MinHeap h2 = Buildheap(seq, m, m);
//	printf("--\n");
	Printheap(h2);
	return 0;
} 
