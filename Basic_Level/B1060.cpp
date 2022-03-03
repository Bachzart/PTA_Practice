#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int n, num[maxn] = {0};
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num + 1, num + n + 1, cmp);
	int ans = 0, p = 1;
	while(ans <= n && num[p] > p) {
		ans++;
		p++;
	}
	printf("%d", ans);
	return 0;
}
