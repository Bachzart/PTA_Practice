#include <iostream>
using namespace std;

int main() {
	int pa, pb, a, b, c, ta, tb;
	ta = tb = 0;
	scanf("%d %d\n%d %d %d", &pa, &pb, &a, &b, &c);
	if(a) tb += 1;
	else ta += 1;
	if(b) tb += 1;
	else ta += 1;
	if(c) tb += 1;
	else ta += 1;
	if(ta == 3 || (pa > pb && ta >= 1)) printf("The winner is a: %d + %d\n", pa, ta);
	else printf("The winner is b: %d + %d\n", pb, tb);
	return 0;
}
