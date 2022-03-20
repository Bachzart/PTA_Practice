#include <iostream>
using namespace std;

int main() {
	int n, front, rear, len;
	cin >> n;
	string tmp;
	while(n--) {
		cin >> tmp;
		len = tmp.length();
		front = tmp[0] + tmp[1] + tmp[2] - 3 * '0';
		rear = tmp[len - 1] + tmp[len - 2] + tmp[len - 3] - 3 * '0';
		if(front == rear) cout << "You are lucky!" << endl;
		else cout << "Wish you good luck." << endl;
	}
	return 0;
}
