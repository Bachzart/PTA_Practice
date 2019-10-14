#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int node[maxn] = {0}, seq[maxn] = {0}, n, index = 0;
void inorder(int root) {
	if(root > n) return;
	inorder(2 * root);
	node[root] = seq[index++];
	inorder(root * 2 + 1);
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	sort(seq, seq + n);
	inorder(1);
	for(int i = 1; i <= n; i++) {
		cout << node[i];
		if(i < n) cout << ' ';
	}
	return 0;
}
