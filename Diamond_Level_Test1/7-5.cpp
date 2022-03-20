#include <iostream>
using namespace std;
bool judge(int year, int n) {
	int cnt = 0;
	bool isappear[10] = {false};
	for(int i = 0; i < 4; i++) {
		isappear[year % 10] = true;
		year /= 10;
	}
	for(int i = 0; i < 10; i++) {
		if(isappear[i]) cnt++;
	}
	if(cnt == n) return true;
	else return false;
}
int main() {
	int y, n, x = 0;
	cin >> y >> n;
	while(!judge(y, n)) {
		y++, x++;
	}
	printf("%d %04d", x, y);
	return 0;
}
