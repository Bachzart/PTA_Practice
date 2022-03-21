#include <iostream>
using namespace std;
string str[5] = {"duo chi yu!", "duo chi rou!", "wan mei!", "ni li hai!", "shao chi rou!"};
int main() {
	int n, gender, height, weight;
	cin >> n;
	while(n--) {
		cin >> gender >> height >> weight;
		if(gender) {
			if(height > 130) cout << str[3];
			else if(height == 130) cout << str[2];
			else cout << str[0];
			cout << ' ';
			if(weight > 27) cout << str[4];
			else if(weight == 27) cout << str[2];
			else cout << str[1];
		} else {
			if(height > 129) cout << str[3];
			else if(height == 129) cout << str[2];
			else cout << str[0];
			cout << ' ';
			if(weight > 25) cout << str[4];
			else if(weight == 25) cout << str[2];
			else cout << str[1];
		}
		cout << endl;
	}
	return 0;
}
