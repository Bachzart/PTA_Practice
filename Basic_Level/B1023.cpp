#include <cstdio>

int main(int argc, char const *argv[]) {
	int count[10] = {0};
	for(int i = 0; i < 10; i++) {
		scanf("%d", &count[i]);
	}
	//print the first number
	for(int i = 1; i < 10; i++) {
		if(count[i]) {
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	//print the rest of numbers
	for(int i = 0; i < 10; i++) {
		while(count[i]) {
			printf("%d", i);
			count[i]--;
		}
	}
	return 0;
}
