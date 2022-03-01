#include <iostream>
#include <vector>
using namespace std;
vector<char> hands[11], eyes[11], mouth[11], emo;
string temp;
int arr[6];
int main() {
	for(int i = 1; i <= 3; i++) {
		getline(cin, temp);
		int j, k, cnt = 1;
		if(i == 1) {
			for(j = 0; j < temp.length(); j++) {
				if(temp[j] == '[') {
					for(k = j + 1; temp[k] != ']'; k++) {
						hands[cnt].push_back(temp[k]);
					}
					cnt++;
					j = k;
				}
			}
		} else if(i == 2) {
			for(j = 0; j < temp.length(); j++) {
				if(temp[j] == '[') {
					for(k = j + 1; temp[k] != ']'; k++) {
						eyes[cnt].push_back(temp[k]);
					}
					cnt++;
					j = k;
				}
			}
		} else {
			for(j = 0; j < temp.length(); j++) {
				if(temp[j] == '[') {
					for(k = j + 1; temp[k] != ']'; k++) {
						mouth[cnt].push_back(temp[k]);
					}
					cnt++;
					j = k;
				}
			}
		}
	}
	int k, tmp;
	cin >> k;
	while(k--) {
		bool flag = true;
		emo.clear();
		for(int i = 0; i < 5; i++) {
			cin >> arr[i];
		}
		if(hands[arr[0]].size() == 0 || eyes[arr[1]].size() == 0 || mouth[arr[2]].size() == 0 \
			|| eyes[arr[3]].size() == 0 || hands[arr[4]].size() == 0) {
			printf("Are you kidding me? @\\/@\n");
			continue;
		} 
		for(vector<char>::iterator it = hands[arr[0]].begin(); it != hands[arr[0]].end(); it++) {
			emo.push_back(*it);
		}
		emo.push_back('(');
		for(vector<char>::iterator it = eyes[arr[1]].begin(); it != eyes[arr[1]].end(); it++) {
			emo.push_back(*it);
		}
		for(vector<char>::iterator it = mouth[arr[2]].begin(); it != mouth[arr[2]].end(); it++) {
			emo.push_back(*it);
		}
		for(vector<char>::iterator it = eyes[arr[3]].begin(); it != eyes[arr[3]].end(); it++) {
			emo.push_back(*it);
		}
		emo.push_back(')');
		for(vector<char>::iterator it = hands[arr[4]].begin(); it != hands[arr[4]].end(); it++) {
			emo.push_back(*it);
		}
		for(int i = 0; i < emo.size(); i++) {
			cout << emo[i];
		}
		cout << endl;
	}
	return 0;
}
