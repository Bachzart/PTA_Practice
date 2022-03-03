#include <stdio.h>

int main(int argc, char const *argv[]) { 
	int N, M;
	scanf("%d %d", &N, &M);
	int i, j, Scores[M], Right[M], Temp, Sum;
	for(i = 0; i < M; i++) {
		scanf("%d", &Scores[i]);
	}
	for(i = 0; i < M; i++) {
		scanf("%d", &Right[i]);
	}
	while(N--) {
		Sum = 0;
		for(i = 0; i < M; i++) {
			scanf("%d", &Temp);
			if(Temp == Right[i]) Sum += Scores[i];
		}
		printf("%d\n", Sum);
	}
	return 0;
} 
