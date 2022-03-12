#include <cstdio>
char str[10005];
int times[6] = {0};
int main() {
	scanf("%s", str);
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] == 'S') times[0]++;
		else if(str[i] == 't') times[1]++;
		else if(str[i] == 'r') times[2]++;
		else if(str[i] == 'i') times[3]++;
		else if(str[i] == 'n') times[4]++;
		else if(str[i] == 'g') times[5]++;
	} 
	while(times[0] || times[1] || times[2] || times[3] || times[4] || times[5]) {
		if(times[0]) {
			printf("S");
			times[0]--;
		}
		if(times[1]) {
			printf("t");
			times[1]--;
		}
		if(times[2]) {
			printf("r");
			times[2]--;
		}
		if(times[3]) {
			printf("i");
			times[3]--;
		}
		if(times[4]) {
			printf("n");
			times[4]--;
		}
		if(times[5]) {
			printf("g");
			times[5]--;
		}
	}
	return 0;
}
