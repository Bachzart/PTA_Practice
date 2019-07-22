#include <cstdio>
#include <algorithm>
using namespace std;

void toArray(int n, int *array) {
	int temp = n, i = 0, ret = 0;
	while(temp) {
		array[i++] = temp % 10;
		temp /= 10;
	}
}

int main(int argc, char const *argv[]) {
	int n, min, max, diff;
	scanf("%d", &n);
	while(1) {
		int num[5] = {0};
		toArray(n, num);
		sort(num, num + 4); 
		max = num[0] + num[1] * 10 + num[2] * 100 + num[3] * 1000;
		min = num[3] + num[2] * 10 + num[1] * 100 + num[0] * 1000;
		diff = max - min;
		if(!diff) {
			printf("%04d - %04d = 0000\n", max, min);
			break;
		} else {
			printf("%04d - %04d = %04d\n", max, min, diff);
			if(diff == 6174) break;
			n = diff;
		}
	}
	
	return 0;
} 
