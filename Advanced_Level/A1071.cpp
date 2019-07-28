#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> mp;

bool check(char c) {
	if('0' <= c && c <= '9') return true;
	if('a' <= c && c <= 'z') return true;
	if('A' <= c && c <= 'Z') return true;
	return false;
}

int main(int agrc, char const *argv[]) {
	map<string, int> count;
	string str;
	getline(cin, str);
	int i = 0;
	while(i < str.length()) {
		string word;
		while(i < str.length() && check(str[i]) == true) {
			if('A' <= str[i] && str[i] <= 'Z') {
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word != "") {
			if(count.find(word) == count.end()) count[word] = 1;
			else count[word]++;
		}
		while(i < str.length() && check(str[i]) == false) {
			i++;
		}
	}
	string ans;
	int max = 0;
	for(map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
		if(it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	cout << ans << ' ' << max;
	return 0;
}
