#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;

int main(int argc, char const *argv[]) {
	int Nc, Np, coupon[MAXN] = {0}, product[MAXN] = {0};
	scanf("%d", &Nc);
	for(int i = 0; i < Nc; i++) {
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &Np);
	for(int i = 0; i < Np; i++) {
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon + Nc);
	sort(product, product + Np);
	int i = 0, j, ans = 0;
	while(i < Nc && i < Np && coupon[i] < 0 && product[i] < 0) {
		ans += coupon[i] * product[i];
		i++;
	}
	i = Nc - 1;
	j = Np - 1;
	while(i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0) {
		ans += coupon[i] * product[j];
		i--, j--;
	}
	printf("%d\n", ans);
	return 0;
}
