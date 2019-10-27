#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 10 + 5;
const int inf = 0x3fffffff;
int G[maxn][maxn], nv, ne;
bool visited[maxn] = {false};
void init() {
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			G[i][j] = inf;
		}
	}
}
void dfs(int node) {
	visited[node] = true;
	cout << node << ' ';
	for(int i = 0; i < nv; i++) {
		if(!visited[i] && G[node][i] != inf) dfs(i);
	} 
}
void bfs(int node) {
	queue<int> q;
	cout << node << ' ';
	visited[node] = true;
	q.push(node);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i = 0; i < nv; i++) {
			if(!visited[i] && G[front][i] != inf) {
				cout << i << ' ';
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
void listcomponents() {
	for(int i = 0; i < nv; i++) {
		if(!visited[i]) {
			cout << "{ ";
			dfs(i);
			cout << "}\n";
		}
	}
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < nv; i++) {
		if(!visited[i]) {
			cout << "{ ";
			bfs(i);
			cout << "}\n";
		}
	}
}
int main() {
	init();
	cin >> nv >> ne;
	for(int i = 0; i < ne; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	} 
	listcomponents();
	return 0;
} 

/*
some samples:
in:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
out:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }

*/
