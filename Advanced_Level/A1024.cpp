#include <iostream>
#include <cstring>
using namespace std;
struct bign {
	int d[200], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char *str) {
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

bign reversebign(bign a) {
	int temp;
	for(int i = 0; i < a.len / 2; i++) {
		temp = a.d[i];
		a.d[i] = a.d[a.len - i - 1];
		a.d[a.len - i - 1] = temp;
	}
	return a;
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

bool isPalindromic(bign a) {
	for(int i = 0; i <= a.len / 2; i++) {
		if(a.d[i] != a.d[a.len - 1 - i]) return false;
	}
	return true;
}

void print(bign a) {
	for(int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	putchar('\n');
}

int main(int argc, char const *argv[]) {
	char str[150];
	int times, count = 0;
	scanf("%s %d", str, &times);
	bign a = change(str), rev;
	while(times--) {
		if(isPalindromic(a)) {
			break;
		} else {
			rev = reversebign(a);
			a = add(a, rev);
			count++;
		}
	}
	print(a);
	printf("%d", count);
	return 0;
}

/* C++ */
#include <iostream>
#include <algorithm>
using namespace std;
bool ispalindromic(string &num) {
	int left = 0, right = num.length() - 1;
	while(left < right) {
		if(num[left] != num[right]) return false;
		left++, right--;
	}
	return true;
}
int main() {
	int k;
	string num, tmp;
	cin >> num >> k;
	int i;
	reverse(num.begin(), num.end());
	for(i = 0; i < k; i++) {
		if(ispalindromic(num)) break;
		tmp = num;
		reverse(tmp.begin(), tmp.end());
		int carry = 0;
		for(int i = 0; i < num.length(); i++) {
			int t = (num[i] + tmp[i] + carry - 2 * '0');
			num[i] = t % 10 + '0';
			carry = t / 10;
		} 
		if(carry) num.push_back(carry + '0');
	}
	reverse(num.begin(), num.end());
	cout << num << endl;
	cout << (i == k ? k : i);
	return 0;
}
