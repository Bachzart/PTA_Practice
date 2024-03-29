/* way 1: use string.find() */
#include <iostream>
#include <cctype>
using namespace std;
int main() {
	string s1, s2, ans;
	cin >> s1 >> s2;
	for(int i = 0; i < s1.length(); i++) {
		if(s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos) {
			ans += toupper(s1[i]);
		}
	}
	cout << ans;
	return 0;
}

/* 
// way 2: traverse string 
#include <cstdio>
#include <cctype>

void levelup(char *str);

int main(int argc, char const *argv[]) {
	char str1[85], str2[85], Result[30];
	scanf("%s %s", str1, str2);
	levelup(str1);
	levelup(str2);
	int count = 0;
	for(int i = 0; str1[i] != '\0'; i++) {
		char temp = str1[i];
		bool flag = true;
		for(int j = 0; str2[j] != '\0'; j++) {
			if(temp == str2[j]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			int k = 0;
			for(k = 0; k < 30; k++) {
				if(temp == Result[k]) {
					break;
				}
			}
			if(k == 30) {
				Result[count++] = temp;
			}
		}
	}
	Result[count] = '\0';
	puts(Result);
	return 0;
}

void levelup(char *str) {
	char *p = str;
	while(*p != '\0') {
		if(islower(*p)) {
			*p = toupper(*p);
		}
		p++;
	}
}

*/

/*
// way 3: hash
#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	string name, birth, maxname, minname, maxbirth = "1814/09/06", minbirth = "2014/09/06";
	for(int i = 0; i < n; i++) {
		cin >> name >> birth;
		if("1814/09/06" <= birth && birth <= "2014/09/06") {
			cnt++;
			if(maxbirth <= birth) {
				maxbirth = birth;
				maxname = name;
			}
			if(minbirth >= birth) {
				minbirth = birth;
				minname = name;
			}
		}
	}
	cout << cnt;
	if(cnt) cout << ' ' << minname << ' ' << maxname;
	return 0;
}

*/
