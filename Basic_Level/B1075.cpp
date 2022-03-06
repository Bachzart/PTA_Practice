#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
struct Node {
	int address, data, next;
	int order;
} node[maxn], nod[maxn];
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	for(int i = 0; i < maxn; i++) {
		node[i].order = maxn;
	}
	int begin, n, k, address;
	scanf("%d %d %d", &begin, &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d %d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin, count = 0;
	while(p != -1) {
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = count;
	count = 0;
	for(int i = 0; i < n; i++) {
		if(node[i].data < 0) nod[count++] = node[i];
	}
	for(int i = 0; i < n; i++) {
		if(0 <= node[i].data && node[i].data <= k) nod[count++] = node[i];
	}
	for(int i = 0; i < n; i++) {
		if(node[i].data > k) nod[count++] = node[i];
	}
	for(int i = 0; i < count; i++) {
		if(i != count - 1) printf("%05d %d %05d\n", nod[i].address, nod[i].data, nod[i + 1].address);
		else printf("%05d %d -1\n", nod[i].address, nod[i].data);
	}
	return 0;
}