#include <stdio.h>

struct examinee_info{
	char number[17];
	int test_seat;
	int exam_seat;
} Examinee_Info[1005];

int main(int argc, char const *argv[]) {
	int N, M, i, temp;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%s %d %d", Examinee_Info[i].number, &Examinee_Info[i].test_seat, &Examinee_Info[i].exam_seat);
	}
	scanf("%d", &M);
	while(M--) {
		scanf("%d", &temp);
		for(i = 0; i < N; i++) {
			if(temp == Examinee_Info[i].test_seat) {
				printf("%s %d\n", Examinee_Info[i].number, Examinee_Info[i].exam_seat);
			}
		}
	}
	return 0;
}
