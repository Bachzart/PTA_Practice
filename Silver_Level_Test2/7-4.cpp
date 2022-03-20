#include <cstdio>

int main() {
	int pa, pb, a, b, c, ta = 0;
	scanf("%d %d\n%d %d %d", &pa, &pb, &a, &b, &c);
	if(!a) ta += 1;
	if(!b) ta += 1;
	if(!c) ta += 1;
	if(ta == 3 || (pa > pb && ta >= 1)) printf("The winner is a: %d + %d\n", pa, ta);
	else printf("The winner is b: %d + %d\n", pb, 3 - ta);
	return 0;
}
