#include <cstdio>
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	int tmp = gcd(a, b);
	return a * b / tmp;
}

int main() {
	int n1, m1, n2, m2, k;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	int t1 = lcm(m1, m2);
	int t2 = lcm(t1, k);
	if(n1 > n2) {
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	int left = n1 * t2 / m1, right = n2 * t2 / m2, tmp = t2 / k;
	bool flag = true;
	for(int i = left + 1; i < right; i++) {
		if(i % tmp == 0 && gcd(i / tmp, k) == 1) {
			if(flag) {
				printf("%d/%d", i / tmp, k);
				flag = false;
			} else {
				printf(" %d/%d", i / tmp, k);
			}
		}
	}
	return 0;
}

/*
in:
7/18 13/20 12
out:
5/12 7/12

in:
7/18 19/20 12
out:
5/12 7/12 11/12

in:
1/8 7/8 8
out:
3/8 5/8

in:
1/8 7/8 2
out:
1/2

in:
1/18 13/20 12
out:
1/12 5/12 7/12

in:
1/2 3/4 8
out:
5/8

in:
1/10 1/2 5
out:
1/5 2/5
*/