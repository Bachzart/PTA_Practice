#include <stdio.h>

int main(int argc, char const *argv[]) {
	int Array[6] = {0}, i, N, sign = 1, temp, sum_A4 = 0, flag = 0;
	double average_A4 = 0.0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &temp);
		// calculate A1
		if(temp % 5 == 0 && temp % 2 == 0) {
			Array[1] += temp;
		}
		// calculate A2, attention: A2 may is 0
		if(temp % 5 == 1) {
			flag = 1;
			Array[2] += (temp * sign);
			sign = - sign;
		}
		// calculate A3
		if(temp % 5 == 2) {
			Array[3]++;
		}
		// calculate A4
		if(temp % 5 == 3) {
			Array[4]++;
			sum_A4 += temp;
		}
		// calculate A5
		if(temp % 5 == 4) {
			if(temp > Array[5]) {
				Array[5] = temp;
			}
		}
	}
	average_A4 = 1.0 * sum_A4 / Array[4];
	//print
	if(Array[1]) {
		printf("%d ", Array[1]);
	} else {
		printf("N ");
	}
	if(flag) {
		printf("%d ", Array[2]);
	} else {
		printf("N ");
	}
	if(Array[3]) {
		printf("%d ", Array[3]);
	} else {
		printf("N ");
	}
	if(Array[4]) {
		printf("%.1lf ", average_A4);
	} else {
		printf("N ");
	}
	if(Array[5]) {
		printf("%d\n", Array[5]);
	} else {
		printf("N\n");
	}
	return 0;
}
