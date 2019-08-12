#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;

map<int, string> intTostring;
map<string, int> stringToint;
map<string, int> Gang;
int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, numPerson = 0;
bool visited[maxn] = {false};
void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
	numMember++;
	visited[nowVisit] = true;
	if(weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for(int i = 0; i < numPerson; i++) {
		if(G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(visited[i] == false) {
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}
void DFSTrave() {
	for(int i = 0; i < numPerson; i++) {
		if(visited[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if(numMember > 2 && totalValue > k) {
				Gang[intTostring[head]] = numMember;
			}
		}
	}
}
int change(string s) {
	if(stringToint.find(s) != stringToint.end()) {
		return stringToint[s];
	} else {
		stringToint[s] = numPerson;
		intTostring[numPerson] = s;
		return numPerson++;
	}
}
int main(int argc, char const *argv[]) {
	int w;
	string s1, s2;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = change(s1);
		int id2 = change(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for(it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
	return 0;
} 
