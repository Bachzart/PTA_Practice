#include <cstdio>

int main() {
	int n, wifi_password[105] = {0}, count = 0;
	scanf("%d%*c", &n);
	char opt, taf;
	for(int i = 0; i < 4 * n; i++) {
		scanf("%c-%c%*c", &opt, &taf);
		if(taf == 'T') wifi_password[count++] = opt - 'A' + 1;
	}
	for(int i = 0; i < count; i++) {
		printf("%d", wifi_password[i]);
	}
	return 0;
}
