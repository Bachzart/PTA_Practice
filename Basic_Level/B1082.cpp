#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10000 + 5;
struct athlete{
	char id[5];
	int x, y, dis;	
} ath[maxn];
bool cmp(athlete a, athlete b) {
	return a.dis < b.dis;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", ath[i].id, &ath[i].x, &ath[i].y);
		ath[i].dis = sqrt(ath[i].x * ath[i].x + ath[i].y * ath[i].y);
	}
	sort(ath, ath + n, cmp);
	printf("%s %s", ath[0].id, ath[n - 1].id);
	return 0;
}
