#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000 + 5;
struct user{
	int id, scores[6], sum, perfect;
	bool flag;
} us[maxn];
int n, k, m, p[6] = {0};
bool cmp(user a, user b) {
	if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}
void init() {
	for(int i = 1; i <= n; i++) {
		us[i].id = i;
		us[i].sum = us[i].perfect = 0;
		us[i].flag = false;
		memset(us[i].scores, -1, sizeof(us[i].scores));
	}
}
int main() {
	scanf("%d %d %d", &n, &k, &m);
	init();
	for(int i = 1; i <= k; i++) {
		scanf("%d", p + i);
	}
	int id, proid, scoob;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &id, &proid, &scoob);
		if(scoob != -1) us[id].flag = true;
		if(scoob == -1 && us[id].scores[proid] == -1) us[id].scores[proid] = 0;
		if(scoob == p[proid] && us[id].scores[proid] < p[proid]) us[id].perfect++;
		if(scoob > us[id].scores[proid]) us[id].scores[proid] = scoob;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(us[i].scores[j] > 0) us[i].sum += us[i].scores[j];
		}
	}
	sort(us + 1, us + n + 1, cmp);
	int rank = 1;
	for(int i = 1; i <= n && us[i].flag; i++) {
		if(i > 1 && us[i].sum != us[i - 1].sum) rank = i;
		printf("%d %05d %d", rank, us[i].id, us[i].sum);
		for(int j = 1; j <= k; j++) {
			if(us[i].scores[j] == -1) printf(" -");
			else printf(" %d", us[i].scores[j]);
		}
		putchar('\n');
	}
	return 0;
} 

/*
samples:
in:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
out:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -

in:
3 4 9
20 25 25 30
00001 3 30
00002 3 30
00003 3 30
00001 3 30
00002 3 20
00003 3 20
00001 3 30
00002 3 10
00003 3 30
out:
1 00001 30 - - 30 -
1 00002 30 - - 30 -
1 00003 30 - - 30 -

in:
2 2 6
20 20
00001 1 -1
00002 1 -1
00001 1 -1
00002 1 -1
00001 1 -1
00002 1 0
out:
(blank)

*/
