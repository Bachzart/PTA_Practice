#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TNode{
	int data, height;
	struct TNode *lchild, *rchild;
};
typedef struct TNode* PtrToTNode;
typedef PtrToTNode Tree;
int max(int a, int b) {
	return a > b ? a : b;
}
int getheight(Tree root) {
	if(!root) return -1;
	else return root->height;
}
Tree RRrotate(Tree root) {
	PtrToTNode t = root->rchild;
	root->rchild = t->lchild;
	t->lchild = root;
	t->height = max(getheight(t->lchild), getheight(t->rchild)) + 1;
	root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
	return t;
}
Tree LLrotate(Tree root) {
	PtrToTNode t = root->lchild;
	root->lchild = t->rchild;
	t->rchild = root;
	t->height = max(getheight(t->lchild), getheight(t->rchild)) + 1;
	root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
	return t;
}
Tree RLrotate(Tree root) {
	root->rchild = LLrotate(root->rchild);
	return RRrotate(root);
}
Tree LRrotate(Tree root) {
	root->lchild = RRrotate(root->lchild);
	return LLrotate(root);
}
Tree insert(Tree root, int data) {
	if(!root) {
		root = (Tree)malloc(sizeof(struct TNode));
		root->lchild = root->rchild = NULL;
		root->data = data;
		root->height = 0;
	} else if(data > root->data) {
		root->rchild = insert(root->rchild, data);
		if(getheight(root->rchild) - getheight(root->lchild) == 2) {
			if(data > root->rchild->data) root = RRrotate(root);
			else root = RLrotate(root);
		} 
	} else if(data < root->data) {
		root->lchild = insert(root->lchild, data);
		if(getheight(root->lchild) - getheight(root->rchild) == 2) {
			if(data < root->lchild->data) root = LLrotate(root);
			else root = LRrotate(root);
		}
	}
	root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
	return root;
}
int main() {
	int i, n, data;
	scanf("%d", &n);
	Tree root = NULL;
	for(i = 0; i < n; ++i) {
		scanf("%d", &data);
		root = insert(root, data);
	}
	printf("%d", root->data);
	return 0;
}
