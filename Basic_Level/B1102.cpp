#include <cstdio>
const int maxn = 10000 + 5;
struct test{
	char id[9];
	int price, amount, sum;
} te[maxn]; 

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", te[i].id, &te[i].price, &te[i].amount);
		te[i].sum = te[i].price * te[i].amount;
	}
	int max_amount = te[0].amount, max_sum = te[0].sum, index1 = 0, index2 = 0;
	for(int i = 1; i < n; i++) {
		if(max_amount < te[i].amount) {
			max_amount = te[i].amount;
			index1 = i;
		}
		if(max_sum < te[i].sum) {
			max_sum = te[i].sum;
			index2 = i;
		}
	}
	printf("%s %d\n%s %d\n", te[index1].id, max_amount, te[index2].id, max_sum);
	return 0;
}
