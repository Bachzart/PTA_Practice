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
