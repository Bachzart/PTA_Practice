#include <iostream>
#include <queue>
using namespace std;
const int maxn = 110;
struct node {
	int depth;
	vector<int> child;
} Node[maxn];
int n, m, seq, child;
int Depth[maxn] = {0};
void BFS() {
	queue<int> q;
	q.push(1);
	Node[1].depth = 1;
	Depth[Node[1].depth]++;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i = 0; i < Node[front].child.size(); i++) {
			int child = Node[front].child[i];
			Node[child].depth = Node[front].depth + 1;
			Depth[Node[child].depth]++;
			q.push(child);
		}
	}
}

int main(int argc, char const *argv[]) {
	cin >> n >> m;
	int k;
	for(int i = 0; i < m; i++) {
		cin >> seq >> k;
		for(int j = 0; j < k; j++) {
			cin >> child;
			Node[seq].child.push_back(child);
		}
	}
	BFS();
	int max = -1, l = 1;
	for(int i = 0; i < maxn; i++) {
		if(Depth[i] > max) {
			max = Depth[i];
			l = i;
		}
	}
	cout << Depth[l] << ' ' << l << endl;
	return 0;
}
