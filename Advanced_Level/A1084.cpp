#include <cstdio>
#include <cctype>

int main(int argc, char const *argv[]) {
	char str1[85], str2[85];
	scanf("%s %s", str1, str2);
	bool HashTable[128] = {false};
	for(int i = 0; str1[i] != '\0'; i++) {
		int j = 0;
		char c1 = str1[i];
		for(; str2[j] != '\0'; j++) {
			char c2 = str2[j];
			if(islower(c1)) c1 = toupper(c1);
			if(islower(c2)) c2 = toupper(c2);
			if(c1 == c2) break;
		}
		if(str2[j] == '\0' && HashTable[c1] == false) {
			printf("%c", c1);
			HashTable[c1] = true;
		}
	}
	putchar('\n');
	return 0;
}
