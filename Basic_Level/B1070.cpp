#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
int num[maxn] = {0};
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	int res = num[0]; 
	for(int i = 1; i < n; i++) {
		res = (res + num[i]) / 2;
	}
	cout << res;
	return 0;
}
