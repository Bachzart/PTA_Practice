#include <cstdio>
#include <cctype>
const int maxn = 1000 + 5;
int num[maxn] = {0}, temp[maxn] = {0};
bool ispalindromic(int *a, int count) {
	if(count == 1) return true;
	for(int i = 0; i < count / 2; i++) {
		if(a[i] != a[count - i - 1]) return false;
	}
	return true;
}
void shownum(int *a, int count) {
	for(int i = count - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
}
void arr_reverse(int *a, int *b, int count) {
	for(int i = 0; i < count; i++) {
		a[i] = b[count - i - 1];
	}
}
int main() {
	char c;
	int count = 0;
	while((c = getchar()) != '\n') {
		temp[count++] = c - '0';
	}
	arr_reverse(num, temp, count);
	int times = 0;
	while(times++ < 10) {
		if(ispalindromic(num, count)) {
			shownum(num, count);
			printf(" is a palindromic number.\n");
			break;
		} else {
			shownum(num, count);
			printf(" + ");
			shownum(temp, count);
			int carry = 0, tmp;
			for(int i = 0; i < count; i++) {
				tmp = num[i];
				num[i] = (tmp + temp[i] + carry) % 10;
				carry = (tmp + temp[i] + carry) / 10;
			}
			if(carry) num[count++] = carry;
			printf(" = ");
			shownum(num, count);
			printf("\n");
			arr_reverse(temp, num, count);
		}
	}
	if(times >= 10) printf("Not found in 10 iterations.\n");
	return 0;
}
