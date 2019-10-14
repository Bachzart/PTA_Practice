/* method 1: count times directly */ 
#include <stdio.h>
int main() {
	int i, n, array[1005] = {0}, x, cnt = 1;
	scanf("%d %d", &n, &array[0]);
	x = array[0];
	for(i = 1; i < n; ++i) {
		scanf("%d", &array[i]);
		if(cnt == 0) {
			x = array[i];
			cnt = 1;
		} else if(x != array[i]) --cnt;
		else ++cnt;
	}
	cnt = 0;
	for(i = 0; i < n; ++i) {
		if(x == array[i]) ++cnt;
	}
	printf("%d %d", x, cnt);
	return 0;
}

/* method 2: use double loop 

#include <stdio.h>

int main(int argc, char const *argv[]) {
	int i, j, N, array[1005], temp = 0, count, max = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &array[i]);
	}
	for(i = 0; i < N; i++) {
		count = 0;
		for(j = 0; j < N; j++) {
			if(array[i] == array[j]) {
				count++;
			}
		}
		if(count > max) {
			max = count;
			temp = array[i];
		}
	}
	printf("%d %d\n", temp, max);
    return 0;
} 

*/
