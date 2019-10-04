#include <stdio.h>
#include <stdbool.h>
#define maxk 100005
int array[maxk] = {0};
int main() {
	int k, i;
	scanf("%d", &k);
	bool flag = false;
	for(i = 1; i <= k; i++) {
		scanf("%d", array + i);
		if(array[i] >= 0) flag = true;
	}
	if(!flag) {
		printf("0 %d %d\n", array[1], array[k]);
	} else {
		int left = 1, right = k, temp_left = 1;
		int ThisSum = 0, MaxSum = -1;
		for(i = 1; i <= k; i++) {
			ThisSum += array[i];
			if(ThisSum > MaxSum) {
				MaxSum = ThisSum;
				left = temp_left;
				right = i;
			} else if(ThisSum < 0) {
				ThisSum = 0;
				temp_left = i + 1;
			}
		}
		printf("%d %d %d\n", MaxSum, array[left], array[right]);
	}
	return 0;
}
