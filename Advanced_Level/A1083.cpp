#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;
struct student{
	char name[15], id[15];
	int grade;
} stu[MAXN];
bool cmp(student a, student b);

int main(int argc, char const *argv[]) {
	int N, grade1, grade2;
	scanf("%d", &N); 
	for(int i = 0; i < N; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade); 
	}
	scanf("%d %d", &grade1, &grade2);
	sort(stu, stu + N, cmp);
	bool flag = false;
	for(int i = 0; i < N; i++) {
		if(grade1 <= stu[i].grade && stu[i].grade <= grade2) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true;
		}
	}
	if(!flag) {
		printf("NONE\n");
	}
	return 0;
}

bool cmp(student a, student b) {
	return a.grade > b.grade;
}

/* C++ */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
struct student {
	string name, id;
	int grade;
} stu[maxn];
int n;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].id >> stu[i].grade;
	}
	sort(stu, stu + n, [](student a, student b) {
		return a.grade > b.grade;
	});
	int left, right, cnt = 0;
	cin >> left >> right;
	for(int i = 0; i < n; i++) {
		if(left <= stu[i].grade && stu[i].grade <= right) {
			cout << stu[i].name << ' ' << stu[i].id << endl;
			cnt++;
		}
	}
	if(!cnt) cout << "NONE" << endl;
	return 0;
}