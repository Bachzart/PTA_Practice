#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int num) {
	if(num <= 1) return false;
	for(int i = 2; i <= sqrt(num); i++) 
		if(num % i == 0)
			return false;
	return true;
}

int main(int argc, char const *argv[]) {
	string date;
	cin >> date;
	int index = 0, len = date.length();
	bool flag = true;
	while(index < len) {
		string num = date.substr(index);
		int n = stoi(num);
		if(isPrime(n)) 
			cout << num << " Yes" << endl;
		else {
			cout << num << " No" << endl;
			flag = false;
		}
		index++;
	}
	if(flag) cout << "All Prime!" << endl;
	return 0;
}