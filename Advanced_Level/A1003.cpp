/*method 1: use bellman-ford
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
struct node {
	int v, dis;
	node(int _v, int _dis) : v(_v), dis(_dis) {}	// constructor
};
const int maxv = 510;
const int inf = 0x3fffffff;
int n, m, st, ed, weight[maxv];
int num[maxv] = {0}, w[maxv] = {0}, d[maxv];
vector<node> Adj[maxv];
set<int> pre[maxv];
bool bellmanford(int s) {
	fill(d, d + maxv, inf);
	d[s] = 0;
	num[s] = 1;
	w[s] = weight[s];
	for(int i = 0; i < n - 1; i++) {
		for(int u = 0; u < n; u++) {
			for(int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]) {	// more optimal solution
					d[v] = d[u] + dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();	// attention: pre[v] must be cleared firstly
					pre[v].insert(u);	// save the precursor
				} else if(d[u] + dis == d[v]) {
					if(w[v] < w[u] + weight[v]) {	// update the maximum
						w[v] = w[u] + weight[v];
					}
					pre[v].insert(u);	// other shortest path also need save
					/* the number of shortest path has been changed, so 
					num[v] must be cleared firstly */
					num[v] = 0;
					set<int>::iterator it;
					for(it = pre[v].begin(); it != pre[v].end(); it++) {
						num[v] += num[*it];
					}
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
	int u, v, dis;
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> dis;
		Adj[u].push_back(node(v, dis));
		Adj[v].push_back(node(u, dis));
	}
	bellmanford(st);
	cout << num[ed] << ' ' << w[ed];
	return 0;
}

/* method 2: use dijkstra

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
					// only one path can count the 'hands', so the w[v] will
					// be covered by the sum of last node and its own 'hands'
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
*/
