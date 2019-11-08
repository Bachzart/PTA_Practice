#include <stdio.h>
#include <stdbool.h> 
#define maxn 1005
const int inf = 0x3fffffff;
int nv, ne, G[maxn][maxn], dist[maxn];
bool visited[maxn] = { false };
void init() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			G[i][j] = inf;
		}
	}
}
void prim() {
	for (int i = 0; i < maxn; i++) dist[i] = inf;
	dist[1] = 0;
	int times = 0;
	for (int t = 1; t <= nv; t++) {
		int mindis = inf, v = -1;
		for (int i = 1; i <= nv; i++) {
			if (!visited[i] && dist[i] < mindis) {
				mindis = dist[i];
				v = i;
			}
		}
		if (v == -1) break;
		times++;
		visited[v] = true;
		for (int w = 1; w <= nv; w++) {
			if (G[v][w] != inf && !visited[w] && G[v][w] < dist[w]) {
				dist[w] = G[v][w];
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= nv; i++) {
		cnt += dist[i];
	}
	if (times == nv) printf("%d", cnt);
	else printf("-1");
}
int main() {
	scanf("%d %d", &nv, &ne);
	init();
	int v1, v2, weight;
	for (int i = 0; i < ne; i++) {
		scanf("%d %d %d", &v1, &v2, &weight);
		G[v1][v2] = G[v2][v1] = weight;
	}
	prim();
	return 0;
}

/*
samples:
in:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
out:
12

*/
