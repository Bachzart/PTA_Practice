#include <iostream>
using namespace std;
const int maxn = 20 + 5;
int G[maxn][maxn], n;
bool isvisit[maxn];
void dfs(int node, int &num) {
	isvisit[node] = true;
	num++;
	for(int i = 0; i < n; i++) {
		if(!isvisit[i] && G[node][i] == 1) dfs(i, num);
	}
}
void init() {
	for(int i = 0; i < maxn; i++) isvisit[i] = false;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> G[i][j]; 
		}
	}
	int v1, v2, num1, num2;
	cin >> v1 >> v2;
	num1 = num2 = 0;
	init();
	dfs(v1, num1);
	init();
	dfs(v2, num2);
	cout << num1 << endl << num2 << endl;
	if(isvisit[v1]) cout << "Yes";
	else cout << "No";
	return 0;
} 
