#include <cstdio>
#include <algorithm>
using namespace std; 
const int MAXN = 100000 + 10;
const int INF = 0x3fffffff;
int array[MAXN], leftMax[MAXN], rightMin[MAXN];
int ans[MAXN], num = 0;

int main(int argc, char const *argv[]) {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &array[i]);
	}
	leftMax[0] = 0;
	for(int i = 1; i < N; i++) {
		leftMax[i] = max(leftMax[i - 1], array[i - 1]);
	}
	rightMin[N - 1] = INF;
	for(int i = N - 2; i >= 0; i--) {
		rightMin[i] = min(rightMin[i + 1], array[i + 1]);
	}
	for(int i = 0; i < N; i++) {
		if(leftMax[i] < array[i] && rightMin[i] > array[i]) {
			ans[num++] = array[i];
		}
	}
	printf("%d\n", num);
	for(int i = 0; i < num; i++) {
		printf("%d", ans[i]);
		if(i < num - 1) putchar(' ');
	}
	putchar('\n');
	return 0;
}
