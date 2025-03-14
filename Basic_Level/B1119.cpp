/*
method 1: dp
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> weight(n);
	for(int i = 0; i < n; ++i)
		cin >> weight[i];
	vector<int> dp(n, 200);
	for(int i = 1; i < n; ++i)
		if(weight[i] > weight[i - 1])
			dp[i] = max(dp[i], dp[i - 1] + 100);
		else if(weight[i] == weight[i - 1])
			dp[i] = max(dp[i], dp[i - 1]);
	
	for(int i = n - 2; i >= 0; --i)
		if(weight[i] > weight[i + 1])
			dp[i] = max(dp[i], dp[i + 1] + 100);
		else if(weight[i] == weight[i + 1])
			dp[i] = max(dp[i], dp[i + 1]);
	cout << accumulate(dp.begin(), dp.end(), 0);
	return 0;
}

/*
method 2: greedy

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> wei(n); 
	vector<int> w(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> wei[i];
	}
	for(int i = 0; i < n; ++i) {
		int leftlen = 0, rightlen = 0;
		for(int j = i - 1; j >=0 && wei[j] <= wei[j + 1]; --j) {
			if(wei[j] < wei[j + 1])
				++leftlen;
		}
		for(int j = i + 1; j < n && wei[j] <= wei[j - 1]; ++j) {
			if(wei[j] < wei[j - 1])
				++rightlen;
		}
		w[i] = leftlen > rightlen ? leftlen : rightlen;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += w[i] * 100 + 200; 
	}
	cout << ans;		
	return 0;
}

*/
