#include <cstdio>
const int maxn = 1000 + 5;
int arr[maxn] = {0, 2, 0, 1, 9};
int main() {
	int n, tmp;
	scanf("%d", &n);
	for(int i = 5; i <= n;i++) {
		tmp = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
		arr[i] = tmp % 10;
	}
	for(int i = 1; i <= n; i++) {
		printf("%d", arr[i]);
	}
	return 0;
} 
