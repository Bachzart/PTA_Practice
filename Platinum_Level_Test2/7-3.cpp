#include <iostream>
using namespace std;

int main() {
	int n, front, rear, len;
	cin >> n;
	string num;
	while(n--) {
		cin >> num;
		len = num.length();
		if(len < 6) continue;
		front = num[0] + num[1] + num[2] - 3 * '0';
		rear = num[len - 1] + num[len - 2] + num[len - 3] - 3 * '0';
		if(front == rear) cout << "You are lucky!" << endl;
		else cout << "Wish you good luck." << endl;
	}
	return 0;
}
