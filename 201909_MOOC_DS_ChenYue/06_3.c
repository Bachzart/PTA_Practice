#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxn 1005
const int inf = 0x3fffffff;
int G[maxn][maxn], nv, ne;
bool visited[maxn];
void init() {
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			G[i][j] = inf;
		}
	}
}
int BFS(int v) {
	memset(visited, false, sizeof(visited));
	visited[v] = true;
	int Queue[maxn], front = -1, rear = -1;
	Queue[++rear] = v;
	int count = 1, level = 0, last = v, tail;
	while(front < rear) {
		int first = Queue[++front];
		for(int w = 1; w <= nv; w++) {
			if(!visited[w] && G[first][w] != inf) {
				Queue[++rear] = w;
				visited[w] = true;
				tail = w;
				count++;
			}
		}
		if(first == last) {
			level++;
			last = tail;
		}
		if(level == 6) break;
	}
	return count;
}
void sds() {
	for(int i = 1; i <= nv; i++) {
		int count = BFS(i);
		printf("%d: %.2lf%%\n", i, (double)count / nv * 100.0);
	}
}
int main() {
	init();
	scanf("%d %d", &nv, &ne);
	int v1, v2;
	for(int i = 0; i < ne; i++) {
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
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
