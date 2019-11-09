#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000 + 5;
const int inf = 0x3fffffff;
struct node {
	int w, weight;
	node(int w, int weight) {
		this->w = w;
		this->weight = weight;
	}
};
vector<node> G[maxn];
int nv, ne, dist[maxn];
bool visited[maxn] = { false };

void prim() {
	for (int i = 0; i < maxn; i++) dist[i] = inf;
	dist[1] = 0;
	int times = 0, cnt = 0;
	while(1) {
		int mindis = inf, v = -1;
		for (int j = 1; j <= nv; j++) {
			if (!visited[j] && dist[j] < mindis) {
				mindis = dist[j];
				v = j;
			}
		}
		if (v == -1) break;
		times++;
		cnt += dist[v];
		visited[v] = true;
		for (int w = 0; w < G[v].size(); w++) {
			if (!visited[G[v][w].w] && G[v][w].weight < dist[G[v][w].w]) {
				dist[G[v][w].w] = G[v][w].weight;
			}
		}
	}
	if (times == nv) cout << cnt;
	else cout << -1;
}
int main() {
	cin >> nv >> ne;
	int v1, v2, weight;
	for (int i = 0; i < ne; i++) {
		cin >> v1 >> v2 >> weight;
		G[v1].emplace_back(v2, weight);
		G[v2].emplace_back(v1, weight);
	}
	prim();
	return 0;
}

/*
samples:
in:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
out:
12

*/
