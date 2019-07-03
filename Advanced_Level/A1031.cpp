#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[]) {
	int n1, n2, n3, N;
	char str[85];
	scanf("%s", str);
	N = strlen(str);
	n1 = n3 = (N + 2) / 3;	//get n1 and n3 first
	n2 = N + 2 - 2 * n1;	//use the condition: n1 + n2 + n3 - 2 = N
	for(int i = 0; i < n1; i++) {
		if(i == n1 - 1) {
			for(int j = i; j <= N - i - 1; j++) {
				printf("%c", str[j]);
			} 
		} else {
			printf("%c", str[i]);
			for(int j = 0; j < n2 - 2; j++) {
				putchar(' ');
			}
			printf("%c", str[N - i - 1]);
		}
		putchar('\n');
	}
	return 0;
}
