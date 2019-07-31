#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct node{
	int address, data, next;
	int order;
} Node[maxn];

bool cmp(node a, node b) {
	return a.order < b.order;
}

int main(int argc, char const *argv[]) {
	for(int i = 0; i < maxn; i++) {
		Node[i].order = maxn;
	}
	int head, n, k, address;
	scanf("%d %d %d", &head, &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d %d", &Node[address].data, &Node[address].next);
		Node[address].address = address;
	}
	int p = head, count = 0;
	while(p != -1) {
		Node[p].order = count++;
		p = Node[p].next;
	}
	sort(Node, Node + maxn, cmp);
	n = count;
	for(int i = 0; i < n / k; i++) {
		for(int j = (i + 1) * k - 1; j > i * k; j--) {
			printf("%05d %d %05d\n", Node[j].address, Node[j].data, 
			Node[j - 1].address);
		}
		printf("%05d %d ", Node[i * k].address, Node[i * k].data);
		if(i < n / k - 1) {
			printf("%05d\n", Node[(i + 2) * k - 1].address);
		} else {
			if(n % k == 0) {
				printf("-1\n");
			} else {
				printf("%05d\n", Node[(i + 1) * k].address);
				for(int i = n / k * k; i < n; i++) {
					printf("%05d %d ", Node[i].address, Node[i].data);
					if(i < n - 1) {
						printf("%05d\n", Node[i + 1].address);
					} else {
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
