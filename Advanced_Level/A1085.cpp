/* method 1: use two pointers
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
long long n, p, Num[MAXN];

int main(int argc, char const *argv[]) {
	scanf("%lld %lld", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &Num[i]);
	}
	sort(Num, Num + n);
	int i, j = 0, ans = 0;
	while(i < n && j < n) {
		long long temp = Num[i] * p;
		while(j < n && Num[j] <= temp) {
			ans = max(ans, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d", ans);
}

/* method 2: use dichotomy

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
long long n, p, Num[MAXN];
int BinarySearch(int i, long long x);

int main(int argc, char const *argv[]) {
	scanf("%lld %lld", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &Num[i]);
	}
	sort(Num, Num + n);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		int j = BinarySearch(i, Num[i] * p);
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
