#include <stdio.h>
#define MAXN 100

int main(int argc, char const *argv[]) {
	int i, N, A_Count, A_Voice, A_Write, B_Count, B_Voice, B_Write, Sum_Voice;
	A_Count = B_Count = Sum_Voice = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d %d %d %d", &A_Voice, &A_Write, &B_Voice, &B_Write);
		Sum_Voice = A_Voice + B_Voice;
		if(A_Write == Sum_Voice && B_Write != Sum_Voice) {
			B_Count++;
		}
		if(B_Write == Sum_Voice && A_Write != Sum_Voice) {
			A_Count++;
		}
	}
	printf("%d %d\n", A_Count, B_Count);
	return 0;
}
