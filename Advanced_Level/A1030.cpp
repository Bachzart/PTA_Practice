/* method 1: use dijkstra and dfs
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxv = 510;
const int inf = 0x3fffffff;
int n, m, s, t, G[maxv][maxv], cost[maxv][maxv];
int d[maxv], mincost = inf; // mincost need to be initialized to 'inf' 
bool vis[maxv] = {false};
vector<int> pre[maxv], tempath, path;
void dijkstra(int s) {
	fill(d, d + maxv, inf);
	d[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++) {
			if(vis[v] == false && G[u][v] != inf) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear(); // do not forget clear
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);	// save other shortest path
				}
			}
		}
	}
}
void dfs(int v) {
	if(v == s) {
		tempath.push_back(v);
		int tempcost = 0;
		for(int i = tempath.size() - 1; i > 0; i--) {
			int id = tempath[i], idNext = tempath[i - 1];
			tempcost += cost[id][idNext];
		}
		if(tempcost < mincost) {
			mincost = tempcost;
			path = tempath;
		}
		tempath.pop_back();
		return;
	}
	tempath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempath.pop_back();
}
int main(int argc, char const *argv[]) {
	cin >> n >> m >> s >> t;
	int u, v;
	fill(G[0], G[0] + maxv * maxv, inf);
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		cin >> G[u][v] >> cost[u][v];
		G[v][u] = G[u][v], cost[v][u] = cost[u][v];
	}
	dijkstra(s);
	dfs(t);
	for(int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
	cout << d[t] << ' ' << mincost;
	return 0;
}

/* method 2: just use dijkstra
#include <iostream>
#include <cstring>
using namespace std;
const int maxv = 510;
const int inf = 0x3fffffff;
int n, m, s, t, G[maxv][maxv], cost[maxv][maxv];
int d[maxv], c[maxv], pre[maxv];
bool vis[maxv] = {false};
void dijkstra(int s) {
	fill(d, d + maxv, inf);	// do not forget initlize the distance array
	for(int i = 0; i < n; i++) pre[i] = i;
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++) {
			if(vis[v] == false && G[u][v] != inf) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;	// save the precursor
				} else if(d[u] + G[u][v] == d[v]) {
					if(c[u] + cost[u][v] < c[v]) {	// more optimized result
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
} 
void dfs(int v) {
	if(v == s) {
		cout << v << ' ';
		return;
	}
	dfs(pre[v]);
	cout << v << ' ';
}
int main(int argc, char const *argv[]) {
	cin >> n >> m >> s >> t;
	fill(G[0], G[0] + maxv * maxv, inf);
	int u, v;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		cin >> G[u][v] >> cost[u][v];
		G[v][u] = G[u][v], cost[v][u] = cost[u][v];
	}
	dijkstra(s);
	dfs(t);
	cout << d[t] << ' ' << c[t];
	return 0;
}

*/
