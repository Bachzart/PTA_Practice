#include <iostream>
using namespace std;
struct minheap{
	int *data, size;
};
typedef struct minheap* Minheap;
Minheap initminheap(int maxsize) {
	Minheap H = new minheap;
	H->data = new int[maxsize + 1];
	H->size = 0;
	return H;
}
void insertheap(Minheap H, int data) {
	int i = ++H->size;
	for(; data < H->data[i / 2] && i > 1; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = data; 
}
void printpath(Minheap H, int index) {
	for(; index >= 1; index /= 2) {
		cout << H->data[index]; 
		if(index != 1) putchar(' ');
	}
	putchar('\n');
}
int main() {
	int n, m, tmp;
	cin >> n >> m;
	Minheap H = initminheap(n);
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		insertheap(H, tmp);
	}
	for(int i = 0; i < m; i++) {
		cin >> tmp;
		printpath(H, tmp);
	}
	return 0;
} 
