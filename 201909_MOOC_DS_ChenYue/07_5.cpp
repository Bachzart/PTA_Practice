#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100 + 5;
struct node {
    int x, y;
} coords[maxn];
int n, d, path[maxn];
bool vis[maxn] = {false};
int firstjump(int v) {
    int dis = d - sqrt(pow(coords[v].x, 2) + pow(coords[v].y, 2)) + 7.5;
	if(dis > 0) return dis;
	else return 0;
}
bool jump(int v, int w) {
    return sqrt(pow(coords[v].x - coords[w].x, 2) + pow(coords[v].y - coords[w].y, 2)) <= d;
}
bool issafe(int v) {
    return fabs(fabs(coords[v].x) - 50) <= d || fabs(fabs(coords[v].y) - 50) <= d;
}
bool cmp(int a, int b) {
	return firstjump(a) > firstjump(b);
}
void printpath(int inde) {
    if(path[inde] == -1) {
        cout << coords[inde].x << ' ' << coords[inde].y << endl;
        return;
    }
    printpath(path[inde]);
    cout << coords[inde].x << ' ' << coords[inde].y << endl;
}
void save007() {
    if(d >= 50 - 15 / 2) {
        cout << 1;
        return;
    } else {
        int order[maxn];
        queue<int> q;
        for(int i = 0; i < n; i++) {
        	order[i] = i;
        	path[i] = -1;
		}
		sort(order, order + n, cmp);
		int last, tail;
		for(int i = 0; i < n; i++) {
			if(firstjump(order[i])) {
				q.push(order[i]);
				vis[order[i]] = true;
				last = order[i];
			}
		}
		int step = 2;
		while(!q.empty()) {
			int front = q.front(); q.pop();
			if(issafe(front)) {
				cout << step << endl;
				printpath(front);
				return;
			}
			for(int i = 0; i < n; i++) {
				if(!vis[i] && jump(front, i)) {
					q.push(i);
					path[i] = front;
					vis[i] = true;
					tail = i;
				}
			}
			if(last == front) {
				step++;
				last = tail;
			}
		}
		if(q.empty()) cout << 0;
    }
}
int main() {
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        cin >> coords[i].x >> coords[i].y;
    }
    save007();
    return 0;
}

/*
samples:
in:
17 15
10 -21
10 21
-40 10
30 -50
20 40
35 10
0 -10
-25 22
40 -40
-30 30
-10 22
0 11
25 21
25 10
10 10
10 35
-30 10
out:
4
0 11
10 21
10 35

in:
4 13
-12 12
12 12
-12 -12
12 -12
out:
0

in:
1 50
30 30
out:
1


*/
