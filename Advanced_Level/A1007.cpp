/* method 1: dynamic programming
*/
#include <iostream>
using namespace std;
const int maxn = 10010;
int a[maxn], dp[maxn];
int s[maxn] = {0};
int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	bool flag = false;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] >= 0) flag = true;
	}
	if(flag == false) {
		cout << 0 << ' ' << a[0] << ' ' << a[n - 1];
	} else {
		dp[0] = a[0];
		for(int i = 1; i < n; i++) {
			if(dp[i - 1] + a[i] > a[i]) {
				dp[i] = dp[i - 1] + a[i];
				s[i] = s[i - 1];
			} else {
				dp[i] = a[i];
				s[i] = i;
			}
		}
		int k = 0;
		for(int i = 1; i < n; i++) {
			if(dp[i] > dp[k]) {
				k = i;
			}
		}
		cout << dp[k] << ' ' << a[s[k]] << ' ' << a[k];
	}
	return 0;
}

/* method 2: online-processing
#include <iostream>
using namespace std;
const int maxk = 10010;
int main(int argc, char *argv[]) {
	int k, arr[maxk] = {0};
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	int ThisSum = 0, MaxSum = -1;
	int left = 0, right = k - 1, temp_left = 0;
	for(int i = 0; i < k; i++) {
		ThisSum += arr[i];
		if(ThisSum > MaxSum) {
			MaxSum = ThisSum;
			right = i;
			left = temp_left;
		} else if(ThisSum < 0) {
			ThisSum = 0;
			temp_left = i + 1;
		}
	}
	if(MaxSum < 0) cout << 0 << ' ' << arr[left] << ' ' << arr[right];
	else cout << MaxSum << ' ' << arr[left] << ' ' << arr[right];
	return 0;
}

*/
