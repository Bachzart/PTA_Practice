#include <cstdio>
#include <cctype>
#include <cstring>
int times[40] = {0};
int main() {
	int n;
	scanf("%d", &n);
	char num[6];
	while(n--) {
		scanf("%s", num);
		int tmp = 0, digit = 0, len = strlen(num);
		for(int i = len - 1; i >= 0; i--) {
			if(isdigit(num[i])) tmp += num[i] - '0';	
		}
		times[tmp]++;
	}
	int cnt = 0;
	for(int i = 0; i < 40; i++) {
		if(times[i] > 0) cnt++;
	}
	printf("%d\n", cnt);
	bool flag = true;
	for(int i = 0; i < 40; i++) {
		if(times[i] > 0) {
			if(flag) {
				printf("%d", i);
				flag = false;
			} else printf(" %d", i);
		}
	}
	return 0;
} 

/*
in:
10
123 899 51 998 27 33 36 12 0 0
out:
5
0 3 6 9 26

*/