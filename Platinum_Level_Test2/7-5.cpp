#include <cstdio>
const int maxn = 1000 + 10;
struct book {
	int start_hour, start_minute;
	char status;
} bo[maxn];
void Init() {
	for(int i = 0; i < maxn; i++) {
		bo[i].status = 'E';
		bo[i].start_minute = bo[i].start_hour = 0;
	}
}
int main() {
	Init();
	int n, book_num, hour, minute, cnt = 0;
	double times = 0.0;
	char status;
	scanf("%d", &n);
	while(n) {
		scanf("%d %c %d:%d", &book_num, &status, &hour, &minute);
		if(book_num == 0) {
			if(cnt) printf("%d %.0lf\n", cnt, times / cnt);
			else printf("0 0\n");
			n--;
			cnt = 0, times = 0.0;
			Init();
			continue;
		} else {
			if(status == 'S') {
				bo[book_num].status = 'S';
				bo[book_num].start_hour = hour;
				bo[book_num].start_minute = minute;
			} else {
				if(bo[book_num].status == 'S') {
					cnt++;
					times = times + 60 * (hour - bo[book_num].start_hour) + minute - bo[book_num].start_minute;
					bo[book_num].status = 'E';
				} else continue;
			}
		}
	}
	return 0;
}
