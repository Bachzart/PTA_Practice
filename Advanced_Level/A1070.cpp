#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 5;
struct mooncake{
	double store, sell, price;
} cake[MAXN];
bool cmp(mooncake a, mooncake b);

int main(int argc, char const *argv[]) {
	int N;
	double D;
	scanf("%d %lf", &N, &D);
	for(int i = 0; i < N; i++) {
		scanf("%lf", &cake[i].store);
	}
	for(int i = 0; i < N; i++) {
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	sort(cake, cake + N, cmp);
	double ans = 0;
	for(int i = 0; i < N; i++) {
		if(cake[i].store <= D) {
			ans += cake[i].sell;
			D -= cake[i].store;
		} else {
			ans += cake[i].price * D;
			break;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}

bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}
