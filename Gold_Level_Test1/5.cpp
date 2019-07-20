#include <cstdio>

struct student {
	int gender;
	char name[10];
	int flag;
} stu[55];

int main(int argc, char const *argv[]) {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d %s", &stu[i].gender, stu[i].name);
	}
	for(int i = 0; i < N / 2; i++) {
		if(stu[i].flag != 1) {
			printf("%s ", stu[i].name);
			stu[i].flag = 1;
		}
		if(stu[i].gender == 0) {
			for(int j = N - 1; j >=  N / 2; j--) {
				if(stu[j].gender == 1 && stu[j].flag != 1) {
					printf("%s\n", stu[j].name);
					stu[j].flag = 1;
					break;
				}
			}
		} else {
			for(int j = N - 1; j >= N / 2; j--) {
				if(stu[j].gender == 0 && stu[j].flag != 1) {
					printf("%s\n", stu[j].name);
					stu[j].flag = 1;
					break;
				}
			}
		}
	}
	return 0;
}
