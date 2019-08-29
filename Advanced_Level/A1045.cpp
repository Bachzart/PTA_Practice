/* method 1: longest increasing sequence

#include <iostream>
#include <cstring>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int stripe[maxn], dp[maxn], hashTable[maxc];
int main(int argc, char const *argv[]) {
	int n, m, x;
	cin >> n >> m;
	memset(hashTable, -1, sizeof(hashTable));
	for(int i = 0; i < m; i++) {
		cin >> x;
		hashTable[x] = i;
	} 
	int l, num = 0;
	cin >> l;
	for(int i = 0; i < l; i++) {
		cin >> x;
		if(hashTable[x] >= 0) {
			stripe[num++] = hashTable[x]; 
		}
	}
	int ans = -1;
	for(int i = 0; i < num; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(stripe[j] <= stripe[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1; 
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}

*/
/*
method 2: longest common substring
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int A[maxc], B[maxn], dp[maxc][maxn];
int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> A[i];
	}
	int l;
	cin >> l;
	for(int i = 1; i <= l; i++) {
		cin >> B[i];
	}
	for(int i = 1; i <= m; i++) {
		dp[i][0] = 0;
	}
	for(int j = 1; j <= l; j++) {
		dp[0][j] = 0;
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= l; j++) {
			int Max = max(dp[i - 1][j], dp[i][j - 1]);
			if(A[i] == B[j]) {
				dp[i][j] = Max + 1;
			} else {
				dp[i][j] = Max;
			}
		}
	}
	cout << dp[m][l];
	return 0;
}
