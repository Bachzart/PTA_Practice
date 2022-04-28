#include <cstdio>

bool PalindromicNum(long long *digits, long long count);

int main(int argc, char const *argv[]) {
	long long N, b, count = 0, digits[50] = {0};
	scanf("%lld %lld", &N, &b);
	while(N) {
		digits[count++] = N % b;
		N /= b;
	}
	count--;
	if(PalindromicNum(digits, count)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	for(; count > 0; count--) {
		printf("%lld ", digits[count]);
	}
	printf("%lld\n", digits[count]);
	return 0;
}

bool PalindromicNum(long long *digits, long long count) {
	bool flag = true;
	int i, j;
	if(count % 2 == 0) {
		i = j = count / 2;
	} else {
		i = count / 2;
		j = i + 1;
	}
	for(; i >= 0 && j <= count; i--, j++) {
		if(digits[i] != digits[j]) {
			flag = false;
			break;
		}
	}
	return flag;
}

/* simplification */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if(n == 0) {
		cout << "Yes\n" << 0;	
	} else {
		vector<int> digits;
		while(n) {
			digits.push_back(n % k);
			n /= k;
		}
		int size = digits.size();
		bool flag = true;
		for(int i = 0; i < size / 2; i++) {
			if(digits[i] != digits[size - i - 1]) {
				flag = false;
				break;
			}
		}
		if(flag) cout << "Yes\n";
		else cout << "No\n";
		for(int i = size - 1; i >= 0; i--) {
			cout << digits[i];
			if(i > 0) cout << ' ';
		}
	}
	return 0;
} 