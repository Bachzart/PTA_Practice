#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
struct node {
	int addr, data, next;
	int order;
} L[maxn];
void Init() {
	for(int i = 0; i < maxn; i++) {
		L[i].order = maxn;
	}
}
bool cmp(node a, node b) {
	return a.order < b.order;
}

int main() {
	Init();
	int head, n, k, tmp;
	scanf("%d %d %d", &head, &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		scanf("%d %d", &L[tmp].data, &L[tmp].next);
		L[tmp].addr = tmp;
	}
	int p = head, count = 0;
	while(p != -1) {
		L[p].order = count++;
		p = L[p].next;
	}
	sort(L, L + maxn, cmp);
	n = count;
	for(int i = n / k; i >= 0; i--) {
		int j = i * k;
		if(i == n / k) {
			for(; j < n; j++) {
				if(j == n - 1) printf("%05d %d %05d\n", L[j].addr, L[j].data, L[(i - 1) * k].addr);
				else printf("%05d %d %05d\n", L[j].addr, L[j].data, L[j].next);
			}
		} else {
			if(i != 0) {
				for(; j < (i + 1) * k; j++) {
					if(j == (i + 1) * k - 1) printf("%05d %d %05d\n", L[j].addr, L[j].data, L[(i - 1) * k].addr);
					else printf("%05d %d %05d\n", L[j].addr, L[j].data, L[j].next);
				}
			} else {
				for(; j < k; j++) {
					if(j == k - 1) printf("%05d %d -1\n", L[j].addr, L[j].data);
					else printf("%05d %d %05d\n", L[j].addr, L[j].data, L[j].next);
				}
			}
		}
	}
	return 0;
}
