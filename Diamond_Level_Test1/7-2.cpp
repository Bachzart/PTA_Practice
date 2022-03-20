#include <iostream>
using namespace std;

int main() {
	int n, breath, beats;
	cin >> n;
	string name;
	while(n--) {
		cin >> name >> breath >> beats;
		if(!(15 <= breath && breath <= 20) || !(50 <= beats && beats <= 70)) cout << name << endl;
	}
	return 0;
}
