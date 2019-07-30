#include <cstdio>
#include <cstring>
const int maxn = 100010;

struct Node{
	char data;
	int next;
	bool flag;
} node[maxn];

int main(int argc, char const *argv[]) {
	for(int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	int head1, head2, n;
	scanf("%d %d %d", &head1, &head2, &n);
	int address, next;
	char data;
	for(int i = 0; i < n; i++) {
		scanf("%d %c %d", &address, &data, &next);
		node[address].next = next;
		node[address].data = data;
	}
	int p;
	for(p = head1; p != -1; p = node[p].next) {
		node[p].flag = true;
	}
	for(p = head2; p != -1; p = node[p].next) {
		if(node[p].flag == true) break;
	}
	if(p != -1) {
		printf("%05d\n", p);
	} else {
		printf("-1\n");
	}
	return 0;
}
