/* method 1: use union-find set
*/
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
int father[maxn];
bool vis[maxn];
int n, m, k;
int findFather(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];
	}
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) {
		father[faA] = faB;
	}
}
void init() {
	for(int i = 1; i < maxn; i++) {
		father[i] = i;
		vis[i] = false;
	}
}
int main(int argc, char const *argv[]) {
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int currentPoint;
	for(int query = 0; query < k; query++) {
		cin >> currentPoint;
		init();
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < G[i].size(); j++) {
				int u = i, v = G[i][j];
				if(u == currentPoint || v == currentPoint) continue;
				Union(u, v);
			}
		}
		int block = 0;
		for(int i = 1; i <= n; i++) {
			if(i == currentPoint) continue;
			int fa_i = findFather(i);
			if(vis[fa_i] == false) {
				block++;
				vis[fa_i] = true;
			}
		}
		cout << block - 1 << endl;
	}
	return 0;
}


/*method 2: use DFS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
bool vis[maxn] = {false};

int currentPoint;
int n, m, k;
void dfs(int v) {
	if(v == currentPoint) return;
	vis[v] = true;
	for(int i = 0; i < G[v].size(); i++) {
		if(vis[G[v][i]] == false) {
			dfs(G[v][i]);
		}
	}
}
int main(int argc, char const *argv[]) {
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int query = 0; query < k; query++) {
		cin >> currentPoint;
		memset(vis, false, sizeof(vis));
		int block = 0;
		for(int i = 1; i <= n; i++) {
			if(i != currentPoint && vis[i] == false) {
				dfs(i);
				block++;
			}
		}
		cout << block - 1 << endl;
	}

	return 0;
}
*/
