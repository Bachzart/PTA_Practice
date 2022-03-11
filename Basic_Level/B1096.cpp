#include <cstdio>
const int maxn = 10000 + 5;
int factor[maxn] = {1};
 
int main() {
	int k, n;
	scanf("%d", &k);
	while(k--) {
		int cnt = 1;
		scanf("%d", &n);
		for(int i = 2; i <= n; i++) {
			if(n % i == 0) factor[cnt++] = i;
		}
		if(cnt < 4) printf("No\n");
		else {
			bool flag = false;
			for(int i = 0; i < cnt - 3; i++) {
				for(int j = i + 1; j < cnt - 2; j++) {
					for(int k = j + 1; k < cnt - 1; k++) {
						for(int l = k + 1; l < cnt; l++) {
							if((factor[i] + factor[j] + factor[k] + factor[l]) % n == 0) {
								printf("Yes\n");
								flag = true;
								goto out;
							}
						}
					}
				}
			}
			out: 
				if(!flag) printf("No\n");
		}
	}
	return 0;
}
