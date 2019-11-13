#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
const int inf = 0x3fffffff;
struct node {
	int v, w;
	node(int v, int w) {
		this->v = v;
		this->w = w;
	}
};
bool cmp(int a, int b) {
	return b - a;
}
vector<node> G[maxn];
stack<int> topo;
int nv, ne, ve[maxn] = { 0 }, vl[maxn], indegree[maxn] = { 0 };
bool topoorder() {
	queue<int> q;
	for (int i = 1; i <= nv; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			indegree[G[i][j].v]++;
		}
	}
	for (int i = 1; i <= nv; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			ve[i] = 0;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		topo.push(u);
		q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			indegree[G[u][i].v]--;
			if (ve[G[u][i].v] < ve[u] + G[u][i].w) {
				ve[G[u][i].v] = ve[u] + G[u][i].w;
			}
			if (indegree[G[u][i].v] == 0) q.push(G[u][i].v);
		}
	}
	if (topo.size() != nv) return false;
	else return true;
}
void criticalpath() {
	int max = ve[1], maxid = 1;
	for (int i = 2; i <= nv; i++) {
		if (ve[i] > max) {
			max = ve[i];
			maxid = i;
		}
	}
	cout << max << endl;
	for (int i = 0; i < maxn; i++) vl[i] = max;
	while (!topo.empty()) {
		int u = topo.top();
		topo.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			if (vl[v] - G[u][i].w < vl[u]) {
				vl[u] = vl[v] - G[u][i].w;
			}
		}
	}
	vector<int> keyact[maxn];
	for (int u = 1; u <= nv; u++) {
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v, w = G[u][i].w;
			int e = ve[u], l = vl[v] - w;
			if (e == l) keyact[u].push_back(v);
		}
	}
	for (int i = 1; i <= nv; i++) sort(keyact[i].begin(), keyact[i].end(), cmp);
	for (int u = 1; u <= nv; u++) {
		for (int i = 0; i < keyact[u].size(); i++) {
			cout << u << "->" << keyact[u][i] << endl;
		}
	}
}
int main() {
	cin >> nv >> ne;
	int u, v, w;
	for (int i = 0; i < ne; i++) {
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
	}
	if (!topoorder()) cout << 0;
	else criticalpath();
	return 0;
}

/*
samples:
in:
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
4 6 6
5 7 5
6 7 2
out:
17
1->2
2->4
4->6
6->7

in:
4 4
1 2 2
1 3 2
2 4 2
3 4 2
out:
4
1->3
1->2
2->4
3->4

in:
3 3
1 2 1
2 3 1
3 1 1
out:
0

in:
3 3
1 2 1
1 3 1
2 3 1
out:
2
1->2
2->3

*/
