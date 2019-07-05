#include <cstdio>
const int MAXN = 100 + 5;

char NumberTable[11][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
};

int main(int argc, char const *argv[]) {
	char num[MAXN];
	int sum = 0;
	scanf("%s", num);
	char *p = num;
	while(*p != '\0') {
		sum += *p++ - '0';
	}
	int temp = sum, mask = 1;
	while(temp > 9) {
		temp /= 10;
		mask *= 10;
	}
	while(mask) {
		printf("%s", NumberTable[sum / mask]);
		if(mask > 9) {
			putchar(' ');
		}
		sum %= mask;
		mask /= 10;
	}
	putchar('\n');
	return 0;
}
