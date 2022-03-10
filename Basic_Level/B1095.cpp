#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int maxn = 10000 +5;
struct student {
	char level;
	string id, exam_room, exam_date;
	int score;
} stu[maxn];
struct examroom {
	string roomid;
	int men;
} examro[maxn];
bool cmp1(student &a, student &b) {
	if(a.level != b.level) return a.level < b.level;
	else if(a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}
bool cmp2(examroom &a, examroom &b) {
	if(a.men != b.men) return a.men > b.men;
	else return a.roomid < b.roomid;
}
void Init_examro() {
	for(int i = 0; i < maxn; i++) {
		examro[i].roomid.resize(10);
		examro[i].men = 0;
	}
}
int main() {
	int n, m, mode;
	string md, tmp;
	tmp.resize(15);
	scanf("%d %d%*c", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%c%s %d%*c", &stu[i].level, tmp.c_str(), &stu[i].score);
		stu[i].exam_room = tmp.substr(0, 3);
		stu[i].exam_date = tmp.substr(3, 6);
		stu[i].id = tmp;
	}
	for(int i = 1; i <= m; i++) {
		cin >> mode >> md;
		bool flag = false;
		printf("Case %d: %d %s\n", i, mode, md.c_str());
		if(mode == 1) {
			sort(stu, stu + n, cmp1);
			for(int i = 0; i < n; i++) {
				if(md[0] == stu[i].level) {
					printf("%c%s %d\n", stu[i].level, stu[i].id.c_str(), stu[i].score);
					flag = true;
				}
			}
		} else if(mode == 2) {
			int sum = 0, men = 0;
			for(int i = 0; i < n; i++) {
				if(md == stu[i].exam_room) {
					sum += stu[i].score;
					men++;
				}
			}
			if(men) {
				printf("%d %d\n", men, sum);
				flag = true;
			}
		} else if(mode == 3) {
			int count = 0;
			unordered_map<string, int> room2num;
			Init_examro();
			for(int i = 0; i < n; i++) {
				if(md == stu[i].exam_date) {
					if(room2num.find(stu[i].exam_room) == room2num.end()) {
						room2num[stu[i].exam_room] = count++;
						examro[room2num[stu[i].exam_room]].roomid = stu[i].exam_room;
					}
					examro[room2num[stu[i].exam_room]].men++;
				}
			}
			sort(examro, examro + count, cmp2);
			for(int i = 0; i < count; i++) {
				printf("%s %d\n", examro[i].roomid.c_str(), examro[i].men);
				flag = true;
			}
		}
		if(!flag) cout << "NA" << endl;
	}
	return 0;
}
