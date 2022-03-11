#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
set<string> xiaoyou;
struct guest{
	string id, birth;
	int flag;
} g[maxn];
bool cmp(guest a, guest b) {
	if(a.flag != b.flag) return a.flag > b.flag;
	else return a.birth < b.birth;
}
int main() {
	string tmp;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		xiaoyou.insert(tmp);
	}
	int count = 0;
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> g[i].id;
		g[i].birth = g[i].id.substr(6, 8);
		if(xiaoyou.find(g[i].id) != xiaoyou.end()) {
			count++;
			g[i].flag = 1;
		}
	}
	sort(g, g + m, cmp);
	cout << count << endl << g[0].id;
	return 0;
} 
