#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int N;
	double height, weight, standard, diff;
	cin >> N;
	while(N--) {
		cin >> height >> weight;
		standard = (height - 100) * 0.9 * 2.0;
		diff = weight - standard;
		standard *= 0.1;
		if(-standard < diff && diff < standard) {
			cout << "You are wan mei!" << endl;
		} else if(diff >= standard) {
			cout << "You are tai pang le!" << endl;
		} else {
			cout << "You are tai shou le!" << endl;
		}
	}
	return 0;
}
