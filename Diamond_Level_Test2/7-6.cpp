/* method 1: use hashtable, AC */
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100000 + 5;
int hashtable[maxn] = {0};
bool visited[maxn] = {false};

int main() {
	int n, id, m, k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &k);
		vector<int> tmp;
		for(int i = 0; i < k; i++) {
			scanf("%d", &id);
			tmp.push_back(id);
		}
		for(int i = 0; i < k; i++) {
			id = tmp[i];
			for(int j = 0; j < k; j++) {
				if(j != i && id != tmp[j]) hashtable[id]++;
			}
		}
	}
	scanf("%d", &m);
	vector<int> ans;
	for(int i = 0; i < m; i++) {
		scanf("%d", &id);
		if(!visited[id] && hashtable[id] == 0) {
			ans.push_back(id);
			visited[id] = true;
		}
	}
	if(ans.size() == 0) printf("No one is handsome");
	else {
		for(int i = 0; i < ans.size(); i++) {
			printf("%05d", ans[i]);
			if(i != ans.size() - 1) printf(" ");
		}
	}
	return 0;
}

/* method 2: use stl. This method will cause memory limit exceeded, because use the set.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int maxn = 100000 + 5;
vector<unordered_set<int>> peo(maxn);
bool visited[maxn] = {false};

int main() {
	int n, id, m, k, t;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> k;
		vector<int> tmp;
		for(int i = 0; i < k; i++) {
			cin >> t;
			tmp.push_back(t);
		}
		for(int i = 0; i < k; i++) {
			t = tmp[i];
			for(int j = 0; j < k; j++) {
				if(j != i && t != tmp[j]) peo[t].insert(tmp[j]);
			}
		}
	}
	cin >> m;
	vector<int> ans;
	for(int i = 0; i < m; i++) {
		cin >> id;
		if(!visited[id] && peo[id].size() == 0) {
			ans.push_back(id);
			visited[id] = true;
		}
	}
	if(ans.size() == 0) cout << "No one is handsome";
	else {
		for(int i = 0; i < ans.size(); i++) {
			printf("%05d", ans[i]);
			if(i != ans.size() - 1) printf(" ");
		}
	}
	return 0;
}

*/
