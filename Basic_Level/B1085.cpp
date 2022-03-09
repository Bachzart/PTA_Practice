#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>
using namespace std;
const int maxn = 100000 + 5;
struct school{
	string name;
	int sum_score, A, B, T, rank, men;
} sch[maxn];
map<string, int> sch_name2num;
bool cmp(school a, school b) {
	if(a.sum_score != b.sum_score) return a.sum_score > b.sum_score;
	else if(a.men != b.men) return a.men < b.men;
	else return a.name < b.name;
}
void Init() {
	for(int i = 0; i < maxn; i++) {
		sch[i].sum_score = sch[i].A = sch[i].B = sch[i].T = sch[i].men =  0;
		sch[i].rank = maxn; 
	}
}
int main() {
	Init();
	int n, score, count = 0;
	cin >> n;
	string stu_name, sch_name;
	while(n--) {
		cin >> stu_name >> score >> sch_name;
		for(int i = 0; i < sch_name.length(); i++) {
			sch_name[i] = tolower(sch_name[i]);
		}
		if(sch_name2num.find(sch_name) == sch_name2num.end()) {
			sch[count].name = sch_name;
			sch_name2num[sch_name] = count++;
		}
		if(stu_name[0] == 'B') {
			sch[sch_name2num[sch_name]].B += score;
		} else if(stu_name[0] == 'A') {
			sch[sch_name2num[sch_name]].A += score;
		} else if(stu_name[0] == 'T') {
			sch[sch_name2num[sch_name]].T += score;
		}
		sch[sch_name2num[sch_name]].men++;
	}
	for(int i = 0; i < count; i++) {
		sch[i].sum_score = (int)(sch[i].B / 1.5 + sch[i].A + sch[i].T * 1.5);
	}
	sort(sch, sch + count, cmp);
	sch[0].rank = 1;
	cout << count << endl;
	cout << sch[0].rank << ' ' << sch[0].name << ' ' << sch[0].sum_score << ' ' << sch[0].men << endl; 
	for(int i = 1; i < count; i++) {
		if(sch[i].sum_score == sch[i - 1].sum_score) sch[i].rank = sch[i - 1].rank;
		else sch[i].rank = i + 1;
		cout << sch[i].rank << ' ' << sch[i].name << ' ' << sch[i].sum_score << ' ' << sch[i].men << endl; 
	}
	return 0;
}
