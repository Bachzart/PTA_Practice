#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	cout << 5000 - y * x / 2 - (y + 100) * (100 - x) / 2;
	return 0;
}
