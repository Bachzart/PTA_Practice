#include <stdio.h>

/*
In the count array:
0 -> victory
1 -> dogfall
2 -> defeat

In the gesture array:
0 -> Bu
1 -> Chuizi
2 -> Jiandao
(Laugh~)
*/
char Gesture[4] = {'B', 'C', 'J'};
int MaxOfArray(int *array);

int main(int argc, char const *argv[]) {
	int temp, N, A_Count[3] = {0}, A_Gesture[3] = {0}, B_Gesture[3] = {0};
	char A, B;
	scanf("%d%*c", &N);
	while(N--) {
		scanf("%c %c%*c", &A, &B);
		if(A == B) {
			A_Count[1]++;	//dogfall
		} else {
			if(A == 'C') {
				if(B == 'J') {
					A_Count[0]++;	//A win
					A_Gesture[1]++;	//Chuizi
				} else {
					A_Count[2]++;	//B win
					B_Gesture[0]++;	//Bu
				}
			} else if(A == 'B') {
				if(B == 'C') {
					A_Count[0]++;	//A win
					A_Gesture[0]++;	//Bu
				} else {
					A_Count[2]++;	//B win
					B_Gesture[2]++;	//Jiandao
				}
			} else if(A == 'J') {
				if(B == 'B') {
					A_Count[0]++;	//A win
					A_Gesture[2]++;	//Jiandao
				} else {
					A_Count[2]++;	//B win
					B_Gesture[1]++;	//Chuizi
				}
			}
		}
	}
	printf("%d %d %d\n", A_Count[0], A_Count[1], A_Count[2]);	//For A
	printf("%d %d %d\n", A_Count[2], A_Count[1], A_Count[0]);	//For B
	printf("%c", Gesture[MaxOfArray(A_Gesture)]);
	printf(" %c\n", Gesture[MaxOfArray(B_Gesture)]);
	return 0;
}

int MaxOfArray(int *array) {
	int i, max = -1, index = -1;
	for(i = 0; i < 3; i++) {
		if(array[i] > max) {
			max = array[i];
			index = i;
		}
	}
	return index;
}
