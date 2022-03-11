#include <cstdio>

int main() {
	int n, tmp, up_low = 1005, down_high = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if(up_low > tmp) up_low = tmp;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if(down_high < tmp) down_high = tmp;
	}
	tmp = up_low - down_high;
	if(tmp > 0) printf("Yes %d", tmp);
	else printf("No %d", 1 - tmp);
	return 0;
}

/*
in:
11
7 6 5 5 6 5 4 5 5 4 4
3 2 2 2 2 3 3 2 1 2 3
out:
Yes 1

in:
11
7 6 5 5 6 5 4 5 5 4 4
3 2 2 2 3 4 3 2 1 2 3
out:
No 1

in:
11
7 6 5 5 6 5 4 5 5 4 4
3 2 2 2 3 5 3 2 1 2 3
out:
No 2

in:
11
7 6 5 5 6 5 4 5 5 4 4
3 2 2 2 3 6 3 2 1 2 3
out:
No 3
*/
