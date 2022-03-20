#include <iostream>
using namespace std;
const int maxn = 1000 + 5;
int n, m, mooncake[maxn] = {0}, cakemax = -1, tmp;

int main() {
	cin >> n >> m;
	while(m--) {
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			mooncake[i] += tmp;
		}
	}
	for(int i = 0; i < n; i++) {
		if(mooncake[i] > cakemax) cakemax = mooncake[i];
	}
	cout << cakemax << endl;
	bool flag = false;
	for(int i = 0; i < n; i++) {
		if(mooncake[i] == cakemax) {
			if(!flag) {
				cout << i + 1;
				flag = true;
			} else cout << ' ' << i + 1;
		}
	}
	return 0;
}
