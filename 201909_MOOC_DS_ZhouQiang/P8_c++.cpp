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
		void countleaves(BinNode<Elem> *r, int &sum) {
			if(r == NULL) return;
			if(r->left == NULL && r->right == NULL) {
				sum += r->data;
			}
			countleaves(r->left, sum);
			countleaves(r->right, sum);
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
		int count() {
			int sum = 0;
			countleaves(root, sum);
			return sum;
		}
};
int main() {
	int n, root;
	cin >> n >> root;
	BinTree<int> bt(root);
	int parent, type, child;
	for(int i = 1; i < n; i++) {
		cin >> parent >> type >> child;
		bt.insert(parent, type, child);
	}
	cout << bt.count();
	return 0;
}

 

/*
some samples:
in:
6
20
20 0 30
20 1 60
30 0 5
30 1 10
60 0 30
out:
45

in:
6
20
20 0 30
20 1 60
30 0 5
30 1 10
60 0 15
out:
30
*/
