#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 100 + 5;
vector<string> chinese(maxn);
bool issame(vector<string>& chinese, int chinese_length) {
	for(int i = 0; i < chinese_length / 2; i++) {
		if(chinese[i] != chinese[chinese_length - i - 1]) return false;
	}
	return true;
}
int main() {
	int n;
	char c;
	cin >> c >> n;
	getchar();
	for(int i = 0; i < n; i++) {
		getline(cin, chinese[i]);
	}
	if(issame(chinese, n)) {
		cout << "bu yong dao le" << endl;
	}
	for(int i = n - 1; i >= 0; i--) {
		for(int j = chinese[i].length() - 1; j >= 0; j--) {
			if(chinese[i][j] != ' ') cout << c;
			else cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
