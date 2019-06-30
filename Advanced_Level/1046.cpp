#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;

int main(int argc, char const *argv[]) {
	int M, N, Exits[MAXN] = {0}, Dis[MAXN], Sum_D = 0, src, dst;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &Exits[i]);
		Sum_D += Exits[i];
		Dis[i] = Sum_D;
	}
	scanf("%d", &M);
	while(M--) {
		scanf("%d %d", &src, &dst);
		if(src > dst) {
			swap(src, dst);
		}
		int temp = Dis[dst - 1] - Dis[src - 1];
		printf("%d\n", temp < (Sum_D - temp) ? temp : (Sum_D - temp));
	}
	return 0;
}