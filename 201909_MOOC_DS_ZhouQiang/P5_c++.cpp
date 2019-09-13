#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++) {
		if(isdigit(str[i])) {
			if(isdigit(str[i + 1]) || str[i + 1] == '.') cout << str[i];
			else cout << str[i] << endl;
		} else {
			if(!isdigit(str[i - 1]) && isdigit(str[i + 1]) && 
			str[i] == '-') cout << str[i];
			else if (isdigit(str[i - 1]) && isdigit(str[i + 1]) && 
			str[i] == '.') cout << str[i];
			else if (!isdigit(str[i - 1]) && isdigit(str[i + 1]) && 
			str[i] == '+' && !isdigit(str[i - 2])) cout << str[i];
			else cout << str[i] << endl;
		}
	}
	return 0;
}
