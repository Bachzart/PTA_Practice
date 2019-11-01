/* method 1: Do not build a tree. use recursion */
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 30 + 5; 
int in[maxn], pre[maxn], post[maxn], n;
void solve(int preL, int inL, int postL, int n) {
	if(n == 0) return;
	if(n == 1) {
		post[postL] = pre[preL];
		return;
	}
	int root = pre[preL], i;
	post[postL + n - 1] = root;
	for(i = 0; i < n; i++) {
		if(in[inL + i] == root) break;
	}
	int L = i, R = n - L - 1;
	solve(preL + 1, inL, postL, L);
	solve(preL + L + 1, inL + L + 1, postL + L, R);
}
int main() {
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
	solve(0, 0, 0, n);
	for(int i = 0; i < n; i++) {
		cout << post[i];
		if(i != n - 1) putchar(' ');
	}
	return 0;
}

/* method 2: use static tree 
 
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

*/
