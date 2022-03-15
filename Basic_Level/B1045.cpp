/* way 1 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int n, arr[maxn] = {0}, tmp[maxn], ans[maxn] = {0};

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		tmp[i] = arr[i];
	} 
	sort(tmp, tmp + n);
	int cnt = 0, max = 0;
	for(int i = 1; i <= n; i++) {
		if(arr[i] == tmp[i] && max < arr[i]) ans[cnt++] = arr[i];
		if(arr[i] > max) max = arr[i];
	}
	cout << cnt << endl;
	if(cnt) {
		for(int i = 0; i < cnt; i++) {
			cout << ans[i];
			if(i != cnt - 1) cout << ' ';
		}
	}
	cout << endl;
	return 0;
} 


/* way 2

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

*/
