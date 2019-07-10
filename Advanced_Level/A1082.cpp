#include <cstdio>
#include <cstring>

char NumberTable[10][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", };
char Digit[5][10] = { "Shi", "Bai", "Qian", "Wan", "Yi", };

int main(int argc, char const *argv[]) {
	char Num[15];
	scanf("%s", Num);
	int len = strlen(Num), left = 0, right = len - 1;
	if(Num[0] == '-') {
		printf("Fu");
		left++;
	}
	while(left + 4 <= right) {
		right -= 4;
	}
	while(left < len) {
		bool flag = false, isPrint = false;
		while(left <= right) {
			if(left > 0 && Num[left] == '0') {
				flag = true;
			} else {
				if(flag == true) {
					printf(" ling");
					flag = false;
				}
				if(left > 0) printf(" ");
				printf("%s", NumberTable[Num[left] - '0']);
				isPrint = true;
				if(left != right) {
					printf(" %s", Digit[right - left - 1]);
				}
			}
			left++;
		}
		if(isPrint == true && right != len - 1) {
			printf(" %s", Digit[(len - 1 - right) / 4 + 2]);
		}
		right += 4;
	}
	return 0;
}
