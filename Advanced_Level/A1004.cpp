#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
struct node {
	int depth;
    vector<int> child;
} Node[maxn];
int n, m, child, seq, maxDepth = -1;
int leaves[maxn] = {0};
void BFS() {
	queue<int> q;
	q.push(1);
	Node[1].depth = 1;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		if(Node[front].depth > maxDepth) {
			maxDepth = Node[front].depth;
		}
		if(Node[front].child.size() != 0) {
			for(int i = 0; i < Node[front].child.size(); i++) {
				int child = Node[front].child[i];
				Node[child].depth = Node[front].depth + 1;
				q.push(child);
			}
		} else {
			leaves[Node[front].depth]++;
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
    for(int i = 1; i <= maxDepth; i++) {
    	cout << leaves[i];
    	if(i < maxDepth) cout << ' ';
	}
    return 0;
}
