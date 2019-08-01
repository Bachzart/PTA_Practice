#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, p, maxFacsum = -1;
vector<int> fac, ans, temp;

int power(int x) {
	int ret = 1;
	for(int i = 0; i < p; i++) {
		ret *= x;
	}
	return ret;
}

void init() {
	int i = 0, temp = 0;
	while(temp <= n) {
		fac.push_back(temp);
		temp = power(++i);
	}
}

void DFS(int index, int nowK, int sum, int facSum) {
	if(sum == n && nowK == k) {
		if(facSum > maxFacsum) {
			ans = temp;
			maxFacsum = facSum;
		}
		return;
	}
	if(sum > n || nowK > k) return;
	if(index - 1 >= 0) {
		temp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facSum + index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if(maxFacsum == -1) {
		printf("Impossible\n");
	} else {
		printf("%d = %d^%d", n, ans[0], p);
		for(int i = 1; i < ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	
	return 0;
} 
