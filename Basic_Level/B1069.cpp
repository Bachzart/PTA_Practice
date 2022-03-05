#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> acc;
map<string, int> done;
int main() {
	int m, n, s;
	cin >> m >> n >> s;
	string str;
	for(int i = 0; i < m; i++) {
		cin >> str;
		acc.push_back(str);
	}
	vector<string>::iterator it = acc.begin();
	if(s > m) {
		cout << "Keep going...";
	} else {
		for(int i = s - 1; i < m; i += n) {
			str = *(it + i);
			if(done[str] == 0) {
				cout << str << endl;
				done[str]++;
			} else {
				for(i++; i < m; i++) {
					str = *(it + i);
					if(done[str] == 0) {
						done[str]++;
						cout << str << endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
