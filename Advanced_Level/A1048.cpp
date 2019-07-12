#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int main(int argc, char const *argv[]) {
	int N, M, coins[MAXN];
	scanf("%d %d", &N, &M);
	int value[MAXN] = {0};
	for(int i = 1; i <= N; i++) {
		scanf("%d", &coins[i]);
		value[coins[i]]++;
	}
	sort(coins + 1, coins + N + 1);
	int i, v1, v2;
	bool flag = false;
	for(i = 1; i <= N; i++) {
		v1 = coins[i];
		v2 = M - v1;
		if(value[v1] && value[v2]) {
			if(v1 == v2 && value[v1] != 2) {
				break;
			}
			printf("%d %d", v1, v2);
			flag = true;
			break;
		}
	}
	if(!flag) {
		printf("No Solution");
	}
	return 0;
} 
