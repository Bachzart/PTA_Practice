#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxv = 1020;
const int inf = 0x3fffffff;
int n, m, k, ds, G[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};
void dijkstra(int s) {
	memset(vis, false, sizeof(vis)); //do not forget initializing this array
	fill(d, d + maxv, inf);
	d[s] = 0;
	for(int i = 0; i < n + m; i++) {
		int u = -1, min = inf;
		for(int j = 1; j <= n + m; j++) {
			if(vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 1; v <= n + m; v++) {
			if(vis[v] == false && G[u][v] != inf) {
				if(d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}
int getid(char str[]) { //tranfer the id of gas station
	int i = 0, len = strlen(str), id = 0;
	while(i < len) {
		if(str[i] != 'G') {
			id = id * 10 + (str[i] - '0');
		}
		i++;
	}
	if(str[0] == 'G') return n + id;
	else return id;
}
int main(int argc, char const *argv[]) {
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	int u, v, w;
	char city1[5], city2[5];
	fill(G[0], G[0] + maxv * maxv, inf);
	for(int i = 0; i < k; i++) {
		scanf("%s %s %d", city1, city2, &w);
		u = getid(city1);
		v = getid(city2);
		G[v][u] = G[u][v] = w;
	}
	double ansdis = -1, ansavg = inf;
	int ansid = -1;
	for(int i = n + 1; i <= n + m; i++) {
		double mindis = inf, avg = 0;
		dijkstra(i); //every station should execute this dijkstra
		for(int j = 1; j <=n; j++) {
			if(d[j] > ds) {	//this solution does not fit the problem
				mindis = -1;
				break;
			}
			if(d[j] < mindis) mindis = d[j]; //cal minimum of distance
			avg += 1.0 * d[j] / n; //calculate the average
		}
		if(mindis == -1) continue;
		if(mindis > ansdis) { //more optimal solution
			ansid = i;
			ansdis = mindis;
			ansavg = avg;
		} else if(mindis == ansdis && avg < ansavg) { //more optimal solution
			ansid = i;
			ansavg = avg;
		}
	}
	if(ansid == -1) printf("No Solution\n");
	else {
		printf("G%d\n", ansid - n);
		printf("%.1lf %.1lf\n", ansdis, ansavg);
	}
	return 0;
}
