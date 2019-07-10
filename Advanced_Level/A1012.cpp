#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2000 + 5;
struct student {
	int id, grade[4];
} stu[MAXN];
char course[4] = {'A', 'C', 'M', 'E'};
int Rank[10000000][4] = {0};
int now;
bool cmp(student a, student b);

int main(int argc, char const *argv[]) {
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2],
		      &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
	}
	for(now = 0; now < 4; now++) {
		sort(stu, stu + N, cmp);
		Rank[stu[0].id][now] = 1;
		for(int i = 1; i < N; i++) {
			if(stu[i].grade[now] == stu[i - 1].grade[now]) {
				Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
			} else {
				Rank[stu[i].id][now] = i + 1;
			}
		}
	}
	int query;
	while(M--) {
		scanf("%d", &query);
		if(Rank[query][0] == 0) {
			printf("N/A\n");
		} else {
			int k = 0;
			for(int j = 0; j < 4; j++) {
				if(Rank[query][j] < Rank[query][k]) {
					k = j;
				}
			}
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}
	return 0;
}

bool cmp(student a, student b) {
	return a.grade[now] > b.grade[now];
}
