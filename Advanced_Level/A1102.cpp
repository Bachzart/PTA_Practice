#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
	int data;
	int lchild, rchild;
} Node[15]; 
int n;
bool isRoot[15] = {false};
int num = 0;
void levelorder(int root) {
	if(root == -1) return;
	queue<node> q;
	q.push(Node[root]);
	while(!q.empty()) {
		node top = q.front();
		q.pop();
		printf("%d", top.data);
		if(num < n - 1) {
			printf(" ");
			num++;
		}
		if(top.lchild != -1) q.push(Node[top.lchild]);
		if(top.rchild != -1) q.push(Node[top.rchild]);
	}
	putchar('\n');
}
int num2 = 0;
void inorder(int root) {
	if(root == -1) return;
	inorder(Node[root].lchild);
	printf("%d", Node[root].data);
	if(num2 < n - 1) {
		printf(" ");
		num2++;
	}
	inorder(Node[root].rchild);
}
int getroot() {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		if(!isRoot[i]) {
			ret = i;
			break;
		}
	}
	return ret;
}

void invert() {
	int i = 0;
	for(int i = 0; i < n; i++) {
		swap(Node[i].lchild, Node[i].rchild);
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	getchar();
	char left, right;
	for(int i = 0; i < n; i++) {
		scanf("%c %c", &left, &right);
		getchar();
		if(left != '-') {
			Node[i].lchild = left - '0';
			isRoot[left - '0'] = true;
		}
		else Node[i].lchild = -1;
		if(right != '-') {
			Node[i].rchild = right - '0';
			isRoot[right - '0'] = true;
		}
		else Node[i].rchild = -1;
		Node[i].data = i;
	}
	int root = getroot();
	invert();
	levelorder(root);
	inorder(root);
	return 0;
}
