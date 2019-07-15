#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int N;
	cin >> N;
	double h, w, standard;
	while(N--) {
		cin >> h >> w;
		standard = (h - 100) * 0.9 * 2;
		double temp = w - standard, cmp = standard * 0.1;
		if(-cmp < temp && temp < cmp) {
			cout << "You are wan mei!" << endl;
		} else if(temp <= -cmp) {
			cout << "You are tai shou le!" << endl;
		} else {
			cout << "You are tai pang le!" << endl;
		}
	}
	
	return 0;
}
