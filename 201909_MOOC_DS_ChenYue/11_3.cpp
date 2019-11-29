#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, string> qqnum;
int main() {
	int n;
	char ope;
	cin >> n;
	string tmp_num, tmp_pass;
	for (int i = 0; i < n; i++) {
		cin >> ope >> tmp_num >> tmp_pass;
		map<string, string>::iterator it;
		it = qqnum.find(tmp_num);
		switch (ope) {
			case 'L': {
				if (it == qqnum.end()) {
					cout << "ERROR: Not Exist" << endl;
				} else {
					if (it->second == tmp_pass) {
						cout << "Login: OK" << endl;
					} else cout << "ERROR: Wrong PW" << endl;
				}
				break;
			}
			case 'N': {
				if (it != qqnum.end()) {
					cout << "ERROR: Exist" << endl;
				} else {
					qqnum[tmp_num] = tmp_pass;
					cout << "New: OK" << endl;
				}
				break;
			}
			default: break;
		}
	}
	return 0;
}

/*
samples:
in:
5
L 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
L 1234567890 myQQ@qq
L 1234567890 myQQ@qq.com
out:
ERROR: Not Exist
New: OK
ERROR: Exist
ERROR: Wrong PW
Login: OK

*/