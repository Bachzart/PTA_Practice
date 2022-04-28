/* method 1 */
#include <cstdio>
const int MAXN = 10;

int main(int argc, char const *argv[]) {
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	if(sum < 0) {
		putchar('-');
		sum = -sum;
	}
	int len = 0, num[MAXN];
	if(sum == 0) {
		num[len++] = sum;
	}
	while(sum) {
		num[len++] = sum % 10;
		sum /= 10;
	}
	for(int i = len - 1; i >= 0; i--) {
		printf("%d", num[i]);
		if(i > 0 && i % 3 == 0) {
			putchar(',');
		}
	}
	return 0;
}

/* method 2 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	if(c < 0) {
		cout << '-';
		c = -c;
	}
	string str = to_string(c), tmp;
	int cnt = 0;
	for(int i = str.length() - 1; i >= 0; i--) {
		tmp.push_back(str[i]);
		cnt++;
		if(cnt == 3) {
			if(i != 0) tmp += ',';
			cnt = 0;
		}
	}
	reverse(tmp.begin(), tmp.end());
	cout << tmp;
	return 0;
}

/* method 3 */
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	if(c < 0) {
		cout << '-';
		c = -c;
	}
	if(c >= 1000000) printf("%d,%03d,%03d", c / 1000000, c % 1000000 / 1000, c % 1000);
	else if(c >= 1000) printf("%d,%03d", c / 1000, c % 1000);
	else printf("%d", c);
	return 0;
}