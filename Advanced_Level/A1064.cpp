#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, number[maxn], CBT[maxn], index = 0;

void inorder(int root) {
	if(root > n) return;
	inorder(2 * root);
	CBT[root] = number[index++];
	inorder(root * 2 + 1);
}

int main(int argc, char const *argv[]) {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number, number + n);
	inorder(1);
	for(int i = 1; i <= n; i++) {
		cout << CBT[i];
		if(i < n) cout << ' ';
	}
	return 0;
}
