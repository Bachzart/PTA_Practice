#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int data;
	int left, right; 
} Node[maxn];
int n, number[maxn], index = 0;

void inorder(int root) {
	if(root == -1) return;
	inorder(Node[root].left);
	Node[root].data = number[index++];
	inorder(Node[root].right);
}
int num = 0;
void levelorder(int root) {
	if(root == -1) return;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		cout << Node[front].data;
		if(num < n - 1) {
			cout << ' ';
			num++;
		}
		if(Node[front].left != -1) q.push(Node[front].left);
		if(Node[front].right != -1) q.push(Node[front].right);
	}
}

int main(int argc, char const *argv[]) {
	cin >> n;
	int lchild, rchild;
	for(int i = 0; i < n; i++) {
		cin >> lchild >> rchild;
		Node[i].left = lchild, Node[i].right = rchild;
	}
	for(int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number, number + n);
	inorder(0);
	levelorder(0);
	return 0;
}
