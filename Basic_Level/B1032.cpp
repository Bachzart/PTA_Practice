#include <stdio.h>
#define MAXN 100005

int main(int argc, char const *argv[]) {
	int i, Num, Max = 0, N, School_Num[MAXN] = {0}, temp;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &Num, &temp);
		School_Num[Num] += temp;
	}
	for(i = 0; i < MAXN; i++) {
		if(Max < School_Num[i]) {
			Num = i;
			Max = School_Num[i];
		}
	}
	printf("%d %d\n", Num, Max);
	return 0;
} 
