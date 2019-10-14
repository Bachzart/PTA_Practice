/* constitute two trees and their preordered sequence, then compare these 
sequence is same or not */
#include <iostream>
using namespace std;
const int maxn = 15;
struct TNode {
	int data;
	struct TNode *left, *right;
};
typedef struct TNode* PtrToTNode;
typedef PtrToTNode Tree;
Tree insert(Tree root, int data) {
	if(!root) {
		root = new TNode;
		root->data = data;
		root->left = root->right = NULL;
	} else {
		if(data < root->data) root->left = insert(root->left, data);
		else if(data > root->data) root->right = insert(root->right, data);
	}
	return root;
}
void preorder(Tree root, int sequence[], int &index) {
	if(!root) return;
	sequence[index++] = root->data;
	preorder(root->left, sequence, index);
	preorder(root->right, sequence, index);
}
void destorytree(Tree root) {
	if(root->left) destorytree(root->left);
	if(root->right) destorytree(root->right);
	delete root;
}
int main() {
	int n, l;
	cin >> n;
	while(n) {
		cin >> l;
		int data;
		Tree root1 = NULL;
		int seq1[maxn], seq2[maxn];
		for(int i = 0; i < n; ++i) {
			cin >> data;
			root1 = insert(root1, data);
		}
		int index = 0;
		preorder(root1, seq1, index);
		while(l--) {
			Tree root2 = NULL;
			for(int i = 0; i < n; ++i) {
				cin >> data;
				root2 = insert(root2, data);
			}
			index = 0;
			bool flag = true;
			preorder(root2, seq2, index);
			for(int i = 0; i < n; i++) {
				if(seq1[i] != seq2[i]) {
					flag = false;
					break;
				}
			}
			if(flag) cout << "Yes\n";
			else cout << "No\n";
			destorytree(root2);
		}
		cin >> n;
		if(n == 0) destorytree(root1);
	}
	return 0;
}
