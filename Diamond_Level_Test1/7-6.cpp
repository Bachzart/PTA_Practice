#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 10000 + 5;
map<string, int> stu;
int n, k;
bool check[maxn] = {false};
bool isprime(int a) {
	if(a <= 1) return false;
	else {
		for(int i = 2; i <= sqrt(a); i++) {
			if(a % i == 0) return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	string str;
	for(int i = 1; i <= n; i++) {
		cin >> str;
		stu[str] = i;
	}
	cin >> k;
	while(k--) {
		cin >> str;
		cout << str << ": ";
		map<string, int>::iterator it = stu.find(str); 
		if(it == stu.end()) cout << "Are you kidding?";
		else {
			if(!check[it->second]) {
				if(it->second == 1) cout << "Mystery Award";
				else if(isprime(it->second)) cout<< "Minion";
				else cout<< "Chocolate";
				check[it->second] = true;
			} else cout << "Checked";
		}
		cout << endl;
	}
	return 0;
}
