/* method 1: use dijkstra and dfs
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
const int maxv = 210;
const int inf = 0x3fffffff;
int n, k, G[maxv][maxv], weight[maxv];
int d[maxv], numpath = 0, maxw = 0;
double maxavg = 0;
bool vis[maxv] = {false};
map<string, int> city2index;
map<int, string> index2city;
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
		numpath++;
		int tempw = 0;
		for(int i = tempath.size() - 1; i >= 0; i--) {
			int id = tempath[i];
			tempw += weight[id];
		}
		double tempavg = 1.0 * tempw / (tempath.size() - 1);
		if(tempw > maxw) {
			maxw = tempw;
			maxavg = tempavg;
			path = tempath;
		} else if(tempw == maxw && tempavg > maxavg) {
			maxavg = tempavg;
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
	string city1, city2;
	cin >> n >> k >> city1;
	city2index[city1] = 0;
	index2city[0] = city1;
	for(int i = 1; i < n; i++) {
		cin >> city1 >> weight[i];
		index2city[i] = city1;
		city2index[city1] = i;
	}
	fill(G[0], G[0] + maxv * maxv, inf);
	int u, v, dis;
	for(int i = 0; i < k; i++) {
		cin >> city1 >> city2 >> dis;
		u = city2index[city1];
		v = city2index[city2];
		G[u][v] = G[v][u] = dis;
	}
	dijkstra(0);
	int rom = city2index["ROM"];
	dfs(rom);
	cout << numpath << ' ' << d[rom] << ' ' << maxw << ' ' << 
	(int)maxavg << endl;
	for(int i = path.size() - 1; i >= 0; i--) {
		cout << index2city[path[i]];
		if(i > 0) cout << "->";
	}
	return 0;
}


/* method 2: only use dijkstra

#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;
const int maxv = 210;
const int inf = 0x3fffffff;
int n, k, G[maxv][maxv], weight[maxv];
int d[maxv], w[maxv] = {0}, num[maxv] = {0}, pt[maxv] = {0}, pre[maxv];
bool vis[maxv] = {false};
map<string, int> city2index;
map<int, string> index2city;
void dijkstra(int s) {
	fill(d, d + maxv, inf);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
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
				if(d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					pre[v] = u;
					num[v] = num[u];
					w[v] = w[u] + weight[v];
					pt[v] = pt[u] + 1;
				} else if(d[v] == d[u] + G[u][v]) {
					num[v] += num[u]; 
					if(w[v] < w[u] + weight[v]) {
						w[v] = w[u] + weight[v];
						pre[v] = u;
						pt[v] = pt[u] + 1;
					} else if(w[v] == w[u] + weight[v]) {
						double uavg = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
						double vavg = 1.0 * w[v] / pt[v];
						if(uavg > vavg) {
							pt[v] = pt[u] + 1;
							pre[v] = u;
						}
					}
				}
			}
		}
	}
}
void dfs(int v) {
	if(v == 0) {
		cout << index2city[v];
		return;
	}
	dfs(pre[v]);
	cout << "->" << index2city[v];
}
int main(int argc, char const *argv[]) {
	string city1, city2;
	cin >> n >> k >> city1;
	city2index[city1] = 0;
	index2city[0] = city1;
	for(int i = 1; i < n; i++) {
		cin >> city1 >> weight[i];
		city2index[city1] = i;
		index2city[i] = city1;
	}
	fill(G[0], G[0] + maxv * maxv, inf);
	int u, v, dis;
	for(int i = 0; i < k; i++) {
		cin >> city1 >> city2 >> dis;
		u = city2index[city1], v = city2index[city2];
		G[u][v] = G[v][u] = dis;
	}
	dijkstra(0);
	int rom = city2index["ROM"];
	cout << num[rom] << ' ' << d[rom] << ' ' << w[rom] << ' ' 
	<< w[rom] / pt[rom] << endl;
	dfs(rom);
	return 0;
}
*/
