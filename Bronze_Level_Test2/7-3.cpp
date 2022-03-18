#include <iostream>
using namespace std;

int main() {
	int x, y, s, t;
	cin >> x >> y;
	s = x * y / 2;
	t = (y + 100) * (100 - x) / 2;
	cout << 5000 - s - t;
	return 0;
}
