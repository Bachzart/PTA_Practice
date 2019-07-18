#include <cstdio>
const int MAXN = 200000 + 10;
int seq[MAXN];
int main(int argc, char const *argv[]) {
	int n1, n2, temp, count = 0;
	scanf("%d", &n1);
	for(int i = 1; i <= n1; i++) {
		scanf("%d", &seq[i]);
	}
	seq[n1 + 1] = 0x7fffffff;
	scanf("%d", &n2);
	int median = (n1 + n2 + 1) / 2, i = 1;
	for(int j = 1; j <= n2; j++) {
		scanf("%d", &temp);
		while(seq[i] < temp) {
			count++;
			if(count == median) printf("%d", seq[i]);
			i++;
		}
		count++;
		if(count == median) printf("%d", temp);
	}
	while(i <= n1) {
		count++;
		if(count == median) printf("%d", seq[i]);
		i++;
	}
	return 0;
}
