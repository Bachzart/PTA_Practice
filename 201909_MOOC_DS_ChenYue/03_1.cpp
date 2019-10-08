#include <iostream>
using namespace std;
const int maxn = 10 + 5;
struct node{
	int left, right;
	char data;
} T1[maxn], T2[maxn];
void init() {
	for(int i = 0; i < maxn; ++i) {
		T1[i].left = T1[i].right = T2[i].left = T2[i].right = -1;
	}
}
int buildtree(node T[]) {
	bool isRoot[maxn] = {false};
	int number;
	cin >> number;
	char data, lc, rc;
	for(int i = 0; i < number; ++i) {
		cin >> data >> lc >> rc;
		T[i].data = data;
		if(lc != '-') {
			T[i].left = lc - '0';
			isRoot[lc - '0'] = true;
		} 
		if(rc != '-') {
			T[i].right = rc - '0';
			isRoot[rc - '0'] = true;
		}
	}
	int root = -1;
	for(int i = 0; i < number; ++i) {
		if(!isRoot[i]) {
			root = i;
			break;
		}
	}
	return root;
}
bool isomorphic(int root1, int root2) {
	if(root1 == -1 && root2 == -1) return true;
	if((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1)) return false;
	if(T1[root1].data != T2[root2].data) return false;
	if(T1[root1].left == -1 && T2[root2].left == -1) {
		return isomorphic(T1[root1].right, T2[root2].right);
	}
	if((T1[root1].left != -1 && T2[root2].left != -1) && 
	(T1[T1[root1].left].data == T2[T2[root2].left].data)) {
		return isomorphic(T1[root1].left, T2[root2].left) && 
			   isomorphic(T1[root1].right, T2[root2].right);
	} else return isomorphic(T1[root1].left, T2[root2].right) &&
				  isomorphic(T1[root1].right, T2[root2].left);
}
int main() {
	init();
	int root1 = buildtree(T1);
	int root2 = buildtree(T2);
	if(isomorphic(root1, root2)) cout << "Yes";
	else cout << "No";
	return 0;
} 

/*
some samples:
in:
0
0
out: 
Yes

*/
