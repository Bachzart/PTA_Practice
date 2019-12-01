#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 20000 + 10;
bool hashTable[maxn] = { 0 };
bool isprime(int n) {
	if (n <= 1) return false;
	else {
		int tmp = (int)sqrt(n);
		for (int i = 2; i <= tmp; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
}
int nextprime(int m) {
	while (!isprime(m)) m++;
	return m;
}
int hashfunc(int num, int hashkey) {
	return num % hashkey;
}
int main() {
	int m, n, tmp;
	cin >> m >> n;
	m = nextprime(m);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		int index = hashfunc(tmp, m);
		if (hashTable[index] == false) {
			hashTable[index] = true;
			if (i == 0) cout << index;
			else cout << ' ' << index;
		} else {
			int step;
			for (step = 1; step < m; step++) {
				index = hashfunc(tmp + step * step, m);
				if (hashTable[index] == false) {
					hashTable[index] = true;
					if (i == 0) cout << index;
					else cout << ' ' << index;
					break;
				}
			}
			if (step >= m) {
				if (i > 0) cout << ' ';
				cout << '-';
			}

		}
	}
	return 0;
}

/*
samples:
in:
4 4
10 6 4 15
out:
0 1 4 -

in:
5 5
10 6 4 15 25
out:
0 1 4 - -

in:
5 5
5 10 6 4 15 
out:
0 1 2 4 -

in:
1 1
1
out:
1

*/