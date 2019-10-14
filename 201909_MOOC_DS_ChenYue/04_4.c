#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TNode{
	int data;
	struct TNode *left, *right;
};
typedef struct TNode* PtrToTNode;
typedef PtrToTNode Tree;
PtrToTNode createnode(int data) {
	PtrToTNode t = (PtrToTNode)malloc(sizeof(struct TNode));
	t->left = t->right = NULL;
	t->data = data;
	return t;
}
Tree insert(Tree root, int data) {
	if(!root) root = createnode(data);
	else if(data < root->data) root->left = insert(root->left, data);
	else if(data > root->data) root->right = insert(root->right, data);
	return root;
}
bool issame(Tree root1, Tree root2) {
	if(!root1 && !root2) return true;
	else if((!root1 && root2) && (root1 && !root2)) return false;
	else {
		if(root1->data != root2->data) return false;
		else return issame(root1->left, root2->left) && issame(root1->right, root2->right);
	}
}
void destorytree(Tree root) {
	if(root->left) destorytree(root->left);
	if(root->right) destorytree(root->right);
	free(root);
}
int main() {
	int n, l;
	scanf("%d", &n);
	while(n) {
		scanf("%d", &l);
		Tree root1 = NULL;
		int i, data;
		for(i = 0; i < n; i++) {
			scanf("%d", &data);
			root1 = insert(root1, data);
		}
		while(l--) {
			Tree root2 = NULL;
			for(i = 0; i < n; i++) {
				scanf("%d", &data);
				root2 = insert(root2, data);
			}
			if(issame(root1, root2)) printf("Yes\n");
			else printf("No\n");
			destorytree(root2);
		}
		scanf("%d", &n);
		if(n == 0) destorytree(root1);
	}
	return 0;
}
