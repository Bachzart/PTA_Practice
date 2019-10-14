#include <iostream>
#include <stack>
using namespace std;
template<class Elem>
struct BinNode {
	Elem data;
	BinNode<Elem> *left;
	BinNode<Elem> *right;
	BinNode(Elem x) {
		data = x;
		left = right = NULL;
	}
};
template<class Elem>
class BinTree {
	protected:
		BinNode<Elem> *root;
		BinNode<Elem> *rfindx(Elem x, BinNode<Elem> *r) {
			if(!r) return NULL;
			if(r->data == x) return r;
			BinNode<Elem> *found;
			found = rfindx(x, r->left);
			return found ? found : rfindx(x, r->right);
		}
		void rinorder(BinNode<Elem> *r) {
			if(!r) return;
			rinorder(r->left);
			cout << r->data << endl;
			rinorder(r->right);
		}
		bool risbinarysearchtree(BinNode<Elem> *r) {
			if(!r->left && !r->right) return true;
			else if(r->left && !r->right && r->left->data < r->data) {
				return risbinarysearchtree(r->left);
			} else if(!r->left && r->right && r->right->data > r->data) {
				return risbinarysearchtree(r->right);
			} else if(r->left && r->right) {
				if(r->left->data < r->data && r->right->data > r->data) {
					return risbinarysearchtree(r->left) && 
					risbinarysearchtree(r->right);
				} else return false;
			}
		}
	public:
		BinTree() {
			root = NULL;
		}
		BinTree(Elem r) {
			root = new BinNode<Elem>(r);
		}
		~BinTree() { }
		BinNode<Elem>* findx(Elem x) {
			return rfindx(x, root);
		}
		bool insert(Elem p, int LorR, Elem x) {
			BinNode<Elem> *found;
			found = findx(p);
			if(!found) return false;
			if(LorR == 0) {
				if(found->left) return false;
				found->left = new BinNode<Elem>(x);
			} else {
				if(found->right) return false;
				found->right = new BinNode<Elem>(x);
			}
			return true;
		}
		void inorder() {
			rinorder(root);
		}
		bool isbinarysearchtree() {
			if(risbinarysearchtree(root)) cout << "Yes";
			else cout << "No";
		} 
};
int main() {
	int n, root;
	cin >> n;
	if(n == 0) {
		cout << "Yes";
		return 0;
	}
	cin >> root;
	BinTree<int> bt(root);
	int parent, type, child;
	for(int i = 1; i < n; i++) {
		cin >> parent >> type >> child;
		bt.insert(parent, type, child);
	}
	bt.inorder();
	bt.isbinarysearchtree();
	return 0;
}
