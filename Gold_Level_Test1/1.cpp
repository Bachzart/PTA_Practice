#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int N, breath, pulse;
	char name[5];
	cin >> N;
	while(N--) {
		cin >> name >> breath >> pulse;
		if(!(15 <= breath && breath <= 20 && 50 <= pulse && pulse <= 70)) {
			cout << name << endl;
		}
	}
	return 0;
} 
