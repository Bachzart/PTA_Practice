#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 20 + 5;
int G[maxn][maxn], n;
bool isvisit[maxn] = {false};
void dfs(int node, int &num) {
	isvisit[node] = true;
	num++;
	for(int i = 0; i < n; i++) {
		if(!isvisit[i] && G[node][i]) dfs(i, num);
	}
}
int bfs(int node) {
	queue<int> q;
	q.push(node);
	isvisit[node] = true;
	int num = 1;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i = 0; i < n; i++) {
			if(!isvisit[i] && G[front][i]) {
				num++;
				q.push(i);
				isvisit[i] = true;
			}
		}
	}
	return num;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> G[i][j]; 
		}
	}
	int v1, v2, num1 = 0, num2 = 0;
	cin >> v1 >> v2;
//	dfs(v1, num1);
	num1 = bfs(v1);
	memset(isvisit, 0, sizeof(isvisit));
//	dfs(v2, num2);
	num2 = bfs(v2);
	cout << num1 << endl << num2 << endl;
	isvisit[v1] ? cout << "Yes" : cout << "No";
	return 0;
} 
