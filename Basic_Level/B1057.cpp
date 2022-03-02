#include <cstdio>
const int maxn = 100000 + 5;
char str[maxn];
long long sum = 0;

int main() {
	fgets(str, maxn, stdin);
	for(int i = 0; str[i] != '\0'; i++) {
		if('A' <= str[i] && str[i] <= 'Z') sum = sum + str[i] - 'A' + 1;
		if('a' <= str[i] && str[i] <= 'z') sum = sum + str[i] - 'a' + 1;
	}
	long long tmp = sum;
	int one = 0, zero = 0;
	while(tmp != 0){
		int i = tmp % 2;
		if(i) one++;
		else zero++;
		tmp /= 2; 
	}
	printf("%d %d", zero, one);
	return 0;
}