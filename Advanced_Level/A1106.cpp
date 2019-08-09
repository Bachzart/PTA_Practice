#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100005;
vector<int> child[maxn];
int tot = 0, n, minDepth = maxn;
double p, r;
void DFS(int index, int depth) {
	if(child[index].size() == 0) {
		if(depth < minDepth) {
			minDepth = depth;
			tot = 1;
		} else if(depth == minDepth) {
			tot++;
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100.0;
	int num, subchild;
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &subchild);
			child[i].push_back(subchild);
		}
	}
	DFS(0, 0);
	double ans = p * pow(1 + r, minDepth);
	printf("%.4lf %d", ans, tot);
	return 0;
}
