#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 500 + 5;
const int INF = 1000000000;
struct station {
	double price, dis;
} sta[MAXN];
bool cmp(station a, station b);

int main(int argc, char const *argv[]) {
	double cmax, d, davg;
	int N;
	scanf("%lf %lf %lf %d", &cmax, &d, &davg, &N);
	for(int i = 0; i < N; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}
	sta[N].price = 0;
	sta[N].dis = d;
	sort(sta, sta + N, cmp);
	if(sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00\n");
	} else {
		int now = 0;
		double ans = 0, capacity = 0, max = cmax * davg;
		while(now < N) {
			int k = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= N && sta[i].dis - sta[now].dis <= max; i++) {
				if(sta[i].price < priceMin) {
					priceMin = sta[i].price;
					k = i;
					if(priceMin < sta[now].price) {
						break;
					}
				}
			}
			if(k == -1) break;
			double need = (sta[k].dis - sta[now].dis) / davg;
			if(priceMin < sta[now].price) {
				if(capacity < need) {
					ans += (need - capacity) * sta[now].price;
					capacity = 0;
				} else {
					capacity -= need;
				}
			} else {
				ans += (cmax - capacity) * sta[now].price;
				capacity = cmax - need;
			}
			now = k;
		}
		if(now == N) {
			printf("%.2lf\n", ans);
		} else {
			printf("The maximum travel distance = %.2lf\n", sta[now].dis + max);
		}
	}
	return 0;
}

bool cmp(station a, station b) {
	return a.dis < b.dis;
}
