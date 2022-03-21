#include <iostream>
#include <string>
using namespace std;

int main() {
	string tmp;
	getline(cin, tmp);
	for(int i = 0; i < tmp.length(); i++) {
		if(tmp[i] == '6') {
			int cnt = 1, j;
			for(j = i + 1; j < tmp.length(); j++) {
				if(tmp[j] == '6') cnt++;
				else break;
			}
			if(cnt > 9) tmp.replace(i, j - i, "27");
			else if(cnt > 3)  tmp.replace(i, j - i, "9");
		}
	}
	cout << tmp;
	return 0;
}
