/* version 1: use scanf */
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int count = 0;
	char Str[85][85], c;
	while(1) {
		scanf("%s", Str[++count]);
		c = getchar();
		if(c == '\n') {
			break;
		}
	}
	for(; count > 1; count--) {
		printf("%s ", Str[count]);
	}
	puts(Str[count]);
	return 0;
} 

/* version 2: use string */
#include <iostream>
using namespace std;

int main() {
	string str, res;
	getline(cin, str);
	for(int i = str.length() - 1; i >= 0; i--) {
		int j = i - 1;
		for(; j > 0; j--) {
			if(str[j] == ' ') break;
		}
		if(j >= 0 && str[j] == ' ') res += str.substr(j + 1, i - j) + ' ';
		else res += str.substr(0, i + 1); 
		i = j;
	}
	cout << res;
	return 0;
}