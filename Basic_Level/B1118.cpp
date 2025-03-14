#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_map<string, int> tex2num = {
	{"ling", 0}, {"yi", 1}, {"er", 2}, {"san", 3},
	{"si", 4}, {"wu", 5}, {"liu", 6},
	{"qi", 7}, {"ba", 8}, {"jiu", 9}
}; 
unordered_set<char> ope = {'+', '-', '*', '/', '%', '^'};

int deal(string s) {
	int len = s.length();
	int idx;
	for(idx = 0; idx < len; ++idx) {
		if(ope.count(s[idx])) 
			break;
	}
	int ret = 0;
	if(idx != len) {
		int num1 = stoi(s.substr(0, idx));
		int num2 = stoi(s.substr(idx + 1));
		switch(s[idx]) {
			case '+':
				ret = num1 + num2; break;
			case '-':
				ret = num1 - num2; break;
			case '*':
				ret = num1 * num2; break;
			case '/':
				ret = num1 / num2; break;
			case '%':
				ret = num1 % num2; break;
			case '^':
				ret = pow(num1, num2); break;
			default:
				break;
		}
	} else {
		if(tex2num.count(s)) 
			ret = tex2num[s];
		else if(s.substr(0, 4) == "sqrt")
			ret = sqrt(stoi(s.substr(4)));
		else 
			ret = stoi(s);
	}
	return ret;
}

int main() {
	string s, ans;
	for(int i = 0; i < 11; ++i) {
		cin >> s;
		ans.push_back(deal(s) + '0');
	}
	cout << ans;
	return 0;
}
