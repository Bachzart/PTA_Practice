/* notes: use vector to simulate adjacency list */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1000 + 5;
int nv, ne;
vector<int> G[maxn];
int BFS(int v) {
	bool visited[maxn] = {false};
	queue<int> q;
	q.push(v);
	visited[v] = true;
	int count = 1, level = 0, last = v, tail;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i = 0; i < G[front].size(); i++) {
			int w = G[front][i];
			if(!visited[w]) {
				q.push(w);
				visited[w] = true;
				tail = w;
				count++;
			}
		}
		if(front == last) {
			level++;
			last = tail;
		}
		if(level == 6) break;
	}
	return count;
}
void sds() {
	for(int v = 1; v <= nv; v++) {
		int count = BFS(v);
		printf("%d: %.2lf%%\n", v, 1.0 * count / nv * 100);
	}
}
int main() {
	scanf("%d %d", &nv, &ne);
	int v1, v2;
	for(int i = 0; i < ne; i++) {
		scanf("%d %d", &v1, &v2);
		G[v1].push_back(v2), G[v2].push_back(v1);
	}
	sds();
	return 0;
}

/*
samples:
in:
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
out:
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%

*/
