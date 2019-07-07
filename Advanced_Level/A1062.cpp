#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;
struct student {
	char id[10];
	int scoreD, scoreC, sumDC, flag;
} stu[MAXN];
int N, L, H, M = 0;

bool cmp(student a, student b);

int main(int argc, char const *argv[]) {
	scanf("%d %d %d", &N, &L, &H);
	for(int i = 0; i < N; i++) {
		scanf("%s %d %d", stu[i].id, &stu[i].scoreD, &stu[i].scoreC);
		stu[i].sumDC = stu[i].scoreD + stu[i].scoreC;
		if(stu[i].scoreC >= L && stu[i].scoreD >= L) {
			if(stu[i].scoreD >= H && stu[i].scoreC >= H) {
				stu[i].flag = 1;
			} else if(stu[i].scoreD >= H && stu[i].scoreC >= L) {
				stu[i].flag = 2;
			} else if(stu[i].scoreC >= L && stu[i].scoreD >= L && stu[i].scoreD >= stu[i].scoreC) {
				stu[i].flag = 3;
			} else {
				stu[i].flag = 4;
			}
			M++;
		} else {
			stu[i].flag = 5;
		}
	}
	printf("%d\n", M);
	sort(stu, stu + N, cmp);
	for(int i = 0; i < M; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].scoreD, stu[i].scoreC);
	}
	return 0;
}

bool cmp(student a, student b) {
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.sumDC != b.sumDC) return a.sumDC > b.sumDC;
	else if(a.scoreD != b.scoreD) return a.scoreD > b.scoreD;
	else return strcmp(a.id, b.id) < 0;
}
