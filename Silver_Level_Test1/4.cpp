#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int N;
	cin >> N;
	int breath, pulse;
	char name[5];
	while(N--) {
		cin >> name >> breath >> pulse;
		if(breath < 15 || breath > 20 || pulse < 50 || pulse > 70) {
			cout << name << endl;
		}
	}
	return 0;
}
