#include <iostream>
#include <queue>
using namespace std;
const int maxn = 20;
struct node{
	int left, right;
} Tree[maxn];
bool isRoot[20] = {false};
void init() {
	for(int i = 0; i < maxn; i++) {
		Tree[i].left = Tree[i].right = -1;
	}
}
void levelorder(int root) {
	queue<int> q;
	q.push(root);
	bool flag = true;
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		if(Tree[tmp].left == -1 && Tree[tmp].right == -1) {
			if(flag) {
				cout << tmp;
				flag = false;
			} else {
				cout << ' ' << tmp;
			}
		} 
		if(Tree[tmp].left != -1) q.push(Tree[tmp].left);
		if(Tree[tmp].right != -1) q.push(Tree[tmp].right);
	}
}
int main() {
	init();
	int n;
	cin >> n;
	char c1, c2;
	for(int i = 0; i < n; ++i) {
		cin >> c1 >> c2;
		if(c1 != '-') {
			isRoot[c1 - '0'] = true;
			Tree[i].left = c1 - '0';
		}
		if(c2 != '-') {
			isRoot[c2 - '0'] = true;
			Tree[i].right = c2 - '0';
		}
	}
	int root;
	for(int i = 0; i < n; i++) {
		if(!isRoot[i]) {
			root = i;
			break;
		}
	}
	levelorder(root);
	return 0;
}
