#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100 + 5;
const int inf = 0x3fffffff;
struct node{
	int w, weight;
	node(int w, int weight) {
		this->w = w;
		this->weight = weight;
	}
};
vector<node> G[maxn];
int nv, ne, indegree[maxn] = { 0 }, cost[maxn];
void topsort() {
	queue<int> q;
	for (int v = 0; v < nv; v++) {
		for (int w = 0; w < G[v].size(); w++) {
			indegree[G[v][w].w]++;
		}
	}
	for (int i = 0; i < maxn; i++) cost[i] = -1;
	int count = 0;
	for (int i = 0; i < nv; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			cost[i] = 0;
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		count++;
		for (int w = 0; w < G[v].size(); w++) {
			indegree[G[v][w].w]--;
			if (cost[G[v][w].w] < cost[v] + G[v][w].weight) {
				cost[G[v][w].w] = cost[v] + G[v][w].weight;
			}
			if (indegree[G[v][w].w] == 0) {
				q.push(G[v][w].w);
				
			}
		}
	}
	if (count != nv) cout << "Impossible";
	else {
		int max = cost[0];
		for (int i = 1; i < nv; i++) {
			if (max < cost[i]) max = cost[i];
		}
		cout << max;
	}
}
int main() {
	cin >> nv >> ne;
	int v1, v2, weight;
	for (int i = 0; i < ne; i++) {
		cin >> v1 >> v2 >> weight;
		G[v1].emplace_back(v2, weight);
	}
	topsort();
	return 0;
}

/*
samples:
in:
9 12
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
5 4 0
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
out:
18

in:
4 5
0 1 1
0 2 2
2 1 3
1 3 4
3 2 5
out:
Impossible

in:
7 6
0 3 2
3 4 2
1 2 3
2 4 2
4 5 3
4 6 2
out:
8


*/