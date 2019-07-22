#include <cstdio>

int main(int argc, char const *argv[]) {
	int n, array[105] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	int total = 0, last = 0;
	for(int i = 0; i < n; i++) {
		if(array[i] == last) {
			total += 5;
		} else if(array[i] > last) {
			total += ((array[i] - last) * 6 + 5);
		} else {
			total += ((last - array[i]) * 4 + 5);
		}
		last = array[i];
	}
	printf("%d\n", total);
	return 0;
}
