#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;
struct student{
	char id[10], name[15];
	int grade;
} stu[MAXN];
int N, C;

bool cmp(student a, student b);

int main(int argc, char const *argv[]) {
	scanf("%d %d", &N, &C);
	for(int i = 0; i < N; i++) {
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
	}
	sort(stu, stu + N, cmp);
	for(int i = 0; i < N; i++) {
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}

bool cmp(student a, student b) {
	if(C == 1) {
		return strcmp(a.id, b.id) < 0;
	} else if(C == 2) {
		int temp = strcmp(a.name, b.name);
		if(temp != 0) return temp < 0;
		else return strcmp(a.id, b.id) < 0;
	} else {
		if(a.grade != b.grade) return a.grade < b.grade;
		else return strcmp(a.id, b.id) < 0;
	}
}

/* C++ */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
struct student {
	string id, name;
	int grade;
} stu[maxn];
bool cmp1(student a, student b) {
	if(a.name != b.name) return a.name < b.name;
	else return a.id < b.id;
}
int n, c;
bool cmp(student a, student b) {
	if(c == 1) return a.id < b.id;
	else if(c ==2) {
		if(a.name != b.name) return a.name < b.name;
		else return a.id < b.id;
	} else {
		if(a.grade != b.grade) return a.grade < b.grade;
		else return a.id < b.id;
	}
}
int main() {
	cin >> n >> c;
	for(int i = 0; i < n; i++) {
		cin >> stu[i].id >> stu[i].name >> stu[i].grade;
	}
	sort(stu, stu + n, cmp);
	for(int i = 0; i < n; i++) {
		cout << stu[i].id << ' ' << stu[i].name << ' ' << stu[i].grade << endl;
	}
	return 0;
}