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

/* simplification */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string str;
	cin >> str;
	int n1, n2 = 3, n3, len = str.length();
	while(true) {
		int diff = len - n2;
		if(diff % 2 == 0) {
			n1 = n3 = diff / 2;
			if(n2 > n1) break;
		}
		n2++;
	}
	int i, j;
	for(i = 0, j = len - 1; i < n1 && j > len - n3 - 1; i++, j--) {
		cout << str[i];
		for(int k = 0; k < n2 - 2; k++) cout << ' ';
		cout << str[j] << endl;
	}
	while(i <= j) cout << str[i++];
	return 0;
}