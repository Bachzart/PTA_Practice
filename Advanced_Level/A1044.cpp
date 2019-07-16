#include <cstdio>
const int MAXN = 100000 + 10;
int sum[MAXN];
int n, S, nearS = 100000000 + 10;

int UpperBound(int L, int R, int x);

int main(int argc, char const *argv[]) {
	scanf("%d %d", &n, &S);
	sum[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	//find the approperiate 'nearS'
	for(int i = 1; i <= n; i++) {
		int j = UpperBound(i, n + 1, sum[i - 1] + S);
		if(sum[j - 1] - sum[i - 1] == S) {
			nearS = S;
			break;
		} else if(j <= n && sum[j] - sum[i - 1] < nearS) {
			//find the minimum
			nearS = sum[j] - sum[i - 1];
			printf("nearS = %d\n", nearS);
		}
	}
	//print
	for(int i = 1; i <= n; i++) {
		int j = UpperBound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}

int UpperBound(int L, int R, int x) {
	int left = L, right = R, mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(sum[mid] > x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}
