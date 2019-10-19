#include <stdio.h>
#include <stdlib.h>
#define MAXN 10005
typedef int Set[MAXN];
typedef int SetType;
void init(Set S) {
	int i;
	for(i = 0; i < MAXN; i++) {
		S[i] = -1;
	}
}
void Union(Set S, int root1, int root2) {
	if(S[root1] < S[root2]) {
		S[root1] += S[root2];
		S[root2] = root1;
	} else {
		S[root2] += S[root1];
		S[root1] = root2;
	}
}
SetType Find(Set S, int elem) {
	if(S[elem] < 0) return elem;
	else return S[elem] = Find(S, S[elem]);
}
int main() {
	Set set;
	init(set);
	int i, n, c1, c2;
	scanf("%d%*c", &n);
	char act;
	while((act = getchar()) != 'S') {
		scanf("%d %d%*c", &c1, &c2);
		int root1, root2;
		root1 = Find(set, c1);
		root2 = Find(set, c2);
		if(act == 'C') {
			if(root1 == root2 && (root1 > 0 || root2 > 0)) printf("yes\n");
			else printf("no\n");
		} else if(act == 'I') {
			Union(set, root1, root2);
		}
	}
	int cnt = 0;
	for(i = 1; i <= n; i++) {
		if(set[i] < 0) cnt++;
	}
	if(cnt == 1) printf("The network is connected.\n");
	else printf("There are %d components.\n", cnt);
	return 0;
}
