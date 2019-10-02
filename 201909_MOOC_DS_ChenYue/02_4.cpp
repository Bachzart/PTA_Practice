#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1000 + 10;
int seq[maxn];
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	bool flag = true;
	while(k--) {
		stack<int> st;
		for(int i = 1; i <= n; i++) {
			cin >> seq[i];
		}
		bool flag = true;
		int i = 1, j = 1;
		while(j <= n + 1) {
			if(st.size() > m) {
				flag = false;
				break;
			}
			if(!st.empty()) {
				if(st.top() == seq[i]) {
					st.pop();
					i++;
				} else st.push(j++);
			} else st.push(j++);
		}
		if(flag && st.size() == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
} 
/*
some samples:
in:
5 7 1
5 6 4 3 7 2 1
out:
YES

some sample:
in:
2 4 4
1 2 3 4
2 1 3 4
1 2 4 3
3 1 2 4
out:
YES
YES
YES
NO
*/
