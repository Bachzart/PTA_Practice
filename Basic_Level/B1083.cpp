// way 1
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct cmp {
	bool operator()(const int k1, const int k2) {
		return k1 > k2;
	}
};
map<int, int, cmp> mp;

int main() {
	int n, tmp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		mp[abs(tmp - i)]++;
	}
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if(it->second >= 2) printf("%d %d\n", it->first, it->second);
	}
	return 0;
}

/*
// way 2

#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 10000 + 5;
int n, appear[maxn] = {0}, tmp;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		appear[abs(tmp - i)]++;
	}
	for(int i = 9999; i >= 0; i--) {
		if(appear[i] > 1) cout << i << ' ' << appear[i] << endl;
	}
	return 0;
}

*/
