#include <iostream>
using namespace std;
struct node {
	int data, height;
	struct node *left, *right;
};
typedef struct node* PtrToTNode;
typedef PtrToTNode Tree;
int Getheight(PtrToTNode root) {
	if(!root) return -1;
	else return root->height;
}
Tree RRrotate(Tree root) {
	PtrToTNode tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	tmp->height = max(Getheight(tmp->left), Getheight(tmp->right)) + 1;
	root->height = max(Getheight(root->left), Getheight(root->right)) + 1;
	return tmp;
}
Tree LLrotate(Tree root) {
	PtrToTNode tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	tmp->height = max(Getheight(tmp->left), Getheight(tmp->right)) + 1;
	root->height = max(Getheight(root->left), Getheight(root->right)) + 1;
	return tmp;
}
Tree RLrotate(Tree root) {
	root->right = LLrotate(root->right);
	return RRrotate(root);
}
Tree LRrotate(Tree root) {
	root->left = RRrotate(root->left);
	return LLrotate(root);
}
Tree insert(Tree root, int data) {
	if(!root) {
		root = new node;
		root->data = data;
		root->height = 0;
		root->left = root->right = NULL;
	} else if(data > root->data) {
		root->right = insert(root->right, data);
		if(Getheight(root->left) - Getheight(root->right) == -2) {
			if(data > root->right->data) root = RRrotate(root);
			else root = RLrotate(root);
		}
	} else if(data < root->data) {
		root->left = insert(root->left, data);
		if(Getheight(root->left) - Getheight(root->right) == 2) {
			if(data < root->left->data) root = LLrotate(root);
			else root = LRrotate(root);
		}
	}
	root->height = max(Getheight(root->left), Getheight(root->right)) + 1;
	return root;
}
Tree buildtree() {
	int n, data;
	cin >> n;
	Tree root = NULL;
	while(n--) {
		cin >> data;
		root = insert(root, data);
	}
	return root;
}
int main() {
	Tree root = buildtree();
	cout << root->data;
	return 0;
}
