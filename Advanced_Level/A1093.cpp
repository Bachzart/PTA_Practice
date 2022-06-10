#include <cstdio>
#include <cstring>
const int MAXN = 100000 + 10;
const int MOD = 1000000007;
char str[MAXN];
int leftNumP[MAXN] = {0};

int main(int argc, char const *argv[]) {
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(i > 0) {
			leftNumP[i] = leftNumP[i - 1];
		}
		if(str[i] == 'P') leftNumP[i]++;
	}
	int ans = 0, rightNumT = 0;
	for(int i = len - 1; i > 0; i--) {
		if(str[i] == 'T') {
			rightNumT++;
		} else if(str[i] == 'A') {
			ans = (ans + leftNumP[i] * rightNumT) % MOD;
		}
	}
	printf("%d", ans);
	return 0;
}

/* simplification */ 
#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int pcnt = 0, tcnt = 0;
	for(char &ch: str) {
		if(ch == 'T') tcnt++;
	}
	int ans = 0;
	for(char &ch: str) {
		if(ch == 'A') {
			ans += tcnt * pcnt;
			ans %= 1000000007;
		} else if(ch == 'P') pcnt++;
		else tcnt--;
	}
	cout << ans;
	return 0;
} 
