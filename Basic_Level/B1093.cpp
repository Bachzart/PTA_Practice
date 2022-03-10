#include <iostream>
using namespace std;
bool isappear[256] = {false};
int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for(int i = 0; i < a.length(); i++) {
		if(!isappear[a[i]]) {
			cout << a[i];
			isappear[a[i]] = true;
		}
	}
	for(int i = 0; i < b.length(); i++) {
		if(!isappear[b[i]]) {
			cout << b[i];
			isappear[b[i]] = true;
		}
	}
	return 0;
}
