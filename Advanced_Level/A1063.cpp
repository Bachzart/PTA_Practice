#include <cstdio>
#include <set>
using namespace std;
const int MAXN = 50 + 5;
set<int> st[MAXN];

void compare(int x, int y) {
	int totalNum = st[y].size(), sameNum = 0;
	for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) {
		if(st[y].find(*it) != st[y].end()) sameNum++;
		else totalNum++; 
	}
	printf("%.1lf%\n", sameNum * 100.0 / totalNum);
}

int main(int argc, char const *argv[]) {
	int n, m, k, temp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for(int j = 0; j < m; j++) {
			scanf("%d", &temp);
			st[i].insert(temp);
		}
	}
	scanf("%d", &k);
	while(k--) {
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		compare(s1, s2);
	}
	return 0;
}
