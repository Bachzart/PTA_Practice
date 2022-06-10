#include <cstdio>
const int MAXN = 100000 + 10;
int sum[MAXN];
int n, S, nearS = 100000000 + 10;

int UpperBound(int L, int R, int x);

int main(int argc, char const *argv[]) {
	scanf("%d %d", &n, &S);
	sum[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	//find the approperiate 'nearS'
	for(int i = 1; i <= n; i++) {
		int j = UpperBound(i, n + 1, sum[i - 1] + S);
		if(sum[j - 1] - sum[i - 1] == S) {
			nearS = S;
			break;
		} else if(j <= n && sum[j] - sum[i - 1] < nearS) {
			//find the minimum
			nearS = sum[j] - sum[i - 1];
		}
	}
	//print
	for(int i = 1; i <= n; i++) {
		int j = UpperBound(i, n + 1, sum[i - 1] + nearS);
		if(sum[j - 1] - sum[i - 1] == nearS) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}

int UpperBound(int L, int R, int x) {
	int left = L, right = R, mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(sum[mid] > x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}


/* sliding window + prefixsum */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> ans1, ans2;
const int maxn = 100000 + 5;
int arr[maxn];
long long prefixsum[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	prefixsum[1] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefixsum[i + 1] = prefixsum[i] + arr[i]; 
	}
	int left = 1, right = 2, minimum = 1000;
	while(left <= n) {
		while(right <= n + 1) {
			if(prefixsum[right] - prefixsum[left] < m) right++;
			else if(prefixsum[right] - prefixsum[left] == m) {
				if(right > left) ans1.push_back({left, right - 1});
				else if(right == left) ans1.push_back({left - 1, right - 1});
				break;
			} else if(prefixsum[right] - prefixsum[left] > m) {
				int tmp = prefixsum[right] - prefixsum[left] - m;
				if(tmp < minimum) {
					ans2.clear();
					minimum = tmp;
					if(right > left) ans2.push_back({left, right - 1});
					else if(right == left) ans2.push_back({left - 1, right - 1});
				} else if(tmp == minimum) {
					if(right > left) ans2.push_back({left, right - 1});
					else if(right == left) ans2.push_back({left - 1, right - 1});
				} 
				break; 
			}
		}
		left++;
	}
	if(ans1.size() != 0) {
		sort(ans1.begin(), ans1.end());
		for(auto p: ans1) {
			cout << p.first << '-' << p.second << endl;
		}
	} else {
		sort(ans2.begin(), ans2.end());
		for(auto p: ans2) {
			cout << p.first << '-' << p.second << endl;
		}
	}
	return 0;
} 