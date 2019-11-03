/* notes: this problem is similar to the Advanced Level 1030. */
#include <iostream>
using namespace std;
const int inf = 0x3fffffff;
const int maxn = 500 + 5;
int n, m, src, dst, G[maxn][maxn], cost[maxn][maxn];
int d[maxn], c[maxn];
bool vis[maxn] = {false};
void dijkstra(int src) {
	fill(d, d + maxn, inf);
	d[src] = 0;
	c[src] = 0;
	for(int i = 0; i < n; i++) {
		int v = -1, min = inf;
		for(int j = 0; j < n; j++) {
			if(!vis[j] && d[j] < min) {
				v = j;
				min = d[j];
			}
		}
		if(v == -1) return;
		vis[v] = true;
		for(int w = 0; w < n; w++) {
			if(!vis[w] && G[v][w] != inf) {
				if(d[v] + G[v][w] < d[w]) {
					d[w] = d[v] + G[v][w];
					c[w] = c[v] + cost[v][w];
				} else if(d[v] + G[v][w] == d[w]) {
					if(c[v] + cost[v][w] < c[w]) c[w] = c[v] + cost[v][w];
				}
			}
		}
	}
}
int main() {
	fill(G[0], G[0] + maxn * maxn, inf);
	cin >> n >> m >> src >> dst;
	int v1, v2;
	for(int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		cin >> G[v1][v2] >> cost[v1][v2];
		G[v2][v1] = G[v1][v2], cost[v2][v1] = cost[v1][v2];
	}
	dijkstra(src);
	cout << d[dst] << ' ' << c[dst];
	return 0;
}

/*
samples:
in:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
out:
3 40

*/
