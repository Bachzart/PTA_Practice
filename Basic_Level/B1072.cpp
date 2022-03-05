#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m;
const int maxn = 1000 + 5;
vector<string> stu[maxn];
set<string> ban;

int main() {
	cin >> n >> m;
	string str, name;
	for(int i = 0; i < m; i++) {
		cin >> str;
		ban.insert(str);
	}
	int snum = 0, bnum = 0, tmp;
	for(int i = 0; i < n; i++) {
		cin >> name >> tmp;
		for(int j = 0; j < tmp; j++) {
			cin >> str;
			if(ban.find(str) != ban.end()) {
				stu[i].push_back(str);
				bnum++;
			}
		}
		if(stu[i].size() != 0) {
			cout << name << ":";
			snum++;
			for(vector<string>::iterator it = stu[i].begin(); it != stu[i].end(); it++) {
				cout << " " << *it;
			}
			cout << endl;
		}
	}
	cout << snum << ' ' << bnum << endl;
	return 0;
}
