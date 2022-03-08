#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100000 + 5;
struct student {
	string name;
	int gp, gmt, gf, g;
} stu[maxn];
map<string, int> name2num;
void init() {
	for(int i = 0; i < maxn; i++) {
		stu[i].g = stu[i].gf = stu[i].gmt = stu[i].gp = -1;
	}
}
bool cmp(student a, student b) {
	if(a.g != b.g) return a.g > b.g;
	else return a.name < b.name;
}
int main() {
	init();
	int p, m, n, count = 0, tmp;
	cin >> p >> m >> n;
	string str;
	for(int i = 0; i < p; i++) {
		cin >> str >> tmp;
		stu[count].name = str;
		stu[count].gp = tmp;
		name2num[str] = count++;
	}
	map<string, int>::iterator it;
	for(int i = 0; i < m; i++) {
		cin >> str >> tmp;
		it = name2num.find(str);
		if(it == name2num.end()) {
			stu[count].gmt = tmp;
			stu[count].name = str;
			name2num[str] = count++;
		} else stu[it->second].gmt = tmp;
	}
	for(int i = 0; i < n; i++) {
		cin >> str >> tmp;
		it = name2num.find(str);
		if(it == name2num.end()) {
			stu[count].gf = tmp;
			stu[count].name = str;
			name2num[str] = count++;
		} else stu[it->second].gf = tmp;
	}
	int a, b;
	for(int i = 0; i < count; i++) {
		if(stu[i].gp < 200) continue;
		else {
			a = stu[i].gmt, b = stu[i].gf;
			if(a <= b) stu[i].g = b;
			else stu[i].g = (int)((a * 0.4 + b * 0.6) + 0.5);
		}
	}
	sort(stu, stu + count, cmp);
	for(int i = 0; i < count; i++) {
		if(stu[i].g >= 60) {
			cout << stu[i].name << ' ' << stu[i].gp << ' ' << stu[i].gmt \
			     << ' ' << stu[i].gf  << ' ' << stu[i].g << endl;
		}
	}
	return 0;
}
