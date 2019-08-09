#include <iostream>
#include <vector>
using namespace std;
struct node {
	int data;
	node *left, *right; 
};

void insert(node *&root, int data) {
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if(data < root->data) insert(root->left, data);
	else insert(root->right, data);
}
void preorder(node *root, vector<int> &vi) {
	if(root == NULL) return;
	vi.push_back(root->data);
	preorder(root->left, vi);
	preorder(root->right, vi);
}
void preordermirror(node *root, vector<int> &vi) {
	if(root == NULL) return;
	vi.push_back(root->data);
	preordermirror(root->right, vi);
	preordermirror(root->left, vi);
}
void postorder(node *root, vector<int> &vi) {
	if(root == NULL) return;
	postorder(root->left, vi);
	postorder(root->right, vi);
	vi.push_back(root->data);
}
void postordermirror(node *root, vector<int> &vi) {
	if(root == NULL) return;
	postordermirror(root->right, vi);
	postordermirror(root->left, vi);
	vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;
int main(int argc, char const *argv[]) {
	int n, data;
	node *root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preorder(root, pre);
	preordermirror(root, preM);
	postorder(root, post);
	postordermirror(root, postM);
	if(origin == pre) {
		cout << "YES\n";
		for(int i = 0; i < post.size(); i++) {
			cout << post[i];
			if(i < post.size() - 1) cout << ' ';
		}
	} else if(origin == preM) {
		cout << "YES\n";
		for(int i = 0; i < postM.size(); i++) {
			cout << postM[i];
			if(i < postM.size() - 1) cout << ' ';
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}
