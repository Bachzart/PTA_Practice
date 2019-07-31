#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100005;
const int Table = 2 * maxn;
struct node{
	int address, next, key;
	int order;
} Node[maxn];
bool isExist[Table] = {false};
bool cmp(node a, node b) {
	return a.order < b.order;
}

int main(int argc, char const *argv[]) {
	for(int i = 0; i < maxn; i++) {
		Node[i].order = 2 * maxn;
	}
	int n, head, address;
	scanf("%d %d", &head, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d %d", &Node[address].key, &Node[address].next);
		Node[address].address = address;
	}
	int countValid = 0, countRemoved = 0, p = head;
	while(p != -1) {
		if(!isExist[abs(Node[p].key)]) {
			isExist[abs(Node[p].key)] = true;
			Node[p].order = countValid++;
		} else {
			Node[p].order = maxn + countRemoved++;
		}
		p = Node[p].next; 
	}
	sort(Node, Node + maxn, cmp);
	int count = countValid + countRemoved;
	for(int i = 0; i < count; i++) {
		if(i != countValid - 1 && i != count - 1) {
			printf("%05d %d %05d\n", Node[i].address, Node[i].key, 
			Node[i + 1].address);
		} else {
			printf("%05d %d -1\n", Node[i].address, Node[i].key);
		}
	} 
	return 0;
}
