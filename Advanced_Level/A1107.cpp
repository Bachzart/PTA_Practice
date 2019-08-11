#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn], isroot[maxn] = {0}, hobby[maxn] = {0};
int findFather(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];
	}
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) {
		father[faA] = father[faB];
	}
}
void init(int n) {
	for(int i = 1; i <= n; i++) {
		father[i] = i;
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main(int argc, char const *argv[]) {
	int n, k, h;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++) {
		scanf("%d:", &k);
		for(int j = 0; j < k; j++) {
			scanf("%d", &h);
			if(hobby[h] == 0) {
				hobby[h] = i;
			}
			Union(i, hobby[h]);
		}
	}
	for(int i = 1; i <= n; i++) {
		isroot[findFather(i)]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(isroot[i] != 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
	sort(isroot + 1, isroot + n + 1, cmp);
	for(int i = 1; i <= ans; i++) {
		printf("%d", isroot[i]);
		if(i < ans) putchar(' ');
	}
	return 0;
}
