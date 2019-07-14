#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;
string str[MAXN];
bool cmp(string a, string b);

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	string ans;
	for(int i = 0; i < n; i++) {
		ans += str[i];
	}
	while(ans.size() != 0 && ans[0] == '0') {
		ans.erase(ans.begin());
	}
	if(ans.size() == 0) {
		cout << 0;
	} else {
		cout << ans;
	}
	return 0;
}

bool cmp(string a, string b) {
	return a + b < b + a;
}
