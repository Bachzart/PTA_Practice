#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	cout << 5000 - x * y / 2 - (100 - x) * (y + 100) / 2;
	return 0;
}
