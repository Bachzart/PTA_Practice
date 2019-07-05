#include <cstdio>
const int MAXN = 1000 + 5;
struct info {
	char name[12], password[12];
	int flag;
} Info[MAXN];

int main(int argc, char const *argv[]) {
	int N, count = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s %s", Info[i].name, Info[i].password);
		char *p = Info[i].password;
		while(*p != '\0') {
			if(*p == '1') {
				*p = '@';
				Info[i].flag = 5;
			} else if(*p == '0') {
				*p = '%';
				Info[i].flag = 5;
			} else if(*p == 'l') {
				*p = 'L';
				Info[i].flag = 5;
			} else if(*p == 'O') {
				*p = 'o';
				Info[i].flag = 5;
			}
			p++;
		}
		if(Info[i].flag != 5) {
			count++;
		}
	}
	if(count == N) {
		if(count == 1) printf("There is %d account and no account is modified\n", count);
		else printf("There are %d accounts and no account is modified", count);
	} else {
		printf("%d\n", N - count);
		for(int i = 0; i < N; i++) {
			if(Info[i].flag == 5) {
				printf("%s %s\n", Info[i].name, Info[i].password);
			}
		}
	}
	return 0;
}
