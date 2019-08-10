#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 25;
struct node {
	int v, height;
	node *left, *right;
} *root;
int n;

node *newnode(int v) {
	node *Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->left = Node->right = NULL;
	return Node;
}

int getheight(node *root) {
	if(root == NULL) return 0;
	return root->height;
}

void updateheight(node *root) {
	root->height = max(getheight(root->left), getheight(root->right)) + 1;
}

int getbalancefactor(node *root) {
	return getheight(root->left) - getheight(root->right);
}

void leftRotation(node *&root) {
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}

void rightRotation(node *&root) {
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}

void insert(node *&root, int v) {
	if(root == NULL) {
		root = newnode(v);
		return;
	}
	if(v < root->v) {
		insert(root->left, v);
		updateheight(root);
		if(getbalancefactor(root) == 2) {
			if(getbalancefactor(root->left) == 1) {
				rightRotation(root);
			} else if(getbalancefactor(root->left) == -1) {
				leftRotation(root->left);
				rightRotation(root);
			}
		}
	} else {
		insert(root->right, v);
		updateheight(root);
		if(getbalancefactor(root) == -2) {
			if(getbalancefactor(root->right) == -1) {
				leftRotation(root);
			} else if(getbalancefactor(root->right) == 1) {
				rightRotation(root->right);
				leftRotation(root);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	cin >> n;
	int value;
	for(int i = 0; i < n; i++) {
		cin >> value;
		insert(root, value);
	}
	cout << root->v;
	return 0;
}
