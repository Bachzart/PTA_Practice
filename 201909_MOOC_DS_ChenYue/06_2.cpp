#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 100 + 5;
struct node{
	double x, y;
} coords[maxn];
int n;
double d;
bool visited[maxn] = {false};
bool firstjump(int v) {
	return sqrt(pow(coords[v].x, 2) + pow(coords[v].y, 2)) - 7.5 <= d;
}
bool jump(int v, int w) {
	return sqrt(pow(coords[v].x - coords[w].x, 2) + pow(coords[v].y - coords[w].y, 2)) <= d;
} 
bool issafe(int v) {
	return fabs(fabs(coords[v].x) - 50) <= d || fabs(fabs(coords[v].y) - 50) <= d;
}
bool DFS(int v) {
	visited[v] = true;
	bool flag = false;
	if(issafe(v)) return true;
	else {
		for(int w = 0; w < n; w++) {
			if(!visited[w] && jump(v, w)) {
				flag = DFS(w);
				if(flag) break;
			}
		}
	}
	return flag;
}
void save007() {
	bool flag = false;
	for(int v = 0; v < n; v++) {
		if(!visited[v] && firstjump(v)) {
			flag = DFS(v);
			if(flag) break;
		}
	}
	flag ? cout << "Yes" : cout << "No";
}
int main() {
	cin >> n >> d;
	for(int v = 0; v < n; v++) {
		cin >> coords[v].x >> coords[v].y;
	}
	save007();
	return 0;
}

/*
sample:
in:
25 -15
-25 28
8 49
29 15
-35 -2
5 28
27 -29
-8 -28
-20 -35
-25 -20
-13 29
-30 15
-35 40
12 12
out:
Yes

in:
4 13
-12 12
12 12
-12 -12
12 -12
out:
No

*/
