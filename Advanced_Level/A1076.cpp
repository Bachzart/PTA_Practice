#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010;
struct node {
	int id;
	int layer;
};
vector<node> Adj[maxn];
bool inq[maxn] = {false};
int BFS(int s, int L) {
	int numFoward = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()) {
		node top = q.front();
		q.pop();
		int u = top.id;
		for(int i = 0; i < Adj[u].size(); i++) {
			node next = Adj[u][i];
			next.layer = top.layer + 1;
			if(inq[next.id] == false && next.layer <= L) {
				q.push(next);
				inq[next.id] = true;
				numFoward++;
			}
		}
	}
	return numFoward;
}

int main(int argc, char const *argv[]) {
	node user;
	int n, L, numFollow, idFollow;
	cin >> n >> L;
	for(int i = 1; i <= n; i++) {
		user.id = i;
		cin >> numFollow;
		for(int j = 0; j < numFollow; j++) {
			cin >> idFollow;
			Adj[idFollow].push_back(user);
		}
	}
	int numQuery, s;
	cin >> numQuery;
	while(numQuery--) {
		memset(inq, false, sizeof(inq));
		cin >> s;
		int numFoward = BFS(s, L);
		cout << numFoward << endl;
	}
	return 0;
}
