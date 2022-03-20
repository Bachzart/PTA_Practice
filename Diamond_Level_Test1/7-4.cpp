#include <cstdio>
#include <cstring>
const int maxn = 55;
char num[maxn];

int main() {
	scanf("%s", num);
	bool negative = false;
	if(num[0] == '-') negative = true;
	int len = strlen(num), two = 0;
	for(int i = 0; i < len; i++) {
		if(num[i] == '2') two++;
	}
	double res = 0.0;
	if(negative) {
		res = two * 1.0 / (len - 1) * 1.5;
	} else res = two * 1.0 / len;
	if((num[len - 1] - '0') % 2 == 0) res = res * 2;
	printf("%.2lf%%", res * 100);
	return 0;
}
