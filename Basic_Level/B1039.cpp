#include <cstdio>
#include <cstring>
const int MAXN = 1000 + 5;

void get_count(int *a, char *s);

int main(int argc, char const *argv[]) {
	char str1[MAXN], str2[MAXN];
	fgets(str1, MAXN, stdin);
	fgets(str2, MAXN, stdin);
	int count1[90] = {0}, count2[90] = {0};
	get_count(count1, str1);
	get_count(count2, str2);
	int temp, less = 0, len1 = strlen(str1), len2 = strlen(str2);
	bool enough = true;
	for(int i = 0; i < 90; i++) {
		temp = count2[i] - count1[i];
		if(temp > 0) {
			less += temp;
			enough = false;
		}
	}
	if(enough) {
		printf("Yes %d\n", len1 - len2);
	} else {
		printf("No %d\n", less);
	}
	return 0;
}

void get_count(int *a, char *s) {
	char *p = s;
	while(*p != '\0') {
		a[*p - '0']++;
		p++;
	}
}
