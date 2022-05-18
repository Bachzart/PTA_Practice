#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int pos[MAXN];

int main(int argc, char const *argv[]) {
	int n, ans = 0;
	scanf("%d", &n);
	int left = n - 1, num;
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && num != 0) {
			left--;
		}
	}
	int k = 1;
	while(left > 0) {
		if(pos[0] == 0) {
			while(k < n) {
				if(pos[k] != k) {
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d\n", ans);
	return 0;
}

/* C++ */
#include <iostream>
#include <unordered_map>
using namespace std;
const int maxn = 100000 + 5;
int arr[maxn];
unordered_map<int, int> numandindex;

int main() {
	int n, cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		numandindex[arr[i]] = i;
	}
	int index0 = numandindex[0], i = 0;
	while(true) {
		if(index0 == 0) {
			for(; i < n; i++) {
				if(arr[i] != i) break;
			}
			if(i != n) {
				numandindex[arr[i]] = 0;
				numandindex[0] = i;
			} else break;
		}
		int index = numandindex[index0];
		swap(arr[index0], arr[index]);
		cnt++;
		index0 = index;
	}
	cout << cnt;
	return 0;
} 