/* way 1: use string.find() */
#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.length(); i++) {
    	s1[i] = tolower(s1[i]);
	}
    for(int i = 0; i < s2.length(); i++) {
    	if(s1.find(s2[i]) == string::npos) {
    		if(!isupper(s2[i])) cout << s2[i];
    		else if(s1.find('+') == string::npos && s1.find(tolower(s2[i])) == string::npos) cout << s2[i];
		}
	}
    return 0;
}

/* way 2: use hash

#include <cstdio>
#include <cctype>
const int MAXN = 100000 + 5;

int main(int argc, char const *argv[]) {
	char str1[MAXN], str2[MAXN]; 
	bool brokenkey[128] = {false};
	fgets(str2, MAXN, stdin);
	fgets(str1, MAXN, stdin);
	for(int i = 0; str2[i] != '\0'; i++) {
		brokenkey[str2[i]] = true;
		if(islower(str2[i])) {
			brokenkey[str2[i] - 32] = true;
		} else if(isupper(str2[i])) {
			brokenkey[str2[i] + 32] = true;
		}
	}
	for(int i = 0; str1[i] != '\0'; i++) {
		if(!brokenkey[str1[i]]) {
			if(isupper(str1[i]) && brokenkey['+']) {
				continue;
			}
			printf("%c", str1[i]);
		}
	}
	return 0;
}

*/
