#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct car{
	char id[8];
	int time;
	char status[4];
} all[maxn], valid[maxn];
int num = 0;
map<string, int> parkTime;
int time2int(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}
bool cmpbyidandtime(car a, car b) {
	if(strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
	else return a.time < b.time;
}
bool cmpbytime(car a, car b) {
	return a.time < b.time;
}
int main(int argc, char const *argv[]) {
	int n, k, hh, mm, ss;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
		all[i].time = time2int(hh, mm, ss);
	}
	sort(all, all + n, cmpbyidandtime);
	int maxTime = -1;
	for(int i = 0; i < n - 1; i++) {
		if(!strcmp(all[i].id, all[i + 1].id) && 
		!strcmp(all[i].status, "in") && 
		!strcmp(all[i + 1].status, "out")) {
			valid[num++] = all[i];
			valid[num++] = all[i + 1];
			int inTime = all[i + 1].time - all[i].time;
			if(parkTime.count(all[i].id) == 0) {
				parkTime[all[i].id] = 0;
			}
			parkTime[all[i].id] += inTime;
			maxTime = max(maxTime, parkTime[all[i].id]);
		}
	} 
	sort(valid, valid + num, cmpbytime);
	int now = 0, numcar = 0;
	for(int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = time2int(hh, mm, ss);
		while(now < num && valid[now].time <= time) {
			if(!strcmp(valid[now].status, "in")) numcar++;
			else numcar--;
			now++;
		}
		printf("%d\n", numcar);
	}
	map<string, int>::iterator it;
	for(it = parkTime.begin(); it != parkTime.end(); it++) {
		if(it->second == maxTime) {
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	return 0;
}
