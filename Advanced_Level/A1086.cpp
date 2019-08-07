#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
struct node {
	int data;
	node *lchild;
	node *rchild;
};
int n, pre[50], in[50], order;
stack<int> st;
node *create(int preL, int preR, int inL, int inR) {
	if(preL > preR) {
		return NULL;
	}
	node *root = new node;
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int num = 0;
void postorder(node *root) {
	if(root == NULL) return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d", root->data);
	if(num < n - 1) {
		printf(" ");
	}
	num++;
}

int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	char str[5];
	int x, preIndex = 0, inIndex = 0;
	for(int i = 0; i < 2 * n; i++) {
		scanf("%s", str);
		if(strcmp("Push", str) == 0) {
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		} else {
			in[inIndex++] = st.top();
			st.pop();
		}
	}
	node *root = create(0, n - 1, 0, n - 1);
	postorder(root);
	return 0;
}
