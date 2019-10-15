#include <stdio.h>
#include <stdlib.h>
#define maxn 1005
int n, tree[maxn], seq[maxn], inde = 0;
void inorder(int root) {
	if(root > n) return;
	inorder(2 * root);
	tree[root] = seq[inde++];
	inorder(2 * root + 1);
}
int cmp(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}
int main() {
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
	}
	qsort(seq, n, sizeof(seq[0]), cmp);
	inorder(1);
	for(i = 1; i <= n; ++i) {
		printf("%d", tree[i]);
		if(i < n) printf(" ");
	}
	return 0;
}
