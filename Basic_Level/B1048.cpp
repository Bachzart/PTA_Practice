#include <cstdio>
#include <cstring>
const int MAXN = 100 + 5;
char change[14] = "0123456789JQK";

void Reverse(char *s);

int main(int argc, char const *argv[]) {
	char A[MAXN], B[MAXN], Result[MAXN];
	scanf("%s %s", A, B);
	Reverse(A);
	Reverse(B);
	int i, lenA = strlen(A), lenB = strlen(B), len; 
	len = lenA > lenB ? lenA : lenB;
	for(i = 0; i < len; i++) {
		int numA = i < lenA ? A[i] - '0' : 0;
		int numB = i < lenB ? B[i] - '0' : 0;
		if(i % 2 == 0) {
			int sum = numA + numB;
			Result[i] = change[sum % 13];
		} else {
			int diff = numB - numA;
			if(diff < 0) {
				diff += 10;
			}
			Result[i] = change[diff];
		}
	}
	Result[i] = '\0';
	Reverse(Result);
	puts(Result);
	return 0;
}

void Reverse(char *s) {
	char temp;
	int len = strlen(s);
	for(int i = 0; i < len / 2; i++) {
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
