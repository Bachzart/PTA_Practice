#include <cstdio>

int main(int argc, char const *argv[]) {
	int mm, dd, yy;
	scanf("%d-%d-%d", &mm, &dd, &yy);
	printf("%d-%02d-%02d", yy, mm, dd);
	return 0;
}
