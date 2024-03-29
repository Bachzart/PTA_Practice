#include <cstdio>
#include <queue>
using namespace std;
struct node {
	int x, y, z;
} Node;
int n, m, slice, T;
int pixel[1290][130][61];
bool inqueue[1290][130][61];
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z) {
	if(x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
	if(pixel[x][y][z] == 0 || inqueue[x][y][z] == true) return false;
	return true;
}

int BFS(int x, int y, int z) {
	int tot = 0;
	queue<node> Q;
	Node.x = x, Node.y = y, Node.z = z;
	Q.push(Node);
	inqueue[x][y][z] = true;
	while(!Q.empty()) {
		node top = Q.front();
		Q.pop();
		tot++;
		for(int i = 0; i < 6; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)) {
				Node.x = newX, Node.y = newY, Node.z = newZ;
				Q.push(Node);
				inqueue[newX][newY][newZ] = true;
			}
		}
	}
	if(tot >= T) return tot;
	else return 0;
}

int main(int argc, char const *argv[]) {
	scanf("%d %d %d %d", &n, &m, &slice, &T);
	for(int z = 0; z < slice; z++) {
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < m; y++) {
				scanf("%d", &pixel[x][y][z]);
			}
		}
	}
	int ans = 0;
	for(int z = 0; z < slice; z++) {
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < m; y++) {
				if(pixel[x][y][z] == 1 && inqueue[x][y][z] == false) {
					ans += BFS(x, y, z);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
