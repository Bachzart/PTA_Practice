/*
method 1: use math, print it straightly according to the conditions.
*/
#include <stdio.h>
#define MAXN 105

int main(int argc, char const *argv[]) {
	int i, j, k, N, M, Array[MAXN];
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) {
		scanf("%d", &Array[i]);
	}
	j = N - M % N;
	k = j;
	for(; j < N; j++) {
		printf("%d ", Array[j]);
	}
	for(i = 0; i < k - 1; i++) {
		printf("%d ", Array[i]);
	}
	printf("%d\n", Array[i]);
	return 0;
}

/*
method 2: use queue

#include <stdio.h>
#define MAXN 105

int main(int argc, char const *argv[]) {
	int i, N, M, temp, Queue[MAXN], front, rear;
	scanf("%d %d", &N, &M);
	front = rear = -1;
	i = N;
	while(i--) {
		scanf("%d", &temp);
		Queue[++rear] = temp;	//Enqueue
	}
	i = N - M % N;
	while(i--) {
		Queue[++rear] = Queue[++front];	//First Dequeue, then Enqueue
	}
	while(front < rear - 1) {
		printf("%d ", Queue[++front]);
	}
	printf("%d\n", Queue[++front]);
	return 0;
}
*/

/*
method 3: use shift algorithm

#include <stdio.h>
#define MAXN 105

void reverse(int *array, int start, int end);

int main(int argc, char const *argv[]) {
	int N, M, i, Array[MAXN];
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) {
		scanf("%d", &Array[i]);
	}
	M %= N;
	reverse(Array, 0, N - M - 1);
	reverse(Array, N - M, N - 1);
	reverse(Array, 0, N - 1);
	printf("%d", Array[0]);
	for(i = 1; i < N; i++) {
		printf(" %d", Array[i]);
	}
	putchar('\n');
	return 0;
}

void reverse(int *array, int start, int end) {
	int i, temp;
	for(i = start; i <= (start + end) / 2; i++) {
		temp = array[i];
		array[i] = array[start + end - i];
		array[start + end - i] = temp;
	}
}

*/
