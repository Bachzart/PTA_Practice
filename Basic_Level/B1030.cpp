/* way 1: use two pointer */
#include <cstdio>
#include <algorithm>
using namespace std; 
const int MAXN = 100000 + 10;
int n, p, Num[MAXN];
int BinarySearch(int i, long long x);

int main(int argc, char const *argv[]) {
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &Num[i]);
	}
	sort(Num, Num + n);
	int i = 0, j = 0, ans = 1;
	while(i < n && j < n) {
		while(j < n && Num[j] <= (long long)Num[i] * p) {
			ans = max(ans, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d", ans);
	return 0;
}

/* way 2: use binary search

#include <cstdio>
#include <algorithm>
using namespace std; 
const int MAXN = 100000 + 10;
int n, p, Num[MAXN];
int BinarySearch(int i, long long x);

int main(int argc, char const *argv[]) {
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &Num[i]);
	}
	sort(Num, Num + n);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		// you can also use upper_bound function
        // int j = upper_bound(Num + i + 1, Num + n, (long long)Num[i] * p) - Num;
		int j = BinarySearch(i, (long long)Num[i] * p);
		ans = max(ans, j - i);
	}
	printf("%d", ans);
	return 0;
}

int BinarySearch(int i, long long x) {
	if(Num[n - 1] <= x) {
		return n;
	}
	int left = i + 1, right = n - 1, mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(Num[mid] <= x) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

*/
