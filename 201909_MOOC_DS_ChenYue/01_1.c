#include <stdio.h>
#define maxk 100005
int array[maxk] = {0};
int max(int a, int b, int c);
int divide(int array[], int left, int right);
int f1(int array[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for(i = 0; i < N; i++) {
		for(j = i; j < N; j++) {
			ThisSum = 0;
			for(k = i; k <= j; k++) {
				ThisSum += array[k];
			}
			if(ThisSum > MaxSum) MaxSum = ThisSum;
		}
	} 
	return MaxSum;
}
int f2(int array[], int N) {
	int ThisSum, MaxSum = 0;
	int i, j;
	for(i = 0; i < N; i++) {
		ThisSum = 0;
		for(j = i; j < N; j++) {
			ThisSum += array[j];
			if(ThisSum > MaxSum) MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
int f3(int array[], int N) {
	return divide(array, 0, N - 1);
}
int f4(int array[], int N) {
	int ThisSum = 0, MaxSum = 0;
	int i;
	for(i = 0; i < N; i++) {
		ThisSum += array[i];
		if(ThisSum > MaxSum) MaxSum = ThisSum;
		else if(ThisSum < 0) ThisSum = 0;
	}
	return MaxSum;
}
int main() {
	int k, i;
	scanf("%d", &k);
	for(i = 0; i < k ; i++) {
		scanf("%d", &array[i]);
	}
//	printf("%d", f1(array, k));
//	printf("%d", f2(array, k));
//	printf("%d", f3(array, k));
	printf("%d", f4(array, k));
	return 0;
} 

int divide(int array[], int left, int right) {
	int MaxleftSum, MaxrightSum;
	int MaxleftBorderSum, MaxrightBorderSum;
	int leftBorderSum, rightBorderSum;
	int center, i;
	if(left == right) {
		if(array[left] > 0) return array[left];
		else return 0;
	}
	center = (left + right) / 2;
	MaxleftSum = divide(array, left, center);
	MaxrightSum = divide(array, center + 1, right);
	MaxleftBorderSum = 0, leftBorderSum = 0;
	for(i = center; i >= left; i--) {
		leftBorderSum += array[i];
		if(leftBorderSum > MaxleftBorderSum) {
			MaxleftBorderSum = leftBorderSum;
		}
	}
	MaxrightBorderSum = 0, rightBorderSum = 0;
	for(i = center + 1; i <= right; i++) {
		rightBorderSum += array[i];
		if(rightBorderSum > MaxrightBorderSum) {
			MaxrightBorderSum = rightBorderSum;
		}
	} 
	return max(MaxleftSum, MaxrightSum, MaxleftBorderSum + MaxrightBorderSum);
}

int max(int a, int b, int c) {
	return a > b ? a > c ? a : c : b > c ? b : c; 
}
