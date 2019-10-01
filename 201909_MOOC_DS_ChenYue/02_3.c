#include <stdio.h>
#define maxn 100005
int addr[maxn], address[maxn], data[maxn], next[maxn];
void reverse(int A[], int left, int right) {
	for(; left < right; left++, right--) {
		int temp = A[left];
		A[left] = A[right];
		A[right] = temp;
	}
}
int main() {
	int src, n, k, m;
	scanf("%d %d %d", &src, &n, &k);
	m = n;
	int tmp_add, tmp_data, tmp_next;
	while(m--) {
		scanf("%d %d %d", &tmp_add, &tmp_data, &tmp_next);
		address[tmp_add] = tmp_add;
		next[tmp_add] = tmp_next;
		data[tmp_add] = tmp_data;
	}
	int len = 1, i, j, tmp = src;
	addr[0] = src;
	while(src != -1) {
		addr[len++] = next[src];
		src = next[src];
	}
	for(i = 0, j = k; j <= len - 1; i = j, j += k) {
		reverse(addr, i, j - 1);
	}
	for(i = 0; i < len - 2; i++) {
		src = addr[i];
		printf("%05d %d %05d\n", src, data[src], addr[i + 1]);
	}
	printf("%05d %d -1\n", address[addr[i]], data[addr[i]]);
	return 0;
}

/*
some samples:
in:
00100 6 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
out:
68237 6 99999
99999 5 00000
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 -1

in:
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
out:
33218 3 12309
12309 2 00100
00100 1 68237
68237 6 99999
99999 5 00000
00000 4 -1

in:
00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
out:
00100 1 12309
12309 2 33218
33218 3 00000
00000 4 99999
99999 5 68237
68237 6 -1

in:
00100 5 3
00000 4 99999
00100 1 12309
33218 3 00000
99999 5 -1
12309 2 33218
out:
33218 3 12309
12309 2 00100
00100 1 00000
00000 4 99999
99999 5 -1

in:
00100 9 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
33333 7 22222
44444 8 11111
03333 9 02222
out:
12309 2 00100
00100 1 00000
00000 4 33218
33218 3 68237
68237 6 99999
99999 5 -1

in:
00100 3 2
00100 1 -1
11111 2 22222
33333 3 44444
out:
00100 1 -1
*/
