#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	stack<char> st;
	int left = 0, right = 0;
	bool flag = true;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
			left++;
			st.push(str[i]);
		} else if(str[i] == ')') {
			right++;
			if(!st.empty() && st.top() == '(') st.pop();
			else flag = false;
		} else if(str[i] == ']') {
			right++;
			if(!st.empty() && st.top() == '[') st.pop();
			else flag = false;
		} else if(str[i] == '}') {
			right++;
			if(!st.empty() && st.top() == '{') st.pop();
			else flag = false;
		}
	}
	cout << left << ' ' << right << endl;
	if(flag && left == right) cout << "YES";
	else cout << "NO";
	return 0;
}
