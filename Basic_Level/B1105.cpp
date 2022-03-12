#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 100000 + 5;
struct node {
	int address, data, next;
} L[maxn], L1[maxn], L2[maxn];
stack<node> lrev;
int newlist(int head, node *l) {
	int p = head, count = 0;
	while(p != -1) {
		l[p].address = p, l[p].data = L[p].data, l[p].next = L[p].next;
		p = L[p].next;
		count++;
	}
	return count;
}
void printlist(int head1, int head2, int n1, int n2, node *l1, node *l2) {
	int p = head1, n = n1 + n2, count = 0;
	while(p != -1) {
		lrev.push(l1[p]);
		p = l1[p].next;
	}
	p = head2;
	node tmp;
	for(int i = 0; i < n; i++) {
		if(count == 0) {
			if(l2[p].next != -1) printf("%05d %d %05d\n", l2[p].address, l2[p].data, l2[p].next);
			else printf("%05d %d -1\n", l2[p].address, l2[p].data);
			p = l2[p].next;
			count++;
		} else if(count == 1) {
			if(i == n - 1) printf("%05d %d -1\n", l2[p].address, l2[p].data);
			else {
				if(!lrev.empty()) {
					tmp = lrev.top();
					printf("%05d %d %05d\n", l2[p].address, l2[p].data, tmp.address);
				} else {
					printf("%05d %d %05d\n", l2[p].address, l2[p].data, l2[p].next);
				}
			}
			p = l2[p].next;
			count++;
		} else if(count == 2) {
			if(!lrev.empty()) {
				tmp = lrev.top();
				lrev.pop();
				if(i != n - 1) printf("%05d %d %05d\n", tmp.address, tmp.data, l2[p].address);
				else printf("%05d %d -1\n", tmp.address, tmp.data);
			} else i--;
			count = 0;
		}
	}
}
int main() {
	int p, head1, head2, n, n1, n2;
	scanf("%d %d %d", &head1, &head2, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p);
		scanf("%d %d", &L[p].data, &L[p].next);
		L[p].address = p;
	}
	n1 = newlist(head1, L1);
	n2 = newlist(head2, L2);
	if(n1 < n2) printlist(head1, head2, n1, n2, L1, L2);
	else printlist(head2, head1, n2, n1, L2, L1);
	return 0;
}

/*
in:
00100 01000 7
02233 2 34891
00100 6 00001
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
00001 7 -1
out:
01000 1 02233
02233 2 00001
00001 7 34891
34891 3 10086
10086 4 00100
00100 6 00033
00033 5 -1

in:
01000 00100 7
02233 2 34891
00100 6 00001
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
00001 7 -1
out:
01000 1 02233
02233 2 00001
00001 7 34891
34891 3 10086
10086 4 00100
00100 6 00033
00033 5 -1

in:
00100 01000 6
02233 2 34891
00100 6 -1
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
out:
01000 1 02233
02233 2 00100
00100 6 34891
34891 3 10086
10086 4 00033
00033 5 -1

*/
