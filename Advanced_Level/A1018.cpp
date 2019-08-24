#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int maxv = 510;
const int inf = 0x3fffffff;
int Cmax, n, m, sp, G[maxv][maxv], weight[maxv];
int d[maxv], minneed = inf, minremain = inf;
bool vis[maxv] = {false};
vector<int> pre[maxv], tempath, path; 
void dijkstra(int s) {
	fill(d, d + maxv, inf);
	d[s] = 0;
	for(int i = 0; i <= n; i++) {
		int u = -1, min = inf;
		for(int j = 0; j <= n; j++) {
			if(vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++) {
			if(vis[v] == false && G[u][v] != inf) {
				if(d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(d[v] == d[u] + G[u][v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs(int v) {
	if(v == 0) {
		tempath.push_back(v);
		int need = 0, remain = 0;
		for(int i = tempath.size() - 1; i >= 0; i--) {
			int id = tempath[i];
			if(weight[id] > 0) {
				remain += weight[id];
			} else {
				if(remain + weight[id] > 0) {
					remain += weight[id];
				} else {
					need += abs(remain + weight[id]);
					remain = 0;
				}
			}
		}
		if(need < minneed) {
			minneed = need;
			minremain = remain;
			path = tempath;
		} else if(need == minneed && remain < minremain) {
			minremain = remain;
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
	cin >> Cmax >> n >> sp >> m;
	fill(G[0], G[0] + maxv * maxv, inf);
	for(int i = 1; i <= n; i++) {
		cin >> weight[i];
		weight[i] -= Cmax / 2;	//preprocessing: make it 'perfect'
	}
	int u, v, dis;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> dis;
		G[u][v] = G[v][u] = dis;
	}
	dijkstra(0);
	dfs(sp);
	cout << minneed << ' ';
	for(int i = path.size() - 1; i >=0; i--) {
		cout << path[i];
		if(i > 0) cout << "->";
	}
	cout << ' ' << minremain;
	return 0;
}
