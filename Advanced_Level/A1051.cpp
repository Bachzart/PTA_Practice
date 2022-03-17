#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1000 + 5;
int seq[maxn] = {0};

int main() {
	int n, m, k, tmp;
	cin >> m >> n >> k;
	while(k--) {
		for(int i = 1; i <= n; i++) {
			cin >> seq[i];
		}
		int index = 1;
		bool flag = true;
		stack<int> st;
		for(int i = 1; i <= n; i++) {
			st.push(i);
			if(st.size() > m) {
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == seq[index]) {
				st.pop();
				index++;
			}
		}
		if(st.empty() && flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
