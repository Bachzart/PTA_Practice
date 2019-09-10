#include <iostream>
using namespace std;
int X[4] = {-1, 1, 0, 0};
int Y[4] = {0, 0, -1, 1};
int m, n, area[25][25];
bool outofrange(int x, int y) {
	if(x < 0 || y < 0 || x > m - 1 || y > n - 1 || area[x][y] == 3) return 1;
	return 0;
}
int main(int argc, char const *argv[]) {
	cin >> m >> n;
	char temp;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> temp;
			if(temp == '0') area[i][j] = 0;
			if(temp == '#') area[i][j] = 1;
		}
	}
	int x, y, k;
	cin >> k;
	while(k--) {
		cin >> x >> y;
		if(area[x][y] >= 1) area[x][y] = 3;
		for(int i = 0; i < 4; i++) {
			int newX = x + X[i];
			int newY = y + Y[i];
			if(area[newX][newY] > 0 && !outofrange(newX, newY)) {
				area[newX][newY]++;
			}
		}
		int count = 0;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(area[i][j] == 3) {
					count++;
					area[i][j] = 0;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}

