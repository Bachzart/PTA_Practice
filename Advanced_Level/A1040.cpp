#include <cstdio>
#include <cstring>
const int maxn = 1010;
char str[maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[]) {
	fgets(str, maxn, stdin);
	int len = strlen(str), ans = 1;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < len; i++) {
		dp[i][i] = 1;
		if(i < len - 1) {
			if(str[i] == str[i + 1]) {
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for(int l = 3; l <= len; l++) {
		for(int i = 0; i + l - 1 < len; i++) {
			int j = i + l - 1;
			if(str[i] == str[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

/* method 2: violent solution

#include <cstdio>
#include <cstring>
const int maxn = 1010;
bool palindrome(char *s1, char *s2) {
	bool flag = true;
	for(; s1 < s2; s1++, s2--) {
		if(*s1 != *s2) {
			flag = false;
			break;
		}
	}
	return flag;
}
int main(int argc, char const *argv[]) {
	char str[maxn];
	fgets(str, maxn, stdin);
	char *p1, *p2;
	int max_len = 0, temp;
	for(p1 = str; *p1 != '\0'; p1++) {
		for(p2 = p1 + 1; *p2 != '\0'; p2++) {
			if(*p1 == *p2) {
				temp = p2 - p1;
				if(temp <= max_len) continue;
				else if(palindrome(p1, p2)) max_len = temp;
			}
		}
	}
	printf("%d", max_len + 1);
	return 0;
} 
*/
