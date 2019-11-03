#include <iostream>
using namespace std;
const int maxn = 100 + 5;
const int inf = 0x3fffffff;
int n, m, G[maxn][maxn], dist[maxn][maxn];
void floyd() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dist[i][j] = G[i][j];
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dist[i][k] + dist[k][j] < dist[i][j] && i != j) {
					dist[i][j] = dist[i][k] + dist[k][j]; 
				}
			}
		}
	}
}
void findanimal() {
	floyd();
	int mindist = inf;
	int animal;
	for(int i = 1; i <= n; i++) {
		int maxdist = 0;
		for(int j = 1; j <= n; j++) {
			if(i != j && dist[i][j] > maxdist) maxdist = dist[i][j];
		}
		if(maxdist == inf) {
			cout << 0;
			return;
		}
		if(mindist > maxdist) {
			mindist = maxdist;
			animal = i;
		}
	}
	cout << animal << ' ' << mindist;
}
int main() {
	fill(G[0], G[0] + maxn * maxn, inf);
	cin >> n >> m;
	int v1, v2;
	for(int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		cin >> G[v1][v2];
		G[v2][v1] = G[v1][v2];
	}
	findanimal();
	return 0;
}

/*
samples:
in:
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
out:
4 70

*/
