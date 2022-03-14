#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

int main(int argc, char const *argv[]) {
	int K, Num[105] = {0}, temp;
	bool times[MAXN] = {false};
	scanf("%d", &K);
	for(int i = 0; i < K; i++) {
		scanf("%d", &Num[i]);
		temp = Num[i];
		while(temp != 1) {
			if(temp % 2 == 1) {
				temp = 3 * temp + 1;
			}
			temp /= 2;
			times[temp] = true;
		}
	}
	sort(Num, Num + K);
	bool flag = true;
	for(int i = K - 1; i >= 0; i--) {
		if(!times[Num[i]]) {
			if(flag) {
				printf("%d", Num[i]);
				flag = false;
			} else printf(" %d", Num[i]);
		}
	}
	return 0;
}
