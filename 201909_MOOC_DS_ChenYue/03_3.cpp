#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int maxn = 30 + 5;
struct node{
	int left, right;
	int data;
} Tree[maxn];
int in[maxn], pre[maxn], n;
void init() {
	for(int i = 0; i < maxn; i++) {
		Tree[i].left = Tree[i].right = -1;
	}
}
int buildtree(int preL, int preR, int inL, int inR) {
	if(preL > preR) return -1;
	Tree[preL].data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;
	Tree[preL].left = buildtree(preL + 1, preL + numLeft, inL, k - 1);
	Tree[preL].right = buildtree(preL + numLeft + 1, preR, k + 1, inR);
	return preL;
}
int num = 0;
void postorder(int root) {
	if(root == -1) return;
	postorder(Tree[root].left);
	postorder(Tree[root].right);
	cout << Tree[root].data;
	if(num < n - 1) cout << ' ';
	num++;
}
int main() {
	init();
	string ope;
	int node, cnt1 = 0, cnt2 = 0;
	cin >> n;
	stack<int> st;
	for(int i = 0; i < 2 * n; i++) {
		cin >> ope;
		if(ope == "Push") {
			cin >> node;
			pre[cnt1++] = node;
			st.push(node);
		} else if(ope == "Pop") {
			in[cnt2++] = st.top();
			st.pop();
		}
	}
	buildtree(0, n - 1, 0, n - 1);
	postorder(0);
	return 0;
}
