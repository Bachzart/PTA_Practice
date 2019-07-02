#include <stdio.h>
#include <stdbool.h>

bool Judge_Automorphic(int test_number, int original_number);


int main(int argc, char const *argv[]) {
	int M, N, K, flag, each_item;
	scanf("%d", &M);
	while(M--) {
		scanf("%d", &K);
		flag = false;
		for(N = 1; N < 10; N++) {
			each_item = N * K * K;
			if( Judge_Automorphic(each_item, K) ) {
				flag = true;
				break;
			}
		}
		if(flag) {
			printf("%d %d\n", N, each_item);
		} else {
			puts("No");
		}
	}
	return 0;
}

bool Judge_Automorphic(int test_number, int original_number) {
	bool flag = false;
	int mask = 1, temp;
	temp = original_number;
	while(temp) {
		temp /= 10;
		mask *= 10;
	}
	temp = test_number;
	temp %= mask;
	if(temp == original_number) {
		flag = true;
	}
	return flag;
}
