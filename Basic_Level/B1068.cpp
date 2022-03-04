/* way 1 */
#include <iostream>
#include <map>
using namespace std;
int image[1005][1005];
map<int, int> isappear; 
int dd[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int m, n, tol;
bool isonly(int x, int y) {
	for(int i = 0; i < 8; i++) {
		int xx = x + dd[i][0];
		int yy = y + dd[i][1];
		if(xx >= 0 && xx < n && yy >= 0 && yy < m && image[x][y] - image[xx][yy] >= -tol
			&& image[x][y] - image[xx][yy] <= tol) return false;
	}
	return true;
}
int main() {
	cin >> m >> n >> tol;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> image[i][j];
			isappear[image[i][j]]++;
		}
	}
	int cnt = 0, x = 0, y = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(isappear[image[i][j]] == 1 && isonly(i, j)) {
				cnt++;
				x = j + 1, y = i + 1;
			}
		}
	}
	if(cnt == 1) cout << "(" << x << ", " << y << "): " << image[y - 1][x - 1];
	else if(cnt > 1) cout << "Not Unique";
	else cout << "Not Exist";
	return 0;
}

/* way 2 

#include <cstdio>
#include <cmath>
typedef long long LL;
const int maxn = 1000 + 5;
const int maxm = 1000 + 5;
LL M, N, TOL, image[maxm][maxn] = {0};
int times[18000000] = {0};

int main() {
	scanf("%lld %lld %lld", &M, &N, &TOL);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%lld", &image[i][j]);
			times[image[i][j]]++;
		}
	}
	LL x, y, cnt = 0;
	x = y = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			LL t = image[i][j];
			if(times[image[i][j]] == 1 
				&& abs(t - image[i - 1][j - 1]) > TOL && abs(t - image[i - 1][j]) > TOL
				&& abs(t - image[i - 1][j + 1]) > TOL && abs(t - image[i][j - 1]) > TOL
			    && abs(t - image[i][j + 1]) > TOL && abs(t - image[i + 1][j - 1]) > TOL
				&& abs(t - image[i + 1][j]) > TOL && abs(t - image[i + 1][j + 1]) > TOL  ) {
				x = j, y = i;
				cnt++;
			}
		}
	}
	if(cnt == 1)  printf("(%lld, %lld): %lld", x, y, image[y][x]);
	else if(cnt > 1) printf("Not Unique");
	else printf("Not Exist");
	return 0;
}

*/