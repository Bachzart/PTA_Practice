#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 15
struct TNode{
	char data;
	int left, right;
} T1[maxn], T2[maxn];
void init() {
	int i;
	for(i = 0; i < maxn; i++) {
		T1[i].left = T1[i].right = T2[i].left = T2[i].right = -1;
	}
}
int buildtree(struct TNode T[]) {
	int i, n;
	scanf("%d%*c", &n);
	char data, lc, rc;
	bool isRoot[maxn] = {false};
	for(i = 0; i < n; i++) {
		scanf("%c %c %c%*c", &data, &lc, &rc);
		T[i].data = data;
		if(lc != '-') {
			T[i].left = lc - '0';
			isRoot[lc - '0'] = true;
		}
		if(rc != '-') {
			T[i].right = rc - '0';
			isRoot[rc - '0'] = true;
		} 
	}
	int root = -1;
	for(i = 0; i < n; i++) {
		if(!isRoot[i]) {
			root = i;
			break;
		}
	}
	return root;
}
bool Isomorphic(int root1, int root2) {
	if(root1 == -1 && root2 == -1) return true;
	if((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1)) return false;
	if(T1[root1].data != T2[root2].data) return false;
	if(T1[root1].left == -1 && T2[root2].left == -1) {
		return Isomorphic(T1[root1].right, T2[root2].left);
	}
	if((T1[root1].left != -1 && T2[root2].left != -1) && 
	(T1[T1[root1].left].data == T2[T2[root2].left].data)) {
		return Isomorphic(T1[root1].left, T2[root2].left) && 
				Isomorphic(T1[root1].right, T2[root2].right);
	} else return Isomorphic(T1[root1].left, T2[root2].right) && 
					Isomorphic(T1[root1].right, T2[root2].left);
}
int main() {
	init();
	int root1 = buildtree(T1);
	int root2 = buildtree(T2);
	if(Isomorphic(root1, root2)) printf("Yes");
	else printf("No");
	return 0;
}
