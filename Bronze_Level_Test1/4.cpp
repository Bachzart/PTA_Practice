#include <cstdio>

int main(int argc, char const *argv[]) {
	int H;
	double weight = 0;
	scanf("%d", &H);
	weight = (H - 100) * 0.9 * 2;
	printf("%.1lf", weight);
	return 0;
}
