#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
set<pair<int, int>> res;
bool isprime(int a) {
	if(a <= 1) return false;
	else {
		for(int i = 2; i <= sqrt(a); i++) {
			if(a % i == 0) return false;
		}
	}
	return true;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b); 
}
int digitsum(int a) {
	int res = 0;
	while(a != 0) {
		res = res + a % 10;
		a /= 10;
	}
	return res;
}
int main() {
	int N, n, k, m, tmp, g;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		printf("Case %d\n", i);
		scanf("%d %d", &k, &m);
		tmp = pow(10, k);
		bool flag = false;
		for(int j = 99 + pow(10, k - 1); j < tmp; j += 100) {
			if(digitsum(j) == m) {
				n = digitsum(j + 1);
				g = gcd(m, n);
				if(g > 2 && isprime(g)) {
					res.insert(make_pair(n, j));
					flag = true;
				}
			} 
		}
		if(!flag) printf("No Solution\n");
		else {
			set<pair<int, int>>::iterator it = res.begin();
			for(; it != res.end(); it++) {
				printf("%d %d\n", it->first, it->second);
			}
			res.clear();
		}
	}
	return 0;
}
