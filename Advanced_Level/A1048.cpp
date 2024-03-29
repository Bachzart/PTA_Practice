/* method 1: use two pointers
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int coins[MAXN];

int main(int argc, char const *argv[]) {
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + N);
	int i = 0, j = N - 1;
	while(i < j) {
		int temp = coins[i] + coins[j];
		if(temp == M) {
			break;
		} else if(temp < M) {
			i++;
		} else {
			j--;
		}
	}
	if(i >= j) {
		printf("No Solution\n");
	} else {
		printf("%d %d\n", coins[i], coins[j]);
	}
	return 0;
}

/* method 2: use dichotomy

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int coins[MAXN];

int BinarySearch(int *array, int left, int right, int x);

int main(int argc, char const *argv[]) {
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins + 1, coins + N + 1);
	int i;
	for(i = 1; i <= N; i++) {
		int pos = BinarySearch(coins, 1, N, M - coins[i]);
		if(pos != -1 && pos != i) {
			printf("%d %d\n", coins[i], coins[pos]);
			break;
		}
	}
	if(i - 1 == N) {
		printf("No Solution\n");
	}
	return 0;
}

int BinarySearch(int *array, int left, int right, int x) {
	int mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(array[mid] == x) {
			return mid;
		} else if(array[mid] > x) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

/* method 3: use hash

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int main(int argc, char const *argv[]) {
	int N, M, coins[MAXN];
	scanf("%d %d", &N, &M);
	int value[MAXN] = {0};
	for(int i = 1; i <= N; i++) {
		scanf("%d", &coins[i]);
		value[coins[i]]++;
	}
	sort(coins + 1, coins + N + 1);
	int i, v1, v2;
	bool flag = false;
	for(i = 1; i <= N; i++) {
		v1 = coins[i];
		v2 = M - v1;
		if(value[v1] && value[v2]) {
			if(v1 == v2 && value[v1] != 2) {
				break;
			}
			printf("%d %d", v1, v2);
			flag = true;
			break;
		}
	}
	if(!flag) {
		printf("No Solution");
	}
	return 0;
} 

/* hash with map
#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, m, tmp;
	cin >> n >> m;
	map<int, int> ht;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		ht[tmp]++;
	}
	bool flag = false;
	for(auto it = ht.begin(); it != ht.end(); it++) {
		int diff = m - it->first;
		if(diff == it->first) {
			if(it->second >= 2) {
				cout << it->first << ' ' << it->first;
				flag = true;
				break;
			}
		} else {
			if(ht.count(diff)) {
				cout << it->first << ' ' << diff;
				flag = true;
				break;
			}
		}
	}
	if(!flag) cout << "No Solution";
	return 0;
}

*/
