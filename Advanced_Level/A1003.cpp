#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int n, m, st, ed, G[maxv][maxv], weight[maxv];
int d[maxv], w[maxv] = {0}, num[maxv] = {0};
bool vis[maxv] = {false};
void dijkstra(int s) {
	fill(d, d + maxv, INF);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];	//update the distance of each node
					w[v] = w[u] + weight[v]; // update the 'hands'
					num[v] = num[u];	// update the path for a new reachable node
				} else if(d[u] + G[u][v] == d[v]) {
					/*only one path can count the 'hands', so the w[v] will
					be covered by the sum of last node and its own 'hands' */
					if(w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
					//but the number of path is not only
					num[v] += num[u];
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	cin >> n >> m >> st >> ed;
	for(int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	int u, v;
	fill(G[0], G[0] + maxv * maxv, INF);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		cin >> G[u][v];
		G[v][u] = G[u][v];
	}
	dijkstra(st);
	cout << num[ed] << ' ' << w[ed];
	return 0;
}
