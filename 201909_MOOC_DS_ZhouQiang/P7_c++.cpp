#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isvalid(string s1, string s2) {
	stack<char> st;
	bool flag = true;
	int i, j = 0;
	for(i = 0; i < s2.length(); i++) {
		if(st.empty()) {
			for(; j < s1.length(); j++) {
				if(s1[j] == s2[i]) {
					j++;
					break;
				} else {
					st.push(s1[j]);
				}
			}
		} else {
			if(st.top() == s2[i]) {
				st.pop();
			} else {
				for(; j < s1.length(); j++) {
					if(s1[j] == s2[i]) {
						j++;
						break;
					} else {
						st.push(s1[j]);
					}
				}
			}
		}
	}
	if(!st.empty()) flag = false;
	return flag;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int i, j = 0;
	stack<char> st;
	if(!isvalid(s1, s2)) {
		cout << "Are you kidding me?" << endl;
	} else {
		for(i = 0; i < s2.length(); i++) {
			if(st.empty()) {
				for(; j < s1.length(); j++) {
					if(s1[j] == s2[i]) {
						cout << "1->2" << endl;
						j++;
						break;
					} else {
						st.push(s1[j]);
						cout << "1->3" << endl;
					}
				}
			} else {
				if(st.top() == s2[i]) {
					st.pop();
					cout << "3->2" << endl;
//				cout << j << i << endl;
				} else {
					for(; j < s1.length(); j++) {
						if(s1[j] == s2[i]) {
							cout << "1->2" << endl;
							j++;
							break;
						} else {
							st.push(s1[j]);
							cout << "1->3" << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}
/*
some samples:
ABC
BAC

*/
