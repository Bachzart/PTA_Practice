#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student {
	char id[15];
	int score;
	int location_number;
	int local_rank;
} stu[30010];

bool cmp(student a, student b);

int main(int argc, char const *argv[]) {
	int N, K, num = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &K);
		for(int j = 0; j < K; j++) {
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;
			num++;
		}
		sort(stu + num - K, stu + num, cmp);
		stu[num - K].local_rank = 1;
		//get local rank
		for(int j = num - K + 1; j < num; j++) {
			if(stu[j].score == stu[j - 1].score) {
				stu[j].local_rank = stu[j - 1].local_rank;
			} else {
				stu[j].local_rank = j + 1 - (num - K);
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	//get final rank
	int r = 1;
	for(int i = 0; i < num; i++) {
		if(i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}

bool cmp(student a, student b) {
	if(a.score != b.score) return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}
