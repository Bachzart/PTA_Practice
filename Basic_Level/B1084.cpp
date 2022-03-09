#include <cstdio>
char str1[100005], str2[100005];
int n;

int main() {
	scanf("%s %d", str1, &n);
	for(int i = 1; i < n; i++) {
		int len = 0;
		for(int j = 0; str1[j] != '\0'; j++) {
			str2[len++] = str1[j];
			int count = 1, k;
			for(k = j + 1; str1[k] == str1[j]; k++) count++;
			str2[len++] = count + '0';
			j = --k;
		}
		str2[len] = '\0';
		for(int j = 0; j <= len; j++) {
			str1[j] = str2[j];
		}
	}
	printf("%s", str1);
	return 0;
}
