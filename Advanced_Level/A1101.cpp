#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int n, array[MAXN], leftmax[MAXN], rightmin[MAXN], pivot[MAXN];
 
int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	leftmax[0] = array[0];
	for(int i = 1; i < n; i++) {
		leftmax[i] = max(leftmax[i - 1], array[i - 1]);
	}
	rightmin[n - 1] = 0x3fffffff;
	for(int i = n - 2; i >= 0; i--) {
		rightmin[i] = min(rightmin[i + 1], array[i + 1]);
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(leftmax[i] <= array[i] && array[i] <= rightmin[i]) {
			pivot[count++] = array[i];
		}
	}
	printf("%d\n", count);
	for(int i = 0; i < count; i++) {
		printf("%d", pivot[i]);
		if(i < count - 1) putchar(' ');
	}
	putchar('\n');
	return 0;
}
