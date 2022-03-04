#include <iostream>
using namespace std;

int main() {
	string password, str;
	int N;
	cin >> password >> N;
	int attempt = 1;
	bool flag = false;
	getchar();
	while(1) {
		getline(cin, str);
		if(str == "#") break;
		if(str == password && attempt <= N) {
			cout << "Welcome in" << endl;
			break;
		}
		if(str != password && attempt <= N) {
			cout << "Wrong password: " << str << endl;
			if(attempt == N){
				cout << "Account locked" << endl;
				break;
			}
		}
		attempt++;
	}
	return 0;
}
