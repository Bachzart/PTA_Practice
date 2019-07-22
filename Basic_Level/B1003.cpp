#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	while(n--) {
		char str[105];
		scanf("%s", str);
		int len = strlen(str);
		int num_p = 0, num_t = 0, other = 0;
		int pos_p = -1, pos_t = -1;
		for(int i = 0; i < len; i++) {
			if(str[i] == 'P') {
				num_p++;
				pos_p = i;
			} else if(str[i] == 'T') {
				num_t++;
				pos_t = i;
			} else if(str[i] != 'A') other++;
		}
		if(num_p != 1 || num_t != 1 || other != 0 || pos_t - pos_p <= 1) {
			printf("NO\n");
			continue;
		}
		int x = pos_p, y = pos_t - pos_p - 1, z = len - pos_t - 1;
		if(z - x * (y - 1) == x) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
