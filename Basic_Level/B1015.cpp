#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;

struct student{
	int id, scoreD, scoreC, sumCD, flag;
} stu[MAXN];

bool cmp(student a, student b);
int N, L, H, M = 0;

int main(int argc, char const *argv[]) {
	scanf("%d %d %d", &N, &L, &H);
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d", &stu[i].id, &stu[i].scoreD, &stu[i].scoreC);
		stu[i].sumCD = stu[i].scoreC + stu[i].scoreD;
		if(stu[i].scoreD >= L && stu[i].scoreC >= L) {
			M++;
			if(stu[i].scoreD >= H && stu[i].scoreC >= H) {
				stu[i].flag = 1;
			} else if(stu[i].scoreD >= H && stu[i].scoreC < H) {
				stu[i].flag = 2;
			} else if(stu[i].scoreD < H && stu[i].scoreD < H && stu[i].scoreD >= stu[i].scoreC) {
				stu[i].flag = 3;
			} else stu[i].flag = 4;
		} else {
			stu[i].flag = 5;
		}
	}
	sort(stu, stu + N, cmp);
	printf("%d\n", M);
	for(int i = 0; i < M; i++) {
		printf("%d %d %d\n", stu[i].id, stu[i].scoreD, stu[i].scoreC);
	}
	return 0;
}

bool cmp(student a, student b) {
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.sumCD != b.sumCD) return a.sumCD > b.sumCD;
	else if(a.scoreD != b.scoreD) return a.scoreD > b.scoreD;
	else return a.id < b.id;
}
