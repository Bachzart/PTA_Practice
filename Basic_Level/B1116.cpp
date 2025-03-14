#include <iostream>
#include <string>
using namespace std;

int main() {
	string num;
	cin >> num;
	int len = num.length();
	if(len % 2) {
		cout << "Error: " << len << " digit(s)" << endl;
	} else {
		int pos1 = len / 2 - 1, pos2 = len - 1;
		string X = num.substr(len / 2, len / 2 - 1);
		string Y = num.substr(0, len / 2 - 1);
		if(X == Y && num[pos2] - num[pos1] == 2)
			cout << "Yes: " << X + num[pos2] << " - " << Y + num[pos1] << " = 2" << endl;
		else 
			cout << "No: " << X + num[pos2] << " - " << Y + num[pos1] << " != 2" << endl;
	}
	return 0;
}
