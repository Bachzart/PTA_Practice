#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
const int maxn = 1000 + 3;
vector<int> AdjL[maxn];
int n, hashTable[maxn], elements = 0;
bool isvis[maxn] = {false};
map<int, int> value2index;
map<int, int> index2value;
void toposort() {
	int indegree[maxn] = {0};
	for(int v = 0; v < n; v++) {
		for(int w = 0; w < AdjL[v].size(); w++) {
			indegree[AdjL[v][w]]++;
		}
	}
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 0; i < n; i++) {
		if(indegree[i] == 0 && hashTable[i] >= 0) {
			q.push(hashTable[i]);
		}
	}
	int count = 0;
	while(!q.empty()) {
		int tmp = q.top();
		q.pop();
		cout << tmp;
		if(count < elements - 1) {
			cout << ' ';
			count++;
		}
		int v = value2index[tmp];
		for(int w = 0; w < AdjL[v].size(); w++) {
			indegree[AdjL[v][w]]--;
			if(indegree[AdjL[v][w]] == 0) q.push(hashTable[AdjL[v][w]]);
		}
	}
}
int main() {
	cin >> n;
	memset(hashTable, -1, sizeof(hashTable));
	for(int i = 0; i < n; i++) {
		cin >> hashTable[i];
	}
	for(int i = 0; i < n; i++) {
		if(hashTable[i] < 0) continue;
		value2index[hashTable[i]] = i;
		index2value[i] = hashTable[i];
		elements++;
		int tmp = hashTable[i];
		int index = tmp % n;
		if(hashTable[index] == hashTable[i] && index == i) continue;
		else {	
			bool flag = true;
			queue<int> q;
			for(; index < n || flag; index++) {
				if(flag && index >= n) {
					index %= n;
					flag = false;
				}
				if(hashTable[index] == tmp) break;
				q.push(index);
			}
			while(!q.empty()) {
				int front = q.front();
				q.pop();
				AdjL[front].push_back(index); 
			}
		}
	}
	toposort();
	return 0;
} 
