/* way 1 */
#include <cstdio>
#include <cstring>
const int maxn = 20 + 5;
char tab[maxn], num1[maxn], num2[maxn];
int ans[maxn] = {0}, digit[10] = {10, 0, 2, 3, 4, 5, 6, 7, 8, 9};
void sreverse(char *str) {
	int len = strlen(str);
	for(int i = 0; i < len / 2; i++) {
		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}
int main() {
	scanf("%s\n%s\n%s", tab, num1, num2);
	sreverse(num1), sreverse(num2), sreverse(tab);
	int tmp, carry = 0, i;
	for(i = 0; num1[i] != '\0' && num2[i] != '\0'; i++) {
		tmp = num1[i] + num2[i] - 2 * '0' + carry;
		if(i < 20 && tmp >= digit[tab[i] - '0']) {
			tmp = tmp - digit[tab[i] - '0'];
			carry = 1;
		} else if(i >= 20 && tmp >= 10) {
			tmp = tmp - 10;
			carry = 1;
		} else carry = 0;
		ans[i] = tmp;
	}
	while(num1[i] != '\0') {
		tmp = num1[i] - '0' + carry;
		if(i < 20 && tmp >= digit[tab[i] - '0']) {
			tmp = tmp - digit[tab[i] - '0'];
			carry = 1;
		} else if(i >= 20 && tmp >= 10) {
			tmp = tmp - 10;
			carry = 1;
		} else carry = 0;
		ans[i++] = tmp;
	}
	while(num2[i] != '\0') {
		tmp = num2[i] - '0' + carry;
		if(i < 20 && tmp >= digit[tab[i] - '0']) {
			tmp = tmp - digit[tab[i] - '0'];
			carry = 1;
		} else if(i >= 20 && tmp >= 10) {
			tmp = tmp - 10;
			carry = 1;
		} else carry = 0;
		ans[i++] = tmp;
	}
	if(carry != 0) ans[i] = carry;
	while(ans[i] == 0) i--;
	if(i < 0) printf("0");
	else {
		for(int j = i; j >= 0; j--) {
			printf("%d", ans[j]);
		}
	}
	return 0;
}

/*
in:
30527
06203
415
out:
7201

in:
22
11
11
out:
110

in:
08
77
17
out:
96

in:
22222222222222222222
11111111111111111111
00000000000000000001
out:
100000000000000000000

in:
22222222222222222222
11111111111111111111
10000000000000000001
out:
110000000000000000000

in:
22222222222222222222
211111111111111111111
110000000000000000001
out:
410000000000000000000

in:
22222222222222222222
8800000000000000000000
8800000000000000000000
out:
17600000000000000000000


*/

/* way 2

#include <iostream>
using namespace std;

int main() {
	string s, s1, s2, ans;
	int carry = 0, flag = 0;
	cin >> s >> s1 >> s2;
	ans = s;
	string ss1(s.length() - s1.length(), '0');
	s1 = ss1 + s1;
	string ss2(s.length() - s2.length(), '0');
	s2 = ss2 + s2;
	for(int i = s.length() - 1; i >= 0; i--) {
		int mod = s[i] == '0' ? 10 : (s[i] - '0');
		ans[i] = (s1[i] + s2[i] - 2 * '0' + carry) % mod + '0';
		carry = (s1[i] + s2[i] - 2 * '0' + carry) / mod;
	}
	if(carry != 0) ans = '1' + ans;
	for(int i = 0; i < ans.size(); i++) {
		if(ans[i] != '0' || flag == 1) {
			flag = 1;
			cout << ans[i];
		}
	}
	if(flag == 0) cout << 0;
	return 0;
}

*/
